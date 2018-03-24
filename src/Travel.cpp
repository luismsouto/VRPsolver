#include "Travel.h"
using namespace std;

Travel::Travel()
{
}


Travel::~Travel()
{
}


vector <vector <double>> Travel::getAllDistances() {
	return this->distances;
}

vector <vector <double>> Travel::getAllDrivingTimes() {
	return this->drivingTimes;
}



void Travel::addDistances(vector <vector <double>> distancesMatrix)
{
	this->distances = distancesMatrix;
}

void Travel::addDrivingTimes(vector <vector <double>> drivingTimesMatrix)
{
	this->drivingTimes = drivingTimesMatrix;
}