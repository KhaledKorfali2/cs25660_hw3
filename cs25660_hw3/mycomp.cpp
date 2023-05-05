//
//	Name:		Korfali, Khaled
//	Homework:	3
//	Due: 		05-05-2023
//	Course:		cs-2560-01-sp23
//
//	Description:
//		This program allows the user to enter information for different types of employees, including Employee, ProductionWorker,
//		ShiftSupervisor, and TeamLeader. The program prompts the user to enter the employee's name, ID number, hire date, and other
//		relevant information depending on the type of employee. The program then writes this information to a file specified by the
//		user. The program also checks that the number of entries specified by the user is a positive integer and prompts the user to
//		re-enter if it is not. The program uses classes and inheritance to create the different types of employees, and overloads
//		the << operator to allow the employee information to be output to the file.
//
//

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>

#include"Employee.h"
#include"ProductionWorker.h"
#include"ShiftSupervisor.h"
#include"TeamLeader.h"

using namespace std;

// Function Prototypes
bool isPositiveInteger(string input);


int main()
{
	string fileName;

	// Universal varialbes that all objects of Employee type will use
	string employeeType;
	string name;
	Date hireDate;
	string employeeNum;

	string numOfEntires;
	
	// Display Header
	cout << "My Company by K. Korfali" << endl << endl;
	cout << "Please enter the name of your output file: ";
	cin >> fileName;

	// Open output file with given file name
	ofstream outputFile(fileName);

	// Check if file was opened successfully
	if (!outputFile) 
	{
		cerr << "Error failed to open file '" << fileName << "' for writing." << endl;
		return 1;
	}

	// Indicate that the file was successfully opened
	cout << fileName << " Successfully Opened." << endl;

	// Loop until valid input is entered
	do {
		// Display Input Prompt and Store User Choice
		cout << "Please enter the number of entries you will be inputting (positive integers only): ";
		cin >> numOfEntires;

		// Check if input is valid
		if (!isPositiveInteger(numOfEntires))
		{
			cout << "Invalid input. Please enter a positive integer." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			numOfEntires = "-1";
		}
	} while (numOfEntires == "-1");

	// Loop through the number of entries specified by the user
	for (int i = 0; i < stoi(numOfEntires); i++)
	{
		// Loop until a valid employee type is selected
		do {
			system("clear");

			// Display Header
			cout << "My Company by K. Korfali" << endl << endl;

			// Display Input Prompt and Store User Choice
			cout << "Please select what type of employee you will enter for entry number "<< i+1 <<": " << endl;
			cout << "1) Employee" << endl;
			cout << "2) Production Worker" << endl;
			cout << "3) Shift Supervisor" << endl;
			cout << "4) Team Leader" << endl;
			cout << "Please enter 1, 2, 3, or 4 to choose: ";
			cin >> employeeType;
		} while (employeeType != "1" && employeeType != "2" && employeeType != "3" && employeeType != "4");



		// If user selected Employee
		if (employeeType == "1")
		{
			// Create an Employee object
			Employee aEmployee;

			// Get employee information from user and store them into the employee object
			cout << "Please enter the employee's name: ";
			getline(cin >> ws, name);
			aEmployee.setName(name);

			cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			cin >> employeeNum;
			aEmployee.setEmpyloyeeNum(employeeNum);

			cout << "Please enter the date that " << name << " was hired (month day year): ";
			cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aEmployee.setHireDate(hireDate);
			
			//Employee aEmployee(name, employeeNum, hireDate);

			// Output emplyee information to user specified file
			outputFile << aEmployee << endl << endl;
		}
		else if (employeeType == "2") // If User selected Production Worker
		{
			// Create an ProductionWorker object
			ProductionWorker aProductionWorker;

			// Declare variables to store values specific to ProductionWorkers
			int shift;
			double hourlyPayRate;

			// Get ProductionWorker information from user and store them into the ProductionWorker object
			cout << "Please enter the employee's name: ";
			getline(cin >> ws, name);
			aProductionWorker.setName(name);

			cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			cin >> employeeNum;
			aProductionWorker.setEmpyloyeeNum(employeeNum);

			cout << "Please enter the date that " << name << " was hired (month day year): ";
			cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aProductionWorker.setHireDate(hireDate);

			cout << "Please enter the shift (1 for day or 2 for night): ";
			cin >> shift;
			aProductionWorker.setShift(shift);

			cout << "Please enter the hourly pay rate (Ex. 12.32): ";
			cin >> hourlyPayRate;
			aProductionWorker.setHourlyPayRate(hourlyPayRate);

			// Output emplyee information to user specified file
			outputFile << aProductionWorker << endl << endl;
		}
		else if (employeeType == "3")
		{
			// Create an ShiftSupervisor object
			ShiftSupervisor aShiftSupervisor;

			// Declare variables to store values specific to ShiftSupervisor
			double annualSalary;
			double annualProductionBonus;

			// Get ShiftSupervisor information from user and store them into the ShiftSupervisor object
			cout << "Please enter the employee's name: ";
			getline(cin >> ws, name);
			aShiftSupervisor.setName(name);

			cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			cin >> employeeNum;
			aShiftSupervisor.setEmpyloyeeNum(employeeNum);

			cout << "Please enter the date that " << name << " was hired (month day year): ";
			cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aShiftSupervisor.setHireDate(hireDate);

			cout << "Please enter the annual salary that " << name << " recieves (Ex. 12222.32): ";
			cin >> annualSalary;
			aShiftSupervisor.setAnnualSalary(annualSalary);

			cout << "Please enter the annual production bonus that " << name << " will recieves (Ex. 1222.32): ";
			cin >> annualProductionBonus;
			aShiftSupervisor.setAnnualProductionBonus(annualProductionBonus);

			// Output emplyee information to user specified file
			outputFile << aShiftSupervisor << endl << endl;
		}
		else if (employeeType == "4")
		{
			// Create an TeamLeader object
			TeamLeader aTeamLeader;

			// Declare variables to store values specific to TeamLeader
			int shift;
			int requiredTrainingHours;
			int attendedTrainingHours;
			double hourlyPayRate;
			double monthlyBonus;

			// Get TeamLeader information from user and store them into the TeamLeader object
			cout << "Please enter the employee's name: ";
			getline(cin >> ws, name);
			aTeamLeader.setName(name);

			cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			cin >> employeeNum;
			aTeamLeader.setEmpyloyeeNum(employeeNum);

			cout << "Please enter the date that " << name << " was hired (month day year): ";
			cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aTeamLeader.setHireDate(hireDate);

			cout << "Please enter what shift " << name << " will cover (1 for day or 2 for night): ";
			cin >> shift;
			aTeamLeader.setShift(shift);

			cout << "Please enter the hourly pay rate that " << name << " will recieve (Ex. 12.32): ";
			cin >> hourlyPayRate;
			aTeamLeader.setHourlyPayRate(hourlyPayRate);

			cout << "Please enter the monthly bonus that " << name << " will recieves (Ex. 1222.32): ";
			cin >> monthlyBonus;
			aTeamLeader.setMonthlyBonus(monthlyBonus);

			cout << "Please enter the number of required training hour " << name << " needs to attend (Ex. 12): ";
			cin >> requiredTrainingHours;
			aTeamLeader.setRequiredTrainingHours(requiredTrainingHours);

			cout << "Please enter the number of training hour " << name << " has attended (Ex. 12): ";
			cin >> attendedTrainingHours;
			aTeamLeader.setAttendedTrainingHours(attendedTrainingHours);

			// Output emplyee information to user specified file
			outputFile << aTeamLeader << endl << endl;
		}
	}

	// Close file
	outputFile.close();

	system("clear");

	// Display Header
	cout << "My Company by K. Korfali" << endl << endl;

	// Indicate that all information was successfully sent to specified file
	cout << "The information you just entered for all " << stoi(numOfEntires) 
		<< " employees have been successfully sent to " << fileName << "." << endl;
	
	// return 0 to indicate successful execution of program
	return 0;
}


// Function to check if a string represents a positive integer
bool isPositiveInteger(string input)
{
	// Loop through each character in the string
	for (char c : input)
	{
		// If a non-digit character is found or if the first character is a negative sign, return false
		if (!isdigit(c))
		{
			return false;
		}
	}
	// convert input to integer
	int num = stoi(input);

	// If all characters are digits and the string is not empty, return true
	return num > 0;
}