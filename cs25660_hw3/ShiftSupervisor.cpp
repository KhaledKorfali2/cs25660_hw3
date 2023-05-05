//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		The code defines the implementation of the ShiftSupervisor class, which is derived from the
//		Employee class. The ShiftSupervisor class has a name, employee number, hire date, annual salary,
//		and annual production bonus. The class provides accessor and mutator functions to get and set the
//		values of the data members. The operator<< function is overloaded to print out the ShiftSupervisor
//		object's data members.
//
#include<stdexcept>
#include<iomanip>
#include"ShiftSupervisor.h"



// Parameterized constructor to initialize data members
ShiftSupervisor::ShiftSupervisor(std::string name, std::string employeeNumber, Date hireDate, double annualSalary, double annualProductionBonus)
	: Employee(name, employeeNumber, hireDate)
{
	/*if (annualSalary < 0.0)
	{
		throw std::invalid_argument("Annual salary cannot be negative");
	}
	if (annualProductionBonus < 0.0)
	{
		throw std::invalid_argument("Annual production bonus cannot be negative");
	}
	this->annualSalary = annualSalary;
	this->annualProductionBonus = annualProductionBonus;*/

	// Validate inputs for annualSalary and annualProductionBonus before assigning values to data members
	// If any of the inputs are invalid, throw an exception with an error message
	setAnnualSalary(annualSalary);
	setAnnualProductionBonus(annualProductionBonus);
}

// Accessor function for annual salary.
double ShiftSupervisor::getAnnualSalary() const
{
	return annualSalary;
}

// Accessor function for annual production bonus.
double ShiftSupervisor::getAnnualProductionBonus() const
{
	return annualProductionBonus;
}

// Mutator function for annual salary.
void ShiftSupervisor::setAnnualSalary(double annualSalary)
{
	if (annualSalary < 0.0)// Check if annualSalary is negative, throw an exception with an error message if true
	{
		throw std::invalid_argument("Annual salary cannot be negative");
	}
	this->annualSalary = annualSalary;
}

// Mutator function for annual production bonus.
void ShiftSupervisor::setAnnualProductionBonus(double annualProductionBonus)
{
	// Check if annualProductionBonus is negative, throw an exception with an error message if true
	if (annualProductionBonus < 0.0)
	{
		throw std::invalid_argument("Annual production bonus cannot be negative");
	}
	this->annualProductionBonus = annualProductionBonus;
}

// Overloaded output stream insertion operator to print ShiftSupervisor object's information.
std::ostream& operator<<(std::ostream& os, const ShiftSupervisor& supervisor)
{
	os << static_cast<const Employee&>(supervisor) << "\n" // call the base class's output stream insertion operator
		<< "Salary: " << std::fixed << std::setprecision(2)<< supervisor.getAnnualSalary() << "\n" // print annual salary
		<< "Production Bonus: " << std::fixed << std::setprecision(2) << supervisor.getAnnualProductionBonus(); //print annual production bonus
	return os;
}

