#ifndef DATA_H_
#define DATA_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#pragma region Global Variables
	extern int nLocations;
	extern std::vector <std::vector <double>> distances;
	extern std::vector <std::vector <double>> drivingTimes;
	extern std::vector <std::vector <double>> aggregatedOrders;
#pragma endregion

bool importData();
bool importDistances();
bool importDrivingTimes();

#endif