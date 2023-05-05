//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		This program contains the implementation of the ProductionWorker class that inherits from the Employee class.
//		The ProductionWorker class represents an employee who works in a production line and has a shift and hourly pay rate.
//		This script contains the implementation of the ProductionWorker class member functions as well as an overloaded
//		operator function for outputting ProductionWorker object's data to an output stream.

#include<string>
#include<iomanip>
#include"ProductionWorker.h"



// Parameterized constructor that initializes the ProductionWorker object with a name, employee number, hire date,
ProductionWorker::ProductionWorker(std::string name, std::string employeeNumber, Date hireDate, int shift, double hourlyPayRate)
	: Employee(name, employeeNumber, hireDate)// calls the constructor of the base class
{
   /* if (shift != 1 && shift != 2)
	{
		throw std::invalid_argument("Shift is invalid");
	}
	if (hourlyPayRate < 0.0)
	{
		throw std::invalid_argument("Hourly Pay Rate cannot be negative");
	}
	this->shift = shift;
	this->hourlyPayRate = hourlyPayRate;*/


	// validate shift and hourly pay rate values and set the corresponding data members.
	setShift(shift);
	setHourlyPayRate(hourlyPayRate);

}


// Accessor function for shift.
int ProductionWorker::getShift() const
{
	return shift;
}

// Accessor function for hourly pay rate.
double ProductionWorker::getHourlyPayRate() const
{
	return hourlyPayRate;
}

// Mutator function for shift.
void ProductionWorker::setShift(int shift)
{
	if (shift != 1 && shift != 2)// check if the shift is valid (1 for Day shift or 2 for Night shift).
	{
		throw std::invalid_argument("Shift is invalid");
	}
	this->shift = shift;
}

// Mutator function for hourly pay rate.
void ProductionWorker::setHourlyPayRate(double hourlyPayRate)
{
	if (hourlyPayRate < 0.0)// check if the hourly pay rate is valid (not negative).
	{
		throw std::invalid_argument("Hourly Pay Rate cannot be negative");
	}
	this->hourlyPayRate = hourlyPayRate;
}



// Overloaded output stream insertion operator to print ProductionWorker object's information.
std::ostream& operator<<(std::ostream& os, const ProductionWorker& worker)
{
	os << static_cast<const Employee&>(worker) << "\n" // call the base class's output stream insertion operator
		<< "Shift: " << worker.getShift() << "\n" // print the shift
		<< "Hourly pay rate: " << std::fixed << std::setprecision(2) << worker.getHourlyPayRate(); // print the hourly pay rate
	return os;
}