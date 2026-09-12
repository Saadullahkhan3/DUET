#include<iostream>

using namespace std;

int main(){
    float width, lenght, area;
    
    cout << "> Lab 2: Task 1";
    cout << "\n[ Rectangle Area Calculator ]\n";

    cout << "\nEnter the Width of Rectangle: ";
    cin >> lenght;

    cout << "Enter the Lenght of Rectangle: ";
    cin >> width;

    area = width * lenght;

    cout << "The Area of Rectangle is: " << area;
}

/*
Compile the File
> g++ .\1_area_of_rectangle.cpp -o 1_area_of_rectangle      

Run the Executable File
> .\1_area_of_rectangle.exe

Output:
> Lab 2: Task 1
[ Rectangle Area Calculator ]

Enter the Width of Rectangle: 6.5
Enter the Lenght of Rectangle: 10
The Area of Rectangle is: 65
*/