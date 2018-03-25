#pragma once
#include <string>
#include <vector>

class Travel
{
public:
	Travel();
	~Travel();

	std::vector <std::vector <double>> getAllDistances();
	std::vector <std::vector <double>> getAllDrivingTimes();
	void addDistances(std::vector <std::vector <double>> distancesMatrix);
	void addDrivingTimes(std::vector <std::vector <double>> drivingTimesMatrix);

private:

	std::vector <std::vector <double>> distances;
	std::vector <std::vector <double>> drivingTimes;

};

