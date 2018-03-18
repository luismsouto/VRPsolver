#include <iostream>
#include "Data.h"

using namespace std;


int main() {
	importData();
	system("pause");
	return 0;
}



#include "Data.h"
using namespace std;

bool importData() {
	nLocations = 0;
	if (!importDistances()) {
		return false;
	}
	if (!importDrivingTimes()) {
		return false;
	}

	return true;
}

bool importDistances() {
	string line;
	double val;
	int k = 1;
	vector <double> lineVector;
	ifstream fileInput;
	fileInput.open("Distances.csv");
	while (fileInput.good()) {
		while (getline(fileInput, line)) {
			nLocations++;
		}
	}
	fileInput.close();
	fileInput.open("Distances.csv");
	while (fileInput.good()) {
		while (getline(fileInput, line, ',')) {
			istringstream stream(line);
			while (stream >> val) {
				lineVector.push_back(val);
				if (k < nLocations) {
					++k;
				}
				else {
					distances.push_back(lineVector);
					lineVector.clear();
					k = 1;
				}
			}
		}
	}
	fileInput.close();
	if ((distances.size() == distances[0].size()) && distances.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool importDrivingTimes() {
	string line;
	double val;
	int k = 1;
	vector <double> lineVector;
	ifstream fileInput;
	fileInput.open("Times.csv");

	while (fileInput.good()) {
		while (getline(fileInput, line, ',')) {
			istringstream stream(line);
			while (stream >> val) {
				lineVector.push_back(val);
				if (k < nLocations) {
					++k;
				}
				else {
					drivingTimes.push_back(lineVector);
					lineVector.clear();
					k = 1;
				}
			}
		}
	}
	fileInput.close();
	if ((drivingTimes.size() == drivingTimes[0].size()) && drivingTimes.size() > 0) {
		return true;
	}
	else {
		return false;
	}
}
