#pragma once
class Vehicle
{
public:
	Vehicle();
	~Vehicle();

private:
	int id;
	int capacity;
	std::string name;
	std::string type;
	double fixedCost;
	double variableCost;
	bool mandatory;
};

