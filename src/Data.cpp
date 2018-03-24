#include "Data.h"

using namespace std;

Data::Data()
{
	this->nCustomers = 0;
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

int Data::getNCustomers()
{
	return this->nCustomers;
}

bool Data::defineNCustomers()
{
	string line;
	int k = 1;
	vector <double> lineVector;
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
	return true;
}