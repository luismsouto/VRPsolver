#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector <std::vector <double>> distances;
std::vector <std::vector <double>> drivingTimes;
std::vector <std::vector <double>> aggregatedOrders;
bool importData();
bool importDistances();
bool importDrivingTimes();
int nLocations;