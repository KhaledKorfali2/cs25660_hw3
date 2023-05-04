#include<iostream>
#include<string>

#include"Employee.h"
#include"ProductionWorker.h"
#include"ShiftSupervisor.h"
#include"TeamLeader.h"

using namespace std;

int main()
{
    // Universal varialbes that all options will use
    int employeeType;
    string name;
    Date hireDate;
    string employeeNum;

    cout << "My Company by K. Korfali" << endl << endl;

    cout << "Do you want to enter in a new" << endl;
    cout << "1) Employee" << endl;
    cout << "2) Production Worker" << endl;
    cout << "3) Shift Supervisor" << endl;
    cout << "4) Team Leader" << endl;
    cout << "Please enter 1, 2, 3, or 4 to choose: ";
    cin >> employeeType;

    if (employeeType == 1)
    {
        Employee aEmployee;

        cout << "Please enter the employee's name: ";
        getline(cin >> ws, name);
        aEmployee.setName(name);

        cout << "Please enter " << name << " 's EID (###-L where # are integers and L is uppercase letter): ";
        cin >> employeeNum;
        aEmployee.setEmpyloyeeNum(employeeNum);

        cout << "Please enter the date that " << name << " was hired (month day year): ";
        cin >> hireDate.month >> hireDate.day >> hireDate.year;
        aEmployee.setHireDate(hireDate);

        cout << aEmployee;
    }
    else if (employeeType == 2)
    {
        ProductionWorker aProductionWorker;
        int shift;
        double hourlyPayRate;

        cout << "Please enter the employee's name: ";
        getline(cin >> ws, name);
        aProductionWorker.setName(name);

        cout << "Please enter " << name << " 's EID (###-L where # are integers and L is uppercase letter): ";
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

       
        cout << aProductionWorker;
    }
    else if (employeeType == 3)
    {
        ShiftSupervisor aShiftSupervisor;
        double annualSalary;
        double annualProductionBonus;

        cout << "Please enter the employee's name: ";
        getline(cin >> ws, name);
        aShiftSupervisor.setName(name);

        cout << "Please enter " << name << " 's EID (###-L where # are integers and L is uppercase letter): ";
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


        cout << aShiftSupervisor;
    }
    else if (employeeType == 4)
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

        cout << "Please enter " << name << " 's EID (###-L where # are integers and L is uppercase letter): ";
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

        cout << "Please enter the number of required training hour " << name << "needs to attend (Ex. 12): ";
        cin >> requiredTrainingHours;
        aTeamLeader.setRequiredTrainingHours(requiredTrainingHours);

        cout << "Please enter the number of training hour " << name << " has attended (Ex. 12): ";
        cin >> attendedTrainingHours;
        aTeamLeader.setAttendedTrainingHours(attendedTrainingHours);

        cout << aTeamLeader;
        cout << endl;
        
        if (aTeamLeader.meetsTrainingRequirements())
        {
            cout << name << " has attended all their training hours.";
        }
        else
        {
            cout << name << " has NOT attended all their training hours.";
        }
    }

    cout << endl;
    return 0;
}