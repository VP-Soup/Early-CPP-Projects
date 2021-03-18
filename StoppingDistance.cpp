/* Name: Vicente James Caballero Perez
Date: 1/18/2020
Section: 3363-0008
Assignment: Stopping Distance Program and Unix Commands
Due Date: 1/19/2020
About this project: This program will calculate the stopping distance of a car given user input of velocity
 and coefficient of friction.
Assumptions: Assumes that all user input will be correct (i.e. numeric entries and valid dimensions)

All work below was performed by Vicente James Caballero Perez */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {

    float stopdist;                 //stopping distance of the car in meters
    float velcar;                   //velocity of the car in kilometers per hour by user input - then changed to meters per second for formula
    float cofrict;                  //coefficient of friction - unitless
    const float accelgrav = 9.80;   //constant for acceleration due to gravity in meters per second
    //used float for all of the above since we are only going to use 5 decimal points of accuracy.

    //User input
    cout << "Welcome, this program will help you to calculate the stopping distance of a car." << endl;
    cout << "To begin, please enter the speed of the car (kilometers/hr)" << endl;
    cin >> velcar;
    cout << "Now, please enter the coefficient of friction" << endl;
    cin >> cofrict;

    //Changing velcar to meters per second - multiply by 1000 for km to m and divide by 3600 for hrs to s
    velcar = velcar*1000/3600;
    //Calculation for stopping distance utilizing formula for escape velocity.
    stopdist = (pow(velcar,2))/(2*cofrict*accelgrav);

    //Output results
    cout << "Velocity:                " << fixed << right << showpoint << setprecision(5) << setw(15) << velcar << " m/s" << endl;
    cout << "Coefficient of Friction: " << setw(15) << cofrict << endl;
    cout << "Stopping Distance:       " << setw(15) << stopdist << " m" << endl;

    return 0;
}
