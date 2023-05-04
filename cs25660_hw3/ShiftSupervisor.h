#pragma once
#include<string>

#include"Employee.h"

// ShiftSupervisor class derived from Employee class
class ShiftSupervisor : public Employee {
private:
    double annualSalary;
    double annualProductionBonus;

public:
    // Constructor
    ShiftSupervisor(std::string name = "", std::string employeeNumber = "000-O", Date hireDate = { 0,0,0 }, double annualSalary = 0.0, double annualProductionBonus = 0.0);

    // Accessor functions
    double getAnnualSalary() const;
    double getAnnualProductionBonus() const;

    // Mutator functions
    void setAnnualSalary(double annualSalary);
    void setAnnualProductionBonus(double annualProductionBonus);

    friend std::ostream& operator<<(std::ostream& os, const ShiftSupervisor& supervisor);

};