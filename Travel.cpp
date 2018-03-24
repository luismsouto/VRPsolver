#include "Travel.h"


Travel::Travel()
{
}


Travel::~Travel()
{
}

bool Travel::uploadDistances() {
	this->nCustomers = 0;
	string line;
	double val;
	int k = 1;
	vector <double> lineVector;
	ifstream fileInput;
	fileInput.open("Distances.csv");
	while (fileInput.good()) {
		while (getline(fileInput, line)) {
			this->nCustomers++;
		}
	}
	fileInput.close();
	fileInput.open("Distances.csv");
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