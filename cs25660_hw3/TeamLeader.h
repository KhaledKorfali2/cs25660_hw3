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
    TeamLeader(std::string name = "", std::string employeeNumber = "000-O", Date hireDate = { 0,0,0 }, int shift = 1, double payRate = 0.0,
        double monthlyBonus = 0.0, int requiredTrainingHours = 0, int attendedTrainingHours = 0);

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

