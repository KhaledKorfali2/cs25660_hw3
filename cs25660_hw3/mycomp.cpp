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
    cout << "2) ProductionWorker" << endl;
    cout << "3) ShiftSupervisor" << endl;
    cout << "4) TeamLeader" << endl;
    cout << "Please enter 1, 2, 3, or 4 to choose: ";
    cin >> employeeType;

    if (employeeType == 1)
    {
        Employee aEmployee;

        cout << "Please enter the employee's name: ";
        cin >> name;
        aEmployee.setName(name);

        cout << "Please enter the employee's EID (###-L where # are integers and L is uppercase letter):";
        cin >> employeeNum;
        aEmployee.setEmpyloyeeNum(employeeNum);

        cout << "Please enter the hire date for " << name << ". (month day year seperated by spaces):";
        cin >> hireDate.month >> hireDate.day >> hireDate.year;
        aEmployee.setHireDate(hireDate);

        cout << aEmployee;
    }
    else if (employeeType == 2)
    {
        ProductionWorker aProductionWorker;
        int shift;
        double hourlyPayRate;

        cout << "Please enter the production worker's name: ";
        cin >> name;
        aProductionWorker.setName(name);

        cout << "Please enter the production worker's EID (###-L where # are integers and L is uppercase letter):";
        cin >> employeeNum;
        aProductionWorker.setEmpyloyeeNum(employeeNum);

        cout << "Please enter the hire date for " << name << ". (month day year seperated by spaces):";
        cin >> hireDate.month >> hireDate.day >> hireDate.year;
        aProductionWorker.setHireDate(hireDate);

        cout << "Please enter the shift (1 for day or 2 for night): ";
        cin >> shift;
        aProductionWorker.setShift(shift);

        cout << "Please enter the hourly pay rate (Ex. 1222.32): ";
        cin >> hourlyPayRate;
        aProductionWorker.setHourlyPayRate(hourlyPayRate);

       
        cout << aProductionWorker;
    }

    cout << "ProductionWorker" << endl;
    ProductionWorker aProductionWorker("John Smith", "002-B", {1, 2, 2001}, 1, 15.50);
   
    cout << "ShiftSupervisor" << endl;
    ShiftSupervisor aShiftSupervisor("Jane Doe", "003-C", {1, 1, 2002}, 50000.00, 1000.00);
    cout << aShiftSupervisor << endl << endl;

    cout << "TeamLeader" << endl;
    TeamLeader aTeamLeader("Tina Simons", "004-D", { 1, 1, 2002 }, 2, 0.5, 133.22, 15, 10);
    cout << aTeamLeader << endl << endl;

    cout << endl;
    return 0;
}