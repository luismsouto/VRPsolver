#include "Data.h"

using namespace std;

Data::Data()
{
	this->nCustomers = 0;
	this->nVehicles = 0;
}

Data::~Data()
{

}

bool Data::prepareData() {
	uploadTravel();
	//uploadFleet();
	return true;
}

void Data::setDistancesFilePath(string filePath)
{
	this->distancesFilePath = filePath;
}

void Data::setDrivingTimesFilePath(string filePath)
{
	this->drivingTimesFilePath = filePath;
}

void Data::setFleetFilePath(string filePath) {
	this->fleetFilePath = filePath;
}

int Data::getNCustomers()
{
	return this->nCustomers;
}

bool Data::defineNCustomers()
{
	string line;
	int k = 1;
	ifstream fileInput;
	fileInput.open(this->distancesFilePath);
	while (fileInput.good()) {
		while (getline(fileInput, line)) {
			this->nCustomers++;
		}
	}
	fileInput.close();
if (this->nCustomers > 0) {
	return true;
}
else {
	return false;
}
}

bool Data::uploadDistances()
{
	string line;
	double val;
	int k = 1;
	vector <double> lineVector;
	vector <vector <double>> matrix;
	ifstream fileInput;
	fileInput.open(this->distancesFilePath);
	while (fileInput.good()) {
		while (getline(fileInput, line, ',')) {
			istringstream stream(line);
			while (stream >> val) {
				lineVector.push_back(val);
				if (k < this->nCustomers) {
					++k;
				}
				else {
					matrix.push_back(lineVector);
					lineVector.clear();
					k = 1;
				}
			}
		}
	}

	fileInput.close();
	if ((matrix.size() == matrix[0].size()) && matrix.size() > 0) {
		travel.addDistances(matrix);
		return true;
	}
	else {
		return false;
	}
}

bool Data::uploadDrivingTimes()
{
	string line;
	double val;
	int k = 1;
	vector <double> lineVector;
	vector <vector <double>> matrix;
	ifstream fileInput;
	fileInput.open(this->drivingTimesFilePath);

	while (fileInput.good()) {
		while (getline(fileInput, line, ',')) {
			istringstream stream(line);
			while (stream >> val) {
				lineVector.push_back(val);
				if (k < this->nCustomers) {
					++k;
				}
				else {
					matrix.push_back(lineVector);
					lineVector.clear();
					k = 1;
				}
			}
		}
	}
	fileInput.close();
	if ((matrix.size() == matrix[0].size()) && matrix.size() > 0) {
		travel.addDrivingTimes(matrix);
		return true;
	}
	else {
		return false;
	}
}

bool Data::uploadTravel() {
	this->setDistancesFilePath("Distances.csv");
	this->setDrivingTimesFilePath("Times.csv");

	if (!this->defineNCustomers() || !this->uploadDistances() || !this->uploadDrivingTimes()) {
		return false;
	}
	return true;
}

bool Data::uploadFleet() {
	int id;
	string name;
	int capacity;
	string type;
	double fixedCost;
	double variableCost;
	bool mandatory;

	this->setFleetFilePath("Fleet.csv");
	string line;
	string val;
	int k = 1;
	ifstream fileInput;
	fileInput.open(this->fleetFilePath);
	if (this->defineNVehicles()) {
		while (fileInput.good()) {
			while (getline(fileInput, line)) {
				istringstream stream(line);
				while (stream >> val) {
					if (k == 1) {
						id = stoi(val);
					}
					else if (k == 2) {
						name = val;
					}
					else if (k == 3) {
						capacity = stoi(val);
					}
					else if (k == 4) {
						type = val;
					}
					else if (k == 5) {
						fixedCost = stod(val);
					}
					else if (k == 6) {
						variableCost = stod(val);
					}
					if (k < 7) {
						++k;
					}
					else {
						if (val == "1") {
							mandatory = true;
						}
						else if (val == "0") {
							mandatory = false;
						}
						fleet.push_back(Vehicle(id, name, capacity, type, fixedCost, variableCost, mandatory));
						k = 1;
					}
				}
			}
		}


		fileInput.close();
		if (this->nVehicles == fleet.size()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Data::defineNVehicles() {
	string line;
	int k = 1;
	
	ifstream fileInput;
	fileInput.open(this->fleetFilePath);
	while (fileInput.good()) {
		while (getline(fileInput, line)) {
			this->nVehicles++;
		}
	}
	fileInput.close();

	if (this->nVehicles > 0) {
		return true;
	}
	else {
		return false;
	}
}