#include<iostream>
#include<string>

#include"Employee.h"
#include"ProductionWorker.h"
#include"ShiftSupervisor.h"
#include"TeamLeader.h"

using namespace std;

int main()
{
    cout << "My Company by K. Korfali" << endl << endl;

    Employee aEmployee("James Sam", "001-A", {1, 2, 2000});
    cout << aEmployee << endl << endl;

    ProductionWorker aProductionWorker("John Smith", "002-B", {1, 2, 2001}, 1, 15.50);
    cout << aProductionWorker << endl << endl;
   
    ShiftSupervisor aShiftSupervisor("Jane Doe", "003-C", {1, 1, 2002}, 50000.00, 1000.00);
    cout << aShiftSupervisor << endl << endl;

    TeamLeader aTeamLeader("Tina Simons", "004-D", { 1, 1, 2002 }, 2, 0.5, 133.22, 15, 10);
    cout << aTeamLeader << endl << endl;

    return 0;
}