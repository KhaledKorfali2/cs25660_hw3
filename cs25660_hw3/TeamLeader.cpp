#include<string>
#include<stdexcept>
#include<iomanip>
#include"TeamLeader.h"



// Parameterized constructor
TeamLeader::TeamLeader(std::string name, std::string employeeNumber, Date hireDate, int shift, double payRate,
    double monthlyBonus, int requiredTrainingHours, int attendedTrainingHours)
    : ProductionWorker(name, employeeNumber, hireDate, shift, payRate)
{/*
    this->monthlyBonus = monthlyBonus;
    this->requiredTrainingHours = requiredTrainingHours;
    this->attendedTrainingHours = attendedTrainingHours;*/

    setMonthlyBonus(monthlyBonus);
    setRequiredTrainingHours(requiredTrainingHours);
    setAttendedTrainingHours(attendedTrainingHours);
}

// Accessor and mutator functions
double TeamLeader::getMonthlyBonus() const
{
    return monthlyBonus;
}



int TeamLeader::getRequiredTrainingHours() const
{
    return requiredTrainingHours;
}



int TeamLeader::getAttendedTrainingHours() const
{
    return attendedTrainingHours;
}

void TeamLeader::setMonthlyBonus(double monthlyBonus)
{
    if (monthlyBonus < 0.0)
    {
        throw std::invalid_argument("Monthly Bonus cannot be negative");
    }
    this->monthlyBonus = monthlyBonus;
}

void TeamLeader::setRequiredTrainingHours(int requiredTrainingHours)
{
    if (requiredTrainingHours < 0.0)
    {
        throw std::invalid_argument("Required Training Hours cannot be negative");
    }
    this->requiredTrainingHours = requiredTrainingHours;
}

void TeamLeader::setAttendedTrainingHours(int attendedTrainingHours)
{
    if (attendedTrainingHours < 0.0)
    {
        throw std::invalid_argument("Attended Training Hours cannot be negative");
    }
    this->attendedTrainingHours = attendedTrainingHours;
}



// Other member functions
bool TeamLeader::meetsTrainingRequirements() const
{
    return (attendedTrainingHours >= requiredTrainingHours);
}

std::ostream& operator<<(std::ostream& os, const TeamLeader& leader) {
    os << static_cast<const ProductionWorker&>(leader) << "\n"
        << "Monthly Bonus: " << std::fixed << std::setprecision(2) << leader.getMonthlyBonus() << "\n"
        << "Required Training Hours: " << leader.getRequiredTrainingHours() << "\n"
        << "Training Hours Attended: " << leader.getAttendedTrainingHours() << "\n";
    if (leader.meetsTrainingRequirements())
    {
        os << leader.getName() << " has attended all their training hours.";
    }
    else
    {
        os << leader.getName() << " has NOT attended all their training hours.";
    }
    return os;
}

