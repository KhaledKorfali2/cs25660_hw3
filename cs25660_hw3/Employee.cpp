//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		This program defines the implementation of the Employee class. The Employee class represents an employee
//		with a name, employee number, and hire date. The program includes constructors, accessor and mutator
//		functions for the name, employee number, and hire date. It also includes a function for checking if
//		an employee number is valid and an overloaded operator function for outputting an employee's information.
//

#include<string>
#include<stdexcept>
#include "Employee.h"


// Define the constructor of the Employee class
// It initializes the name, employee number, and hire date of the Employee object
Employee::Employee(std::string name, std::string employeeNum, Date hireDate)
{
	/*if (!isValidIDNum(employeeNum))
	{
		throw std::invalid_argument(employeeNum + ": not valid employee id");
	}
	this->employeeNum = employeeNum;*/
	setEmpyloyeeNum(employeeNum); // Validate and set the employee number using the mutator function
	this->name = name; // Initialize the name of the Employee object
	this->hireDate = hireDate; // Initialize the hire date of the Employee object
}


// Accessor function for the name of the Employee object
std::string Employee::getName() const
{
	return name;
}

// Accessor function for the employee number of the Employee object
std::string Employee::getEmployeeNum() const
{
	return employeeNum;
}

// Accessor function for the hire date of the Employee object
Date Employee::getHireDate() const
{
	return hireDate;
}


// Mutator function for the name of the Employee object
void Employee::setName(std::string name)
{
	this->name = name;
}

// Mutator function for the employee number of the Employee object
// It validates the employee number before setting it
void Employee::setEmpyloyeeNum(std::string employeeNum)
{
	if (isValidIDNum(employeeNum))// Check if the employee number is valid
	{
		this->employeeNum = employeeNum;// Set the employee number of the Employee object
	}
	else 
	{
		// Throw an exception if the employee number is not valid
		throw std::invalid_argument(employeeNum + ": not valid employee id");
	}
	
}

// Mutator function for the hire date of the Employee object
void Employee::setHireDate(Date hireDate)
{
	this->hireDate = hireDate;// Set the hire date of the Employee object
}

// Define a function to check if an employee number is valid
// Employee number should be in the format XXX-L, where X is a digit and L is an uppercase letter
bool Employee::isValidIDNum(std::string employeeNum)
{
	if (employeeNum.length() != 5) // Check if the length of the employee number is 5
	{
		return false; // If not, return false
	}
	for (int i = 0; i < 3; i++)// Check the first 3 characters of the employee number
	{
		if (!isdigit(employeeNum[i]))// If any of the first 3 characters is not a digit
		{
			return false; // Return false
		}
	}
	if (employeeNum[3] != '-')// Check the fourth character of the employee number
	{
		return false;// If it's not a hyphen, return false
	}
	if (!isalpha(employeeNum[4]) || islower(employeeNum[4]))// Check the last character of the employee number
	{
		return false;// If it's not an uppercase letter, return false
	}
	return true;// If all checks passed, return true
}

// Overloaded output stream insertion operator to print Employee object's information.
std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	// Display all information about a Employee object
	os << "Name: " << employee.getName() << "\n" //print the name
		<< "EID: " << employee.getEmployeeNum() << "\n" //print the employee number
		<< "Hire: " << employee.getHireDate().month << "/" //print the hire date month followed by /
		<< employee.getHireDate().day << "/" //print the hire date day followed by /
		<< employee.getHireDate().year; // print the hire date year
	return os;
}

