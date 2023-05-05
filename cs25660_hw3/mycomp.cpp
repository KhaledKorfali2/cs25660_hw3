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

	ofstream outputFile(fileName);
	if (!outputFile) 
	{
		cerr << "Error failed to open file '" << fileName << "' for writing." << endl;
		return 1;
	}

	cout << fileName << " Successfully Opened." << endl;

	do {
		// Display Input Prompt and Store User Choice
		cout << "Please enter the number of entries you will be inputting (positive integers only): ";
		cin >> numOfEntires;

		// Check if input is valid
		if (!isPositiveInteger(numOfEntires)) {
			cout << "Invalid input. Please enter a positive integer." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			numOfEntires = "-1";
		}
	} while (numOfEntires == "-1");

	for (int i = 0; i < stoi(numOfEntires); i++)
	{
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
			Employee aEmployee;

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

			outputFile << aEmployee << endl << endl;
		}
		else if (employeeType == "2") // If User selected Production Worker
		{
			ProductionWorker aProductionWorker;
			int shift;
			double hourlyPayRate;

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


			outputFile << aProductionWorker << endl << endl;
		}
		else if (employeeType == "3")
		{
			ShiftSupervisor aShiftSupervisor;
			double annualSalary;
			double annualProductionBonus;

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


			outputFile << aShiftSupervisor << endl << endl;
		}
		else if (employeeType == "4")
		{
			TeamLeader aTeamLeader;
			int shift;
			int requiredTrainingHours;
			int attendedTrainingHours;
			double hourlyPayRate;
			double monthlyBonus;

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

			outputFile << aTeamLeader << endl << endl;
		}
	}

	outputFile.close();

	system("clear");

	// Display Header
	cout << "My Company by K. Korfali" << endl << endl;

	cout << "The information you just entered for all " << stoi(numOfEntires) 
		<< " employees have been successfully sent to " << fileName << "." << endl;
	
	return 0;
}



bool isPositiveInteger(string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	int num = stoi(input);
	return num > 0;
}