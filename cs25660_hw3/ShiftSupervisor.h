#pragma once
//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		This header file defines the ShiftSupervisor class, which is derived from the Employee class.
//		The ShiftSupervisor class includes functions to access and modify the annual salary and annual
//		production bonus of the supervisor. 
//

#include<string>

#include"Employee.h"

// ShiftSupervisor class derived from Employee class
class ShiftSupervisor : public Employee {
private:
	double annualSalary; // the annual salary of the shift supervisor
	double annualProductionBonus;// the annual production bonus of the shift supervisor

public:
	// Constructor
	ShiftSupervisor(std::string name = "", std::string employeeNumber = "000-O", Date hireDate = { 0,0,0 }, double annualSalary = 0.0, double annualProductionBonus = 0.0);

	// Accessor functions
	double getAnnualSalary() const; // retrieves the annual salary of the shift supervisor
	double getAnnualProductionBonus() const; // retrieves the annual production bonus of the shift supervisor

	// Mutator functions
	void setAnnualSalary(double annualSalary); // sets the annual salary of the shift supervisor
	void setAnnualProductionBonus(double annualProductionBonus); // sets the annual production bonus of the shift supervisor

	// Operator Overloaded Functions
	friend std::ostream& operator<<(std::ostream& os, const ShiftSupervisor& supervisor);// Overloaded stream insertion operator to print out the shift supervisor's information

};