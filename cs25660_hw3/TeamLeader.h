#pragma once

#include"ProductionWorker.h"

#include<string>

class TeamLeader : public ProductionWorker {
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int attendedTrainingHours;
public:
    // Constructors
    TeamLeader(std::string name, std::string employeeNumber, Date hireDate, int shift, double payRate,
        double monthlyBonus, int requiredTrainingHours, int attendedTrainingHours);

    // Accessor functions
    double getMonthlyBonus() const;
    int getRequiredTrainingHours() const;
    int getAttendedTrainingHours() const;
   
    // Mutator functions
    void setMonthlyBonus(double monthlyBonus);
    void setRequiredTrainingHours(int requiredTrainingHours);
    void setAttendedTrainingHours(int attendedTrainingHours);

    // Other member functions
    bool meetsTrainingRequirements() const;

    friend std::ostream& operator<<(std::ostream& os, const TeamLeader& leader);
};

