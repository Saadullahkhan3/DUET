#include<iostream>

using namespace std;

int main(){
    float celsius, fahrenheit;
    
    cout << "> Lab 2: Task 5";
    cout << "\n[ Celsius to Fahrenheit Converter ]\n";

    cout << "\nEnter temperature in Celsius: ";
    cin >> celsius;

    fahrenheit = ((9.0/5.0)*(celsius)) + 32;

    cout << "\n" << celsius << " degree Celsius is equal to " << fahrenheit << " degree Fahrenheit.\n";
}
/*
Compile the File
> g++ .\5_celsius_to_fahrenheit.cpp -o 5_celsius_to_fahrenheit    

Run the Executable File
> .\5_celsius_to_fahrenheit.exe

Output:                                                        
> Lab 2: Task 5
[ Celsius to Fahrenheit Converter ]

Enter temperature in Celsius: 50.5

50.5 degree Celsius is equal to 122.9 degree Fahrenheit.
*/