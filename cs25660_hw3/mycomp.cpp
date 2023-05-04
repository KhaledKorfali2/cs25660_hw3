#include<iostream>
#include<string>

#include"Employee.h"
#include"ProductionWorker.h"
#include"ShiftSupervisor.h"
#include"TeamLeader.h"


bool isPositiveInteger(std::string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	int num = stoi(input);
	return num > 0;
}


int main()
{
	// Universal varialbes that all objects of Employee type will use
	std::string employeeType;
	std::string name;
	Date hireDate;
	std::string employeeNum;

	std::string numOfEntires;
	
	// Display Header
	std::cout << "My Company by K. Korfali" << std::endl << std::endl;


	do {
		// Display Input Prompt and Store User Choice
		std::cout << "Please enter the number of entries you will be inputting (positive integers only): ";
		std::cin >> numOfEntires;

		// Check if input is valid
		if (!isPositiveInteger(numOfEntires)) {
			std::cout << "Invalid input. Please enter a positive integer." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			numOfEntires = "-1";
		}
	} while (numOfEntires == "-1");

	// Used to store the created employee objects
	Employee* employeeArr = new Employee[std::stoi(numOfEntires)];

	for (int i = 0; i < std::stoi(numOfEntires); i++)
	{
		do {
			system("clear");

			// Display Header
			std::cout << "My Company by K. Korfali" << std::endl << std::endl;

			// Display Input Prompt and Store User Choice
			std::cout << "Please select what type of employee you will enter for entry number "<< i+1 <<": " << std::endl;
			std::cout << "1) Employee" << std::endl;
			std::cout << "2) Production Worker" << std::endl;
			std::cout << "3) Shift Supervisor" << std::endl;
			std::cout << "4) Team Leader" << std::endl;
			std::cout << "Please enter 1, 2, 3, or 4 to choose: ";
			std::cin >> employeeType;
		} while (employeeType != "1" && employeeType != "2" && employeeType != "3" && employeeType != "4");



		// If user selected Employee
		if (employeeType == "1")
		{
			Employee aEmployee;

			std::cout << "Please enter the employee's name: ";
			std::getline(std::cin >> std::ws, name);
			aEmployee.setName(name);

			std::cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			std::cin >> employeeNum;
			aEmployee.setEmpyloyeeNum(employeeNum);

			std::cout << "Please enter the date that " << name << " was hired (month day year): ";
			std::cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aEmployee.setHireDate(hireDate);

			//std::cout << aEmployee;
			
			// Add new Employee to array
			*(employeeArr + i) = aEmployee;
		}
		else if (employeeType == "2") // If User selected Production Worker
		{
			ProductionWorker aProductionWorker;
			int shift;
			double hourlyPayRate;

			std::cout << "Please enter the employee's name: ";
			std::getline(std::cin >> std::ws, name);
			aProductionWorker.setName(name);

			std::cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			std::cin >> employeeNum;
			aProductionWorker.setEmpyloyeeNum(employeeNum);

			std::cout << "Please enter the date that " << name << " was hired (month day year): ";
			std::cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aProductionWorker.setHireDate(hireDate);

			std::cout << "Please enter the shift (1 for day or 2 for night): ";
			std::cin >> shift;
			aProductionWorker.setShift(shift);

			std::cout << "Please enter the hourly pay rate (Ex. 12.32): ";
			std::cin >> hourlyPayRate;
			aProductionWorker.setHourlyPayRate(hourlyPayRate);


			//std::cout << aProductionWorker;

			// Add new Production Worker to array
			*(employeeArr + i) = aProductionWorker;
		}
		else if (employeeType == "3")
		{
			ShiftSupervisor aShiftSupervisor;
			double annualSalary;
			double annualProductionBonus;

			std::cout << "Please enter the employee's name: ";
			std::getline(std::cin >> std::ws, name);
			aShiftSupervisor.setName(name);

			std::cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			std::cin >> employeeNum;
			aShiftSupervisor.setEmpyloyeeNum(employeeNum);

			std::cout << "Please enter the date that " << name << " was hired (month day year): ";
			std::cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aShiftSupervisor.setHireDate(hireDate);

			std::cout << "Please enter the annual salary that " << name << " recieves (Ex. 12222.32): ";
			std::cin >> annualSalary;
			aShiftSupervisor.setAnnualSalary(annualSalary);

			std::cout << "Please enter the annual production bonus that " << name << " will recieves (Ex. 1222.32): ";
			std::cin >> annualProductionBonus;
			aShiftSupervisor.setAnnualProductionBonus(annualProductionBonus);


			//std::cout << aShiftSupervisor;

			// Add new Shift Supervisor to array
			*(employeeArr + i) = aShiftSupervisor;
		}
		else if (employeeType == "4")
		{
			TeamLeader aTeamLeader;
			int shift;
			int requiredTrainingHours;
			int attendedTrainingHours;
			double hourlyPayRate;
			double monthlyBonus;

			std::cout << "Please enter the employee's name: ";
			std::getline(std::cin >> std::ws, name);
			aTeamLeader.setName(name);

			std::cout << "Please enter " << name << "'s EID (###-L where # are integers and L is uppercase letter): ";
			std::cin >> employeeNum;
			aTeamLeader.setEmpyloyeeNum(employeeNum);

			std::cout << "Please enter the date that " << name << " was hired (month day year): ";
			std::cin >> hireDate.month >> hireDate.day >> hireDate.year;
			aTeamLeader.setHireDate(hireDate);

			std::cout << "Please enter what shift " << name << " will cover (1 for day or 2 for night): ";
			std::cin >> shift;
			aTeamLeader.setShift(shift);

			std::cout << "Please enter the hourly pay rate that " << name << " will recieve (Ex. 12.32): ";
			std::cin >> hourlyPayRate;
			aTeamLeader.setHourlyPayRate(hourlyPayRate);

			std::cout << "Please enter the monthly bonus that " << name << " will recieves (Ex. 1222.32): ";
			std::cin >> monthlyBonus;
			aTeamLeader.setMonthlyBonus(monthlyBonus);

			std::cout << "Please enter the number of required training hour " << name << "needs to attend (Ex. 12): ";
			std::cin >> requiredTrainingHours;
			aTeamLeader.setRequiredTrainingHours(requiredTrainingHours);

			std::cout << "Please enter the number of training hour " << name << " has attended (Ex. 12): ";
			std::cin >> attendedTrainingHours;
			aTeamLeader.setAttendedTrainingHours(attendedTrainingHours);

			std::cout << aTeamLeader;
			//std::cout << std::endl;

			*(employeeArr + i) = aTeamLeader;
		}
	}


	system("clear");

	// Display Header
	std::cout << "My Company by K. Korfali" << std::endl << std::endl;

	std::cout << "Here is the information you just entered for all " << std::stoi(numOfEntires) << " employees." << std::endl;
	for (int i = 0; i < std::stoi(numOfEntires); i++)
	{
		std::cout << *(employeeArr + i) << std::endl << std::endl;
	}

	// Memory Management
	delete[] employeeArr;
	

	// Final endl
	std::cout << std::endl;
	return 0;
}