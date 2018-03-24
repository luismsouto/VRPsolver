#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Travel.h"
#include "Vehicle.h"

class Data
{
public:
	Data();
	~Data();
	bool prepareData();
	void setDistancesFilePath(std::string filePath);
	void setDrivingTimesFilePath(std::string filePath);
	int getNCustomers();
	bool defineNCustomers();
	bool uploadDistances();
	bool uploadDrivingTimes();
	
private:
	bool uploadTravel();
	bool uploadFleet();
	std::string distancesFilePath;
	std::string drivingTimesFilePath;
	int nCustomers;
	Travel travel;
	std::vector <Vehicle> fleet;
};