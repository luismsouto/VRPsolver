#include "Data.h"

Data::Data()
{

}

Data::~Data()
{

}

bool Data::prepareData() {
	uploadTravel();
	uploadFleet();
	return true;
}

bool Data::uploadTravel() {
	travel.setDistancesFilePath("Distances.csv");
	travel.setDrivingTimesFilePath("Times.csv");

	if (!travel.defineNCustomers() || !travel.uploadDistances() || !travel.uploadDrivingTimes()) {
		return false;
	}
	return true;
}

bool Data::uploadFleet() {

}