#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Travel
{
public:
	Travel();
	~Travel();

	std::vector <std::vector <double>> getAllDistances();
	std::vector <std::vector <double>> getAllDrivingTimes();
	void setDistancesFilePath(std::string filePath);
	void setDrivingTimesFilePath(std::string filePath);
	bool defineNCustomers();
	bool uploadDistances();
	bool uploadDrivingTimes();
	int getNCustomers();

private:
	std::string distancesFilePath;
	std::string drivingTimesFilePath;
	int nCustomers;
	std::vector <std::vector <double>> distances;
	std::vector <std::vector <double>> drivingTimes;

};

