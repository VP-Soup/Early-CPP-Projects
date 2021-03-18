/* Name: Vicente James Caballero Perez
Date: 1/27/2020
Section: 3363-0008
Assignment: Do I need to file a Tax Return
Due Date: 1/26/2020
About this project: This program will determine if the user needs to file taxes based on age and income for singles.
Assumptions:

All work below was performed by Vicente James Caballero Perez */

#include <iostream>

using namespace std;
int main()
{
    char single;        //single or not single
    char age;           //age over 65 or not
    char income;        //income less than 8450 or income less than 9700 depending on path

    cout << "Welcome, this program will help you determine if you need to file taxes." << endl;

    //Begin questioning
    cout<<"Are you single (Y/N)?\n";
    cin>>single;
    switch (single)
        {
        case 'y':
        case 'Y':
            //User is single, determine age range.
                cout<<"Are you under 65 years of age (Y/N)?\n";
                cin>>age;
                switch (age)
                    {
                    case 'y':
                    case 'Y':
                        //User over 65, use $8450 income cap for tax filing determination.
                            cout<<"Is your gross income less than $8450 (Y/N)?\n";
                            cin>>income;
                            switch (income)
                            {
                                case 'y':
                                case 'Y':
                                    cout<<"You do not have to file an income tax return.\n";
                                    break;
                                case 'n':
                                case 'N':
                                    cout<<"You have to file an income tax return.\n";
                                    break;
                                default: cout<<"Invalid input, please run the program again and respond with Y or N.\n";
                            }
                            break;
                    case 'n':
                    case 'N':
                        //User less than 65, use $9700 income cap for tax filing determination.
                            cout<<"Is your gross income less than $9700 (Y/N)?\n";
                            cin>>income;
                            switch (income)
                            {
                                case 'y':
                                case 'Y':
                                    cout << "You do not have to file an income tax return.\n";
                                    break;
                                case 'n':
                                case 'N':
                                    cout << "You have to file an income tax return.\n";
                                    break;
                                default:
                                    cout << "Invalid input, please run the program again and respond with Y or N.\n";
                            }
                            break;
                    default: cout<<"Invalid input, please run the program again and respond with Y or N.\n";
                    }
                break;
        case 'n':
        case 'N': cout<<"This program is only for singles.\n";
                break;
        default: cout<<"Invalid input, please run the program again and respond with a Y or N.\n";
        }
    return 0;
}
