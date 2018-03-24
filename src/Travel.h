#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Travel
{
public:
	Travel();
	~Travel();

	vector <vector <double>> getAllDistances();
	bool uploadDistances();
	int getNCustomers();

private:
	vector <vector <double>> distances;
	vector <vector <double>> drivingTimes;
	int nCustomers;
};

