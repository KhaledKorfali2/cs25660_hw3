#pragma once
//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		// This header file defines a class called Employee and a struct called Date that are used to represent
//		employees and their hire dates. The Employee class has a private member variables for the employee's
//		name, employee number, and hire date. It also has public methods to get and set these member variables,
//		as well as a constructor to initialize them. The header file also includes a function to check the validity
//		of the employee number. The Date struct has three integer member variables to represent the day, month, and
//		year of a date. Finally, the header file includes an overloaded << operator to output an Employee object to
//		an output stream.
//

#include<string>
#include<iostream>

// Date struct
struct Date// define a struct called Date to store day, month, and year as integers
{
	int day;
	int month;
	int year;
};

//Employee Class
class Employee 
{
private:
	std::string name;// private member variable to store employee's name as a string
	std::string employeeNum;// private member variable to store employee's ID number as a string
	Date hireDate;// private member variable to store employee's hire date as a Date struct
	bool isValidIDNum(std::string employeeNum); // private member function to validate employee ID number
public:
	// Constructor
	Employee(std::string name = "", std::string employeeNum = "000-O", Date hireDate = {0,0,0});// constructor to initialize employee object
	
	// Accessors
	std::string getName() const;// public member function to get employee name as a string
	std::string getEmployeeNum() const; // public member function to get employee ID number as a string
	Date getHireDate() const; // public member function to get employee hire date as a Date struct

	// Mutators
	void setName(std::string name); // public member function to set employee name
	void setEmpyloyeeNum(std::string employeeNum); // public member function to set employee ID number
	void setHireDate(Date hireDate); // public member function to set employee hire date

	// Operator Overloaded Functions
	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);// Overloaded stream insertion operator to print out the employee's information
};
