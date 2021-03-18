/* Name: Vicente James Caballero Perez
Date: 1/27/2020
Section: 3363-0008
Assignment: Ordered Numbers Programs
Due Date: 1/26/2020
About this project: This program will display the numbers entered by the user in ascending order or otherwise that they are equal.
Assumptions: Appropriate user input of numbers.

All work below was performed by Vicente James Caballero Perez */

#include <iostream>

using namespace std;
int main()
{
    double Number1;                 //first number entered by user
    double Number2;                 //second number entered by user
    double Number3;                 //third number entered by user
    double LargestNumber;           //will hold value of variable determined to be largest from user input
    double MiddleNumber;            //will hold value of variable determined to be not the largest or smallest
    double SmallestNumber;          //will hold value of variable determined to be smallest

    //User intro and input
    cout << "Welcome! This program will sort three numbers you enter into ascending order." << endl;
    cout <<"Please enter in a number.\n";
    cin >> Number1;
    cout <<"Please enter in a number.\n";
    cin >> Number2;
    cout <<"Please enter in a number.\n";
    cin >> Number3;

    //determining relative position of Number1
    if (Number1 > Number2 && Number1 > Number3)
        LargestNumber=Number1;
    else if (Number1 > Number2 || Number1 > Number3)
        MiddleNumber=Number1;
    else
        SmallestNumber=Number1;
    //determining relative position of Number2
    if (Number2 > Number1 && Number2 > Number3)
        LargestNumber=Number2;
    else if (Number2 > Number1 || Number2 > Number3)
        MiddleNumber=Number2;
    else if (Number2 == SmallestNumber)
        MiddleNumber=Number2;
    else
        SmallestNumber=Number2;
    //determining relative position of Number3
    if (Number3 > Number1 && Number3 > Number2)
        LargestNumber=Number3;
    else if (Number3 > Number1 || Number3 > Number2)
        MiddleNumber=Number3;
    else if (Number3 == SmallestNumber)
        MiddleNumber=Number3;
    else
        SmallestNumber=Number3;

    //determine whether to display message of value equality or ordered numbers.
    if (Number1 == Number2 && Number1 == Number3)
        cout<<"All numbers are equal.\n";
    else
    {
        cout<<"Your numbers in ascending order are:\n";
        cout<<SmallestNumber<<endl<<MiddleNumber<<endl<<LargestNumber<<endl;
    }

    return 0;
}
