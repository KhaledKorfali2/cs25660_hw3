#pragma once
//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		This header file defines the implementation of the TeamLeader class, which is a derived class of
//		the ProductionWorker class. The TeamLeader class adds additional attributes to the ProductionWorker
//		class, such as monthlyBonus, requiredTrainingHours, and attendedTrainingHours. The class provides
//		member functions to access and modify these attributes, and to determine if the team leader meets
//		their required training hours. The program also includes an overloaded stream insertion operator
//		and a print function to print out the team leader's information.
//

#include"ProductionWorker.h"
#include<string>

class TeamLeader : public ProductionWorker {
private:
	double monthlyBonus; // Additional attribute: monthly bonus
	int requiredTrainingHours;
	int attendedTrainingHours;
public:
	// Constructors
	TeamLeader(std::string name = "", std::string employeeNumber = "000-O", Date hireDate = { 0,0,0 }, int shift = 1, double payRate = 0.0,
		double monthlyBonus = 0.0, int requiredTrainingHours = 0, int attendedTrainingHours = 0);

	// Accessor functions
	double getMonthlyBonus() const;// Returns the monthly bonu
	int getRequiredTrainingHours() const;// Returns the required training hours
	int getAttendedTrainingHours() const;// Returns the attended training hours
   
	// Mutator functions
	void setMonthlyBonus(double monthlyBonus); // Sets the monthly bonus
	void setRequiredTrainingHours(int requiredTrainingHours); // Sets the required training hours
	void setAttendedTrainingHours(int attendedTrainingHours); // Sets the attended training hours

	// Other member functions
	bool meetsTrainingRequirements() const; // Returns true if the team leader has met their required training hours, otherwise false
	
	// Overloaded operator functions
	friend std::ostream& operator<<(std::ostream& os, const TeamLeader& leader); // Overloaded stream insertion operator to print out the team leader's information
};

