#pragma once
#include<string>
#include<iostream>

// Date struct
struct Date
{
	int day;
	int month;
	int year;
};

//Employee Class
class Employee 
{
private:
	std::string name;
	std::string employeeNum;
	Date hireDate;
	bool isValidIDNum(std::string employeeNum);
public:
	// Constructor
	Employee(std::string name = "", std::string employeeNum = "000-O", Date hireDate = {0,0,0});
	
	// Getters
	std::string getName() const;
	std::string getEmployeeNum() const;
	Date getHireDate() const;

	// Setters
	void setName(std::string name);
	void setEmpyloyeeNum(std::string employeeNum);
	void setHireDate(Date hireDate);

	// Operator Overloaded Functions
	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};
