//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		This program defines the implementation of the TeamLeader class which is a derived class of the ProductionWorker class.
//		The TeamLeader class adds additional attributes to the ProductionWorker class, such as monthlyBonus, requiredTrainingHours, and attendedTrainingHours.
//		The class provides member functions to access and modify these attributes, and to determine if the team leader meets their required training hours.
//		The program also includes overloaded stream insertion operator and a print function to print out the team leader's information. 
//

#include<string>
#include<stdexcept>
#include<iomanip>
#include"TeamLeader.h"



// Define the constructor of the Employee class
// It initializes the all the data members of the TeamLeader object
TeamLeader::TeamLeader(std::string name, std::string employeeNumber, Date hireDate, int shift, double payRate,
	double monthlyBonus, int requiredTrainingHours, int attendedTrainingHours)
	: ProductionWorker(name, employeeNumber, hireDate, shift, payRate)
{/*
	this->monthlyBonus = monthlyBonus;
	this->requiredTrainingHours = requiredTrainingHours;
	this->attendedTrainingHours = attendedTrainingHours;*/

	// Validate inputs for monthlyBonus, requiredTrainingHours, and attendedTrainingHours before assigning values to data members
	// If any of the inputs are invalid, throw an exception with an error message
	setMonthlyBonus(monthlyBonus);
	setRequiredTrainingHours(requiredTrainingHours);
	setAttendedTrainingHours(attendedTrainingHours);
}

// Accessor function for monthly bonus.
double TeamLeader::getMonthlyBonus() const
{
	return monthlyBonus;
}


// Accessor function for required training hours.
int TeamLeader::getRequiredTrainingHours() const
{
	return requiredTrainingHours;
}


// Accessor function for attended training hours.
int TeamLeader::getAttendedTrainingHours() const
{
	return attendedTrainingHours;
}

// Mutator function for monthly bonus.
void TeamLeader::setMonthlyBonus(double monthlyBonus)
{
	// Check if the input value for monthlyBonus is valid before assigning it to the data member
	// If the value is invalid, throw an exception with an error message
	if (monthlyBonus < 0.0)
	{
		throw std::invalid_argument("Monthly Bonus cannot be negative");
	}
	this->monthlyBonus = monthlyBonus;
}

void TeamLeader::setRequiredTrainingHours(int requiredTrainingHours)
{
	// Check if the input value for requiredTrainingHours is valid before assigning it to the data member
	// If the value is invalid, throw an exception with an error message
	if (requiredTrainingHours < 0.0)
	{
		throw std::invalid_argument("Required Training Hours cannot be negative");
	}
	this->requiredTrainingHours = requiredTrainingHours;
}

void TeamLeader::setAttendedTrainingHours(int attendedTrainingHours)
{
	// Check if the input value for attendedTrainingHours is valid before assigning it to the data member
	// If the value is invalid, throw an exception with an error message
	if (attendedTrainingHours < 0.0)
	{
		throw std::invalid_argument("Attended Training Hours cannot be negative");
	}
	this->attendedTrainingHours = attendedTrainingHours;
}


// Check if the team leader has met their required training hours
bool TeamLeader::meetsTrainingRequirements() const
{
	return (attendedTrainingHours >= requiredTrainingHours);
}

// Overloaded output stream insertion operator to print TeamLeader object's information.
std::ostream& operator<<(std::ostream& os, const TeamLeader& leader) {
	os << static_cast<const ProductionWorker&>(leader) << "\n"// call the base class's output stream insertion operator
		<< "Monthly Bonus: " << std::fixed << std::setprecision(2) << leader.getMonthlyBonus() << "\n" // print monthy bonus
		<< "Required Training Hours: " << leader.getRequiredTrainingHours() << "\n" // print required training hours
		<< "Training Hours Attended: " << leader.getAttendedTrainingHours() << "\n"; // print attended training hours
	if (leader.meetsTrainingRequirements())// If the team leader has met their required training hours, print a message saying so
	{
		os << leader.getName() << " has attended all their training hours.";
	}
	else// Otherwise, print a message saying they have not met their required training hours
	{
		os << leader.getName() << " has NOT attended all their training hours.";
	}
	return os;
}

