/* Name: Vicente James Caballero Perez
Date: 2/9/2020
Section: 3363-0008
Assignment: Pell Numbers Program
Due Date: 2/9/2020
About this project: This program will output the pell number sequence up to the nth number as desired by the user
 and calculate the summation of the displayed numbers.
Assumptions: Assumes numeric integer input by user.

All work below was performed by Vicente James Caballero Perez */

#include <iostream>

using namespace std;

int main() {

    int DesiredSequence=0;              //user input variable determing how many numbers to display of the Pell Numbers
    int PellCurrent;                    //holds value of pell number calculated each loop

    cout << "Welcome to the Pell Numbers Program!" <<endl;

    do
    {
        cout<< "Please enter in how many numbers of the Pell Number Sequence you would like displayed (or -99 to quit):\n";
        cin >> DesiredSequence;
        //Validation for DesiredSequence
        while (DesiredSequence<0 && DesiredSequence != -99)
        {cout<<"Invalid input please enter an integer 0 or greater or -99 to quit:\n";
        cin >> DesiredSequence;}

        //Initialize/Reinitialize running total and Pell number holders for loops.
        int Pell0=0;            //initialized for 0th number of pell sequence; used to hold the Pell number 2 repetitions before current
        int Pell1=1;            //initialized for 1st number of pell sequence, used to hold the Pell number 1 repetition before current
        int PellTotal=0;        //running total of Pell Numbers displayed.

        //calculating and displaying Pell Number sequence up to the DesiredSequence number of terms.
        for (int RepNumber = 0; RepNumber <= DesiredSequence; RepNumber++)
            //0th term of Pell Number sequence
            if (RepNumber == 0)
                cout << Pell0 << endl;
            //1st term of Pell Number sequence
            else if (RepNumber == 1)
            {
                cout << Pell1 << endl;
                PellTotal+=Pell1;
            }
            //nth term of Pell Number Sequence
            else
            {
                PellCurrent = 2*Pell1 + Pell0;
                cout << PellCurrent << endl;
                PellTotal+=PellCurrent;
                Pell0 = Pell1;
                Pell1 = PellCurrent;
            }
        if (DesiredSequence !=-99)
            cout<<"Sum of this sequence of pell numbers = "<<PellTotal<<endl;

    }
    while (DesiredSequence!=-99);
        cout<<"Thank you for using this program!.\n";
    return 0;
}
