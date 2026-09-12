#include<iostream>
#include<string>

using namespace std;

int main(){
    string name;
    int age;
    
    cout << "> Lab 2: Task 4";
    cout << "\n[ Greeting Card ]\n";

    cout << "\nEnter your Name: ";
    getline(cin, name); // Used to get multiple words input

    cout << "Enter your Age: ";
    cin >> age;
    
    cout << "\nHello, " << name + "!" << " You are " << age << " years old.";

    cout << "\n";
    cout << " GREETINGS & HONORS\n";
    cout << " ------------------------------\n";
    cout << " Hello, " << name << "!\n";
    cout << " You are " << age << " years old.\n";
    cout << " \n\n";

    return 0;

}
/*
Compile the File
> g++ .\4_greeting_card.cpp -o 4_greeting_card  

Run the Executable File
> .\4_greeting_card.exe 

Output:                                                        
> Lab 2: Task 4
[ Greeting Card ]

Enter your Name: Saadullah Khan
Enter your Age: 99

Hello, Saadullah Khan! You are 99 years old.
*/