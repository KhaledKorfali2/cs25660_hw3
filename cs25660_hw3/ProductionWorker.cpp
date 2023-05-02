#include<string>
#include<iomanip>
#include"ProductionWorker.h"



// Parameterized constructor
ProductionWorker::ProductionWorker(std::string name, std::string employeeNumber, Date hireDate, int shift, double hourlyPayRate)
    : Employee(name, employeeNumber, hireDate)
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

    setShift(shift);
    setHourlyPayRate(hourlyPayRate);

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
    if (shift != 1 && shift != 2)
    {
        throw std::invalid_argument("Shift is invalid");
    }
    this->shift = shift;
}

void ProductionWorker::setHourlyPayRate(double hourlyPayRate)
{
    if (hourlyPayRate < 0.0)
    {
        throw std::invalid_argument("Hourly Pay Rate cannot be negative");
    }
    this->hourlyPayRate = hourlyPayRate;
}


std::ostream& operator<<(std::ostream& os, const ProductionWorker& worker)
{
    os << static_cast<const Employee&>(worker)
        << "Shift: " << worker.getShift() << "\n"
        << "Hourly pay rate: " << std::fixed << std::setprecision(2) << worker.getHourlyPayRate();
    return os;
}