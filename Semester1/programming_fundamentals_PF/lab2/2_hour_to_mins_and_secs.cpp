#include<iostream>

using namespace std;

int main(){
    float hours, mins, secs;
    
    cout << "> Lab 2: Task 2";
    cout << "\n[ Convert Hour into Minutes and Seconds ]\n";

    cout << "\nEnter Hour(s): ";
    cin >> hours;

    mins = hours * 60;
    secs = mins * 60;

    cout << "The " << hours << " Hour(s) " << "in:";
    cout << "\n- Minutes: " << mins;
    cout << "\n- Seconds: " << secs;
}
/*
Compile the File
> g++ .\2_hour_to_mins_and_secs.cpp -o 2_hour_to_mins_and_secs     

Run the Executable File
> .\2_hour_to_mins_and_secs.exe 

Output:                  
> Lab 2: Task 2
[ Convert Hour into Minutes and Seconds ]

Enter Hour(s): 1.5
The 1.5 Hour(s) in:
- Minutes: 90
- Seconds: 5400
*/