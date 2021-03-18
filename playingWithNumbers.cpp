/* Name: Vicente James Caballero Perez
Date: 2/23/2020
Section: 3363-0008
Assignment: Playing With Numbers Program
Due Date: 2/23/2020
About this project: Allows the user to determine if a number is prime or count the number of digits in a number that are prime.
Assumptions: Assumes numeric input by user.

All work below was performed by Vicente James Caballero Perez */

#include <iostream>

using namespace std;
void getValidUserInputPosNumGT0(int&);
bool isprime(int);
int numPrimeDigits(int);
int main()
{
    int MenuChoice;              //used for determining what function to execute
    int userNumber;              //user entered number

    cout << "Welcome to the playing with numbers program, what would you like to do?\n";

    //begin menu loop
    do
    {
        cout << "1: Determine if a number is prime.\n2: Count how many digits in a number are prime.\n3: Quit\n";
        cout << "Please select 1, 2, or 3:\n";
        cin >> MenuChoice;
        //validation for appropriate menu choice
        while (MenuChoice !=1 && MenuChoice !=2 && MenuChoice !=3)
        {
            cout << "Please select 1, 2, or 3:\n";
            cin >> MenuChoice;
        }
        //Menu Choice 1 - Determines if a number is prime using isprime() function
        if (MenuChoice == 1) {
            cout << "Please enter an integer greater than 0:\n";
            cin >> userNumber;
            getValidUserInputPosNumGT0(userNumber);
            if (isprime(userNumber))
                cout << userNumber << " is Prime.\n\n";
            else
                cout << userNumber <<" is not Prime.\n\n";

        }
        //Menu Choice 2 - Outputs number of digits in userNumber that are prime using numPrimeDigits()
        else if (MenuChoice == 2) {
            cout << "Please enter an integer greater than 0:\n";
            cin >> userNumber;
            getValidUserInputPosNumGT0(userNumber);
            cout << "Your number has " << numPrimeDigits(userNumber) <<" digits that are prime.\n\n";

        }
    }
    //exits loop if user inputs 3 as menu choice
    while (MenuChoice !=3);
        cout <<"Thank you for using this program.\n";
    return 0;
}

//function for validating user input to be a positive integer greater than 0
void getValidUserInputPosNumGT0(int &num)
{
    while (num < 0)
    {
        cout << "Invalid input, please enter an integer greater than 0:\n";
        cin >> num;
    }
}

//function for determining if a number is prime
bool isprime(int num)
{
    //initialize counter for total number of proper divisors num has
    int TotalProperDivisors=0;
    //loop to test every number from 1 to num to see how many divide evenly
    for (int PrimeTest=1; PrimeTest<=num; PrimeTest++)
        if (num%PrimeTest == 0)
            TotalProperDivisors++;
    //num is prime if the the only proper divisors are 1 and itself, hence a total of 2 proper divisors.
    if (TotalProperDivisors==2)
        return true;
    else
        return false;
}

//function for counting number of digits that are prime
int numPrimeDigits(int num)
{
    //initialize counter for total number of digits of num that are prime
   int TotalPrimeDigits=0;
   //loop for testing each digit of num to be prime
   //in the first iteration the unit digit is chosen using %10 for testing (ex. (123/1)%10 = 3)
   //in every following iteration a digit from the right side is removed and the new unit digit is chosen for testing
   //until all digits are tested.
   //ex. (123/10)%10 = 2; (123/100)%10 = 1
   for (int DigitSelector=1; DigitSelector < num; DigitSelector *=10)
   {
       int digit;
       digit = (num/DigitSelector)%10;
       if (isprime(digit))
           TotalPrimeDigits++;
   }
   return TotalPrimeDigits;
}