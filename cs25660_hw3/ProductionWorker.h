#pragma once
//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		This header file defines the ProductionWorker class, which is a derived class of the Employee class.
//		A ProductionWorker represents an employee who works in a production line and has a shift (day or night)
//		and an hourly pay rate. The class provides accessor and mutator functions for the shift and hourly pay
//		rate, as well as a constructor and an overloaded insertion operator.
//

#include "Employee.h"
#include<string>

class ProductionWorker : public Employee
{
private:
	int shift;// The shift the worker is assigned to (1 for day shift, 2 for night shift)
	double hourlyPayRate;// The hourly pay rate for the worker
public:
	// Constructors
	ProductionWorker(std::string name = "", std::string employeeNumber = "000-O", Date hireDate = { 0,0,0 }, int shift = 1, double hourlyPayRate = 0.0);
	
	// Accessor functions
	int getShift() const;// Get the shift of the worker
	double getHourlyPayRate() const;// Get the hourly pay rate of the worker

	// Mutator functions
	void setShift(int shift);// Set the shift of the worker
	void setHourlyPayRate(double hourlyPayRate);// Set the hourly pay rate of the worker

	// Overloaded operator functions
	friend std::ostream& operator<<(std::ostream& os, const ProductionWorker& worker);// Overloaded stream insertion operator to print out the production worker's information
};
