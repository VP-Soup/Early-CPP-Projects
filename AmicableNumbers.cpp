/* Name: Vicente James Caballero Perez
Date: 2/2/2020
Section: 3363-0008
Assignment: Amicable Numbers Program
Due Date: 2/2/2020
About this project: This program will determine if two numbers are mathematically amicable.
Assumptions: Assumes numeric input by user.

All work below was performed by Vicente James Caballero Perez */

#include <iostream>

using namespace std;
int main()
{
    int num1=0;           //first user entered number, if user enters non integer, will be truncated
    int num2=0;           //second user entered number, if user enters non integer, will be truncated
    char RunAgain='Y';      //determine if program will be run again

    cout<<"This number will determine if two numbers are mathematically amicable.\n";
    do
    {
        cout<<"Please enter an integer (>=0).\n";
        cin >> num1;
        //validation for num1 to be a positive number
        while (num1 < 0) {
            cout << "Invalid entry. Please enter an integer greater than or equal to 0.\n";
            cin >> num1;
        }
        cout << "Please enter a second integer (>=0).\n";
        cin >> num2;
        //validation for num2 to be a positive number
        while (num2 < 0) {
            cout << "Invalid entry. Please enter an integer greater than or equal to 0.\n";
            cin >> num2;
        }

        int total1=0;       //total of proper divisors for num1
        int total2=0;       //total of proper divisors for num2

        //calculating the total of proper divisors for num1
        for (int divider = 1; divider < num1; divider++)
            if (num1 % divider == 0)
                total1 += divider;
        //calculating the total of proper divisor for num2
        for (int divider = 1; divider < num2; divider++)
            if (num2 % divider == 0)
                total2 += divider;
        //test if numbers are amicable
        if (total1 == num2 && total2 == num1)
            cout << num1 << " and " << num2 << " are amicable.\n";
        else {
            cout << num1 << " and " << num2 << " are NOT amicable.\n";
            cout << "The sum of proper divisors for your first number is: " << total1 << endl;
            cout << "The sum of proper divisors for your second number is: " << total2 << endl;
        }
        cout<<"Do you want the run the program again (Y/N)?\n";
        cin>>RunAgain;
        while (RunAgain !='y' && RunAgain !='Y' && RunAgain !='n' && RunAgain !='N')
        {cout<<"Invalid entry. Please enter a Y or N.\n";
        cin>>RunAgain;}
    }
    while (RunAgain=='Y' || RunAgain=='y');
        cout << "Thank you for using this program.\n";
    return 0;
}
