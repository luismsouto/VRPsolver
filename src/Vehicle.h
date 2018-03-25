#pragma once
#include <string>
class Vehicle
{
public:
	Vehicle(int id, 
			std::string name,
			int capacity,
			std::string type,
			double fixedCost,
			double variableCost,
			bool mandatory);
	~Vehicle();

private:
	int id;
	std::string name;
	int capacity;
	std::string type;
	double fixedCost;
	double variableCost;
	bool mandatory;
};

