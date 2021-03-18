/* Name: Vicente James Caballero Perez
Date: 4/8/2020
Section: 3363-0008
Assignment: Lottery Numbers Program
Due Date: 4/8/2020
About this project: Determine and arrange data from past lottery numbers by frequency.
Assumptions: Appropriate data type for user inputs.

All work below was performed by Vicente James Caballero Perez */

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>

using namespace std;

void MostCommonNumbers(vector <int>);
void LeastCommonNumbers(vector <int>);
void FrequencyOfRegular(vector <int>);
void FrequencyOfPowerball(vector <int>);

const int MAX_REGULAR=69; //Max value of regular lottery numbers
const int MAX_POWERBALL=26; //Max value of powerball numbers

int main()
{
    char MenuChoice;    //user input variable for menu options

    ifstream LotteryDataFile;
    LotteryDataFile.open("Lottery_Powerball_Winning_Numbers.txt");

    //placeholder variables for tranferring numbers from data into appropriate buckets
    int PlaceHolder1, PlaceHolder2, PlaceHolder3, PlaceHolder4, PlaceHolder5, PlaceHolder6;
    //bucket for regular numbers
    vector <int> RegularNumbers;
    //bucket for powerball numbers
    vector <int> PowerBallNumbers;
    //lottery numbers are split into 5 reg followed by 1 powerball, thus the first 5 will go into regular number bucket then the sixth into powerball
    while (LotteryDataFile >> PlaceHolder1 >> PlaceHolder2 >> PlaceHolder3 >> PlaceHolder4 >> PlaceHolder5 >> PlaceHolder6)
    {
        RegularNumbers.push_back(PlaceHolder1);
        RegularNumbers.push_back(PlaceHolder2);
        RegularNumbers.push_back(PlaceHolder3);
        RegularNumbers.push_back(PlaceHolder4);
        RegularNumbers.push_back(PlaceHolder5);
        PowerBallNumbers.push_back(PlaceHolder6);
    }

    cout << "Please select an option (A-D)\n";
    cin >> MenuChoice;
    if (toupper(MenuChoice)=='A')
        MostCommonNumbers(RegularNumbers);
    else if (toupper(MenuChoice)=='B')
        LeastCommonNumbers(RegularNumbers);
    else if (toupper(MenuChoice)=='C')
        FrequencyOfRegular(RegularNumbers);
    else if (toupper(MenuChoice)=='D')
        FrequencyOfPowerball(PowerBallNumbers);
    else
        cout << "Invalid Option Entered.";

    return 0;
}

void MostCommonNumbers(vector <int> LotteryData)
{
    //below are variables for holding the most frequent lottery numbers and their frequencies
    //there were other ways I thought about doing it but this seemed the easiest
    int largest = -1;
    int secondlargest = -2;
    int thirdlargest = -3;
    int fourthlargest = -4;
    int fifthlargest = -5;
    int sixthlargest = -6;
    int seventhlargest =-7;
    int eighthlargest = -8;
    int ninthlargest = -9;
    int tenthlargest = -10;
    double largestpercent = -1;
    double secondlargestpercent = -2;
    double thirdlargestpercent = -3;
    double fourthlargestpercent = -4;
    double fifthlargestpercent = -5;
    double sixthlargestpercent = -6;
    double seventhlargestpercent = -7;
    double eighthlargestpercent = -8;
    double ninthlargestpercent = -9;
    double tenthlargestpercent = -10;

    //the below loop cycles through each possible value of the lottery number determines the frequency
    //and then compares it to the currently determined highest frequency to determine its spot
    for (int counter=1; counter<=MAX_REGULAR; counter++)
    {
        double frequency = 0;
        double TotalDataPoints = 0;
        for (auto number : LotteryData)
        {
            TotalDataPoints++;
            if (number == counter)
                frequency++;
        }
        double frequencyPercent = (frequency/TotalDataPoints)*100;
        if (frequencyPercent >= largestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = seventhlargest;
            seventhlargest = sixthlargest;
            sixthlargest = fifthlargest;
            fifthlargest = fourthlargest;
            fourthlargest = thirdlargest;
            thirdlargest = secondlargest;
            secondlargest = largest;
            largest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = seventhlargestpercent;
            seventhlargestpercent = sixthlargestpercent;
            sixthlargestpercent = fifthlargestpercent;
            fifthlargestpercent = fourthlargestpercent;
            fourthlargestpercent = thirdlargestpercent;
            thirdlargestpercent = secondlargestpercent;
            secondlargestpercent = largestpercent;
            largestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= secondlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = seventhlargest;
            seventhlargest = sixthlargest;
            sixthlargest = fifthlargest;
            fifthlargest = fourthlargest;
            fourthlargest = thirdlargest;
            thirdlargest = secondlargest;
            secondlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = seventhlargestpercent;
            seventhlargestpercent = sixthlargestpercent;
            sixthlargestpercent = fifthlargestpercent;
            fifthlargestpercent = fourthlargestpercent;
            fourthlargestpercent = thirdlargestpercent;
            thirdlargestpercent = secondlargestpercent;
            secondlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= thirdlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = seventhlargest;
            seventhlargest = sixthlargest;
            sixthlargest = fifthlargest;
            fifthlargest = fourthlargest;
            fourthlargest = thirdlargest;
            thirdlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = seventhlargestpercent;
            seventhlargestpercent = sixthlargestpercent;
            sixthlargestpercent = fifthlargestpercent;
            fifthlargestpercent = fourthlargestpercent;
            fourthlargestpercent = thirdlargestpercent;
            thirdlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= fourthlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = seventhlargest;
            seventhlargest = sixthlargest;
            sixthlargest = fifthlargest;
            fifthlargest = fourthlargest;
            fourthlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = seventhlargestpercent;
            seventhlargestpercent = sixthlargestpercent;
            sixthlargestpercent = fifthlargestpercent;
            fifthlargestpercent = fourthlargestpercent;
            fourthlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= fifthlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = seventhlargest;
            seventhlargest = sixthlargest;
            sixthlargest = fifthlargest;
            fifthlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = seventhlargestpercent;
            seventhlargestpercent = sixthlargestpercent;
            sixthlargestpercent = fifthlargestpercent;
            fifthlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= sixthlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = seventhlargest;
            seventhlargest = sixthlargest;
            sixthlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = seventhlargestpercent;
            seventhlargestpercent = sixthlargestpercent;
            sixthlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= seventhlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = seventhlargest;
            seventhlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = seventhlargestpercent;
            seventhlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= eighthlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = eighthlargest;
            eighthlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = eighthlargestpercent;
            eighthlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= ninthlargestpercent)
        {
            tenthlargest = ninthlargest;
            ninthlargest = counter;
            tenthlargestpercent = ninthlargestpercent;
            ninthlargestpercent = frequencyPercent;
        }
        else if (frequencyPercent >= tenthlargestpercent)
        {
            tenthlargest = counter;
            tenthlargestpercent = frequencyPercent;
        }
        else;
    }

    cout << "The ten most common lottery numbers are:\n";
    cout << largest << ":\t\t"<<largestpercent<<endl;
    cout << secondlargest << ":\t\t"<<secondlargestpercent<<endl;
    cout << thirdlargest << ":\t\t"<<thirdlargestpercent<<endl;
    cout << fourthlargest << ":\t\t"<<fourthlargestpercent<<endl;
    cout << fifthlargest << ":\t\t"<<fifthlargestpercent<<endl;
    cout << sixthlargest << ":\t\t"<<sixthlargestpercent<<endl;
    cout << seventhlargest << ":\t\t"<<seventhlargestpercent<<endl;
    cout << eighthlargest << ":\t\t"<<eighthlargestpercent<<endl;
    cout << ninthlargest << ":\t\t"<<ninthlargestpercent<<endl;
    cout << tenthlargest << ":\t\t"<<tenthlargestpercent<<endl;
}

void LeastCommonNumbers(vector <int> LotteryData)
{
    //exactly the same as most common except with different placeholder numbers
    int smallest = -1;
    int secondsmallest = -2;
    int thirdsmallest = -3;
    int fourthsmallest = -4;
    int fifthsmallest = -5;
    int sixthsmallest = -6;
    int seventhsmallest =-7;
    int eighthsmallest = -8;
    int ninthsmallest = -9;
    int tenthsmallest = -10;
    double smallestpercent = 101;
    double secondsmallestpercent = 102;
    double thirdsmallestpercent = 103;
    double fourthsmallestpercent = 104;
    double fifthsmallestpercent = 105;
    double sixthsmallestpercent = 106;
    double seventhsmallestpercent = 107;
    double eighthsmallestpercent = 108;
    double ninthsmallestpercent = 109;
    double tenthsmallestpercent = 110;

    //exactly the same as most common except assigning based on least value here
    for (int counter=1; counter<=MAX_REGULAR; counter++)
    {
        double frequency = 0;
        double TotalDataPoints = 0;
        for (auto number : LotteryData)
        {
            TotalDataPoints++;
            if (number == counter)
                frequency++;
        }
        double frequencyPercent = (frequency/TotalDataPoints)*100;
        if (frequencyPercent <= smallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = seventhsmallest;
            seventhsmallest = sixthsmallest;
            sixthsmallest = fifthsmallest;
            fifthsmallest = fourthsmallest;
            fourthsmallest = thirdsmallest;
            thirdsmallest = secondsmallest;
            secondsmallest = smallest;
            smallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = seventhsmallestpercent;
            seventhsmallestpercent = sixthsmallestpercent;
            sixthsmallestpercent = fifthsmallestpercent;
            fifthsmallestpercent = fourthsmallestpercent;
            fourthsmallestpercent = thirdsmallestpercent;
            thirdsmallestpercent = secondsmallestpercent;
            secondsmallestpercent = smallestpercent;
            smallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= secondsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = seventhsmallest;
            seventhsmallest = sixthsmallest;
            sixthsmallest = fifthsmallest;
            fifthsmallest = fourthsmallest;
            fourthsmallest = thirdsmallest;
            thirdsmallest = secondsmallest;
            secondsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = seventhsmallestpercent;
            seventhsmallestpercent = sixthsmallestpercent;
            sixthsmallestpercent = fifthsmallestpercent;
            fifthsmallestpercent = fourthsmallestpercent;
            fourthsmallestpercent = thirdsmallestpercent;
            thirdsmallestpercent = secondsmallestpercent;
            secondsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= thirdsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = seventhsmallest;
            seventhsmallest = sixthsmallest;
            sixthsmallest = fifthsmallest;
            fifthsmallest = fourthsmallest;
            fourthsmallest = thirdsmallest;
            thirdsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = seventhsmallestpercent;
            seventhsmallestpercent = sixthsmallestpercent;
            sixthsmallestpercent = fifthsmallestpercent;
            fifthsmallestpercent = fourthsmallestpercent;
            fourthsmallestpercent = thirdsmallestpercent;
            thirdsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= fourthsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = seventhsmallest;
            seventhsmallest = sixthsmallest;
            sixthsmallest = fifthsmallest;
            fifthsmallest = fourthsmallest;
            fourthsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = seventhsmallestpercent;
            seventhsmallestpercent = sixthsmallestpercent;
            sixthsmallestpercent = fifthsmallestpercent;
            fifthsmallestpercent = fourthsmallestpercent;
            fourthsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= fifthsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = seventhsmallest;
            seventhsmallest = sixthsmallest;
            sixthsmallest = fifthsmallest;
            fifthsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = seventhsmallestpercent;
            seventhsmallestpercent = sixthsmallestpercent;
            sixthsmallestpercent = fifthsmallestpercent;
            fifthsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= sixthsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = seventhsmallest;
            seventhsmallest = sixthsmallest;
            sixthsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = seventhsmallestpercent;
            seventhsmallestpercent = sixthsmallestpercent;
            sixthsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= seventhsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = seventhsmallest;
            seventhsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = seventhsmallestpercent;
            seventhsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= eighthsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = eighthsmallest;
            eighthsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = eighthsmallestpercent;
            eighthsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= ninthsmallestpercent)
        {
            tenthsmallest = ninthsmallest;
            ninthsmallest = counter;
            tenthsmallestpercent = ninthsmallestpercent;
            ninthsmallestpercent = frequencyPercent;
        }
        else if (frequencyPercent <= tenthsmallestpercent)
        {
            tenthsmallest = counter;
            tenthsmallestpercent = frequencyPercent;
        }
        else;
    }
    cout << "The ten least common lottery numbers are:\n";
    cout << smallest << ":\t\t"<<smallestpercent<<endl;
    cout << secondsmallest << ":\t\t"<<secondsmallestpercent<<endl;
    cout << thirdsmallest << ":\t\t"<<thirdsmallestpercent<<endl;
    cout << fourthsmallest << ":\t\t"<<fourthsmallestpercent<<endl;
    cout << fifthsmallest << ":\t\t"<<fifthsmallestpercent<<endl;
    cout << sixthsmallest << ":\t\t"<<sixthsmallestpercent<<endl;
    cout << seventhsmallest << ":\t\t"<<seventhsmallestpercent<<endl;
    cout << eighthsmallest << ":\t\t"<<eighthsmallestpercent<<endl;
    cout << ninthsmallest << ":\t\t"<<ninthsmallestpercent<<endl;
    cout << tenthsmallest << ":\t\t"<<tenthsmallestpercent<<endl;
}

void FrequencyOfRegular(vector <int> LotteryData)
{
    cout << "The frequency of the regular lottery numbers are:\n";
    //loops through each possible value of regular lottery numbers and outputs the frequency of each
    for (int counter=1; counter<=MAX_REGULAR; counter++)
    {
        double frequency = 0;
        double TotalDataPoints = 0;
        for (auto number : LotteryData)
        {
            TotalDataPoints++;
            if (number == counter)
                frequency++;
        }
        cout << frequency << endl << TotalDataPoints <<endl;
        double frequencyPercent = (frequency/TotalDataPoints)*100;
        cout << counter << " : " << frequencyPercent << "%" << endl;
    }
}
void FrequencyOfPowerball(vector <int> LotteryData)
{
    cout << "The frequency of the powerball lottery numbers are:\n";
    //exact same as frequency of reg numbers except for powerball
    for (int counter=1; counter<=MAX_POWERBALL; counter++)
    {
        double frequency = 0;
        double TotalDataPoints = 0;
        for (auto number : LotteryData)
        {
            TotalDataPoints++;
            if (number == counter)
                frequency++;
        }
        double frequencyPercent = (frequency/TotalDataPoints)*100;
        cout << counter << " : " << frequencyPercent << "%" << endl;
    }
}