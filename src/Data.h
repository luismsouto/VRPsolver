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
	
private:
	bool uploadTravel();
	bool uploadFleet();

	Travel travel;
	std::vector <Vehicle> fleet;
};