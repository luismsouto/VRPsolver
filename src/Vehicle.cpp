#include "Vehicle.h"



Vehicle::Vehicle(int id, std::string name, int capacity, std::string type, double fixedCost, double variableCost,  bool mandatory)
{
	this->id = id;
	this->capacity = capacity;
	this->name = name;
	this->type = type;
	this->fixedCost = fixedCost;
	this->variableCost = variableCost;
	this->mandatory = mandatory;
}


Vehicle::~Vehicle()
{
}
