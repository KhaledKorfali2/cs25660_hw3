#include<string>
#include<iomanip>
#include"ProductionWorker.h"



// Parameterized constructor
ProductionWorker::ProductionWorker(std::string name, std::string employeeNumber, Date hireDate, int shift, double hourlyPayRate)
    : Employee(name, employeeNumber, hireDate)
{
    this->shift = shift;
    this->hourlyPayRate = hourlyPayRate;
}

// Accessor functions
int ProductionWorker::getShift() const
{
    return shift;
}

double ProductionWorker::getHourlyPayRate() const
{
    return hourlyPayRate;
}

// Mutator functions
void ProductionWorker::setShift(int shift)
{
    this->shift = shift;
}

void ProductionWorker::setHourlyPayRate(double hourlyPayRate)
{
    this->hourlyPayRate = hourlyPayRate;
}


std::ostream& operator<<(std::ostream& os, const ProductionWorker& worker)
{
    os << static_cast<const Employee&>(worker)
        << "Shift: " << worker.getShift() << "\n"
        << "Hourly pay rate: " << std::fixed << std::setprecision(2) << worker.getHourlyPayRate();
    return os;
}