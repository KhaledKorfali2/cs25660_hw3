#include<string>
#include<stdexcept>
#include "Employee.h"


// Constructor
Employee::Employee(std::string name, std::string employeeNum, Date hireDate)
{
    this->name = name;
    this->employeeNum = employeeNum;
    this->hireDate = hireDate;
}

// Accessor Functions
// Accessor for name
std::string Employee::getName() const
{
    return name;
}

// Accessor for number
std::string Employee::getEmployeeNum() const
{
    return employeeNum;
}

// Accessor for hire date
Date Employee::getHireDate() const
{
    return hireDate;
}

// Mutator for name
void Employee::setName(std::string name)
{
    this->name = name;
}

// Mutator for number
void Employee::setEmpyloyeeNum(std::string employeeNum)
{
    if (isValidIDNum(employeeNum))
    {
        this->employeeNum = employeeNum;
    }
    else 
    {
        throw std::invalid_argument(employeeNum + ": not valid employee id");
    }
    
}

// Mutator for hire date
void Employee::setHireDate(Date hireDate)
{
    this->hireDate = hireDate;
}

bool Employee::isValidIDNum(std::string employeeNum)
{
    // Employee number should be in the format XXX-L, where X is a digit and L is an uppercase letter
    if (employeeNum.length() != 5)
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        if (!isdigit(employeeNum[i]))
        {
            return false;
        }
    }
    if (employeeNum[3] != '-')
    {
        return false;
    }
    if (!isalpha(employeeNum[4]) || islower(employeeNum[4]))
    {
        return false;
    }
    return true;
}


    // Operator Overloaded Functions
std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << "Name: " << employee.getName() << "\n"
        << "EID: " << employee.getEmployeeNum() << "\n"
        << "Hire: " << employee.getHireDate().month << "/"
        << employee.getHireDate().day << "/"
        << employee.getHireDate().year << "/" << std::endl;
    return os;
}

