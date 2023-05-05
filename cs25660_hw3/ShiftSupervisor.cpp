#include<stdexcept>
#include<iomanip>
#include"ShiftSupervisor.h"



// Parameterized constructor
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

    setAnnualSalary(annualSalary);
    setAnnualProductionBonus(annualProductionBonus);
}

// Accessor functions
double ShiftSupervisor::getAnnualSalary() const
{
    return annualSalary;
}

double ShiftSupervisor::getAnnualProductionBonus() const
{
    return annualProductionBonus;
}

// Mutator functions
void ShiftSupervisor::setAnnualSalary(double annualSalary)
{
    if (annualSalary < 0.0)
    {
        throw std::invalid_argument("Annual salary cannot be negative");
    }
    this->annualSalary = annualSalary;
}

void ShiftSupervisor::setAnnualProductionBonus(double annualProductionBonus)
{
    if (annualProductionBonus < 0.0)
    {
        throw std::invalid_argument("Annual production bonus cannot be negative");
    }
    this->annualProductionBonus = annualProductionBonus;
}


std::ostream& operator<<(std::ostream& os, const ShiftSupervisor& supervisor)
{
    os << static_cast<const Employee&>(supervisor) << "\n"
        << "Salary: " << std::fixed << std::setprecision(2)<< supervisor.getAnnualSalary() << "\n"
        << "Production Bonus: " << std::fixed << std::setprecision(2) << supervisor.getAnnualProductionBonus();
    return os;
}

