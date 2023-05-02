#include<iostream>
#include<string>

#include"ProductionWorker.h"
#include"ShiftSupervisor.h"
#include"TeamLeader.h"

using namespace std;

int main()
{
    cout << "My Company by K. Korfali" << endl << endl;

    ProductionWorker pw("John Smith", "123", {1,2,2000}, 1, 15.50);
    cout << pw << endl;
   


    ShiftSupervisor ss("Jane Doe", "456", { 1,1,2300 }, 50000.00, 1000.00);
    cout << ss << endl;

    //
    cout << pw << ss << endl;
    return 0;
}