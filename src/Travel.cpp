#include "Travel.h"
using namespace std;

Travel::Travel()
{
	this->nCustomers = 0;
}


Travel::~Travel()
{
}

void Travel::setDistancesFilePath(string filePath)
{
	this->distancesFilePath = filePath;
}

void Travel::setDrivingTimesFilePath(string filePath)
{
	this->drivingTimesFilePath = filePath;
}

#pragma region Upload distances/driving times
bool Travel::defineNCustomers()
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

bool Travel::uploadDistances()
{
	string line;
	double val;
	int k = 1;
	vector <double> lineVector;
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
					this->distances.push_back(lineVector);
					lineVector.clear();
					k = 1;
				}
			}
		}
	}

	fileInput.close();
	if ((this->distances.size() == this->distances[0].size()) && this->distances.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool Travel::uploadDrivingTimes()
{
	string line;
	double val;
	int k = 1;
	vector <double> lineVector;
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
					this->drivingTimes.push_back(lineVector);
					lineVector.clear();
					k = 1;
				}
			}
		}
	}
	fileInput.close();
	if ((this->drivingTimes.size() == this->drivingTimes[0].size()) && this->drivingTimes.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

#pragma endregion

vector <vector <double>> Travel::getAllDistances() {
	return this->distances;
}

vector <vector <double>> Travel::getAllDrivingTimes() {
	return this->drivingTimes;
}