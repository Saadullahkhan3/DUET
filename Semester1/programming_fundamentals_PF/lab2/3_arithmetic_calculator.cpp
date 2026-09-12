#include<iostream>

using namespace std;

int main(){
    float n1, n2;
    
    cout << "> Lab 2: Task 3";
    cout << "\n[ Arithmetic Calculator ]\n";

    cout << "\nEnter Number 1: ";
    cin >> n1;

    cout << "Enter Number 2: ";
    cin >> n2;
    
    cout << "\nArithmetic Operations:" << endl;

    cout << "- " << n1 << " + " << n2 << " = " << (n1 + n2) << endl;
    cout << "- " << n1 << " - " << n2 << " = " << (n1 - n2) << endl;
    cout << "- " << n1 << " * " << n2 << " = " << (n1 * n2) << endl;
    cout << "- " << n1 << " / " << n2 << " = " << (n1 / n2) << endl;
    cout << "- " << n1 << " % " << n2 << " = " << (int(n1) % int(n2)) << endl;
}
/*
Compile the File
> g++ .\3_arithmetic_calculator.cpp -o 3_arithmetic_calculator    

Run the Executable File
> .\3_arithmetic_calculator.exe 

Output:                                   
> Lab 2: Task 3
[ Arithmetic Calculator ]

Enter Number 1: 10
Enter Number 2: 4

Arithmetic Operations:
- 10 + 4 = 14
- 10 - 4 = 6
- 10 * 4 = 40
- 10 / 4 = 2.5
- 10 % 4 = 2
*/