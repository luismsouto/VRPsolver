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
	void setFleetFilePath(std::string filePath);
	int getNCustomers();

private:
	bool uploadTravel();
	bool uploadFleet();
	std::string distancesFilePath;
	std::string drivingTimesFilePath;
	std::string fleetFilePath;
	int nCustomers;
	int nVehicles;
	Travel travel;
	std::vector <Vehicle> fleet;
	bool defineNCustomers();
	bool defineNVehicles();
	bool uploadDistances();
	bool uploadDrivingTimes();
};