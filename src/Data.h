#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector <std::vector <double>> distances;
std::vector <std::vector <double>> drivingTimes;
bool importData();
bool importDistances();
bool importDrivingTimes();
int nLocations;