#pragma once

#include "Employee.h"

#include<string>

class ProductionWorker : public Employee
{
private:
	int shift;
	double hourlyPayRate;
public:
	ProductionWorker(std::string name = "", std::string employeeNumber = "000-O", Date hireDate = { 0,0,0 }, int shift = 1, double hourlyPayRate = 0.0);
	int getShift() const;
	double getHourlyPayRate() const;

	void setShift(int shift);
	void setHourlyPayRate(double hourlyPayRate);

	friend std::ostream& operator<<(std::ostream& os, const ProductionWorker& worker);
};
