#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector <vector <double>> distances;
bool importData();
bool importDistances();


int main() {
	importData();
	for (int i = 0; i < distances.size(); i++) {
		for (int j = 0; j < distances[i].size(); j++) {
			cout << distances[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}


bool importData() {
	string line;
	double val;
	int nLines = 0, k = 1;
	vector <double> lineVector;
	ifstream fileInput;
	fileInput.open("Distances.csv");
	while (fileInput.good()) {
		while (getline(fileInput, line)) {
			nLines++;
		}
	}
	fileInput.close();
	fileInput.open("Distances.csv");
	while (fileInput.good()) {
		while (getline(fileInput, line, ',')) {
			istringstream stream(line);
			while (stream >> val) {
				lineVector.push_back(val);
				if (k < nLines) {
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
	return true;
}