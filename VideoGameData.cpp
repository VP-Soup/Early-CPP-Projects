/* Name: Vicente James Caballero Perez
Date: 4/8/2020
Section: 3363-0008
Assignment: Video Game Data Program
Due Date: 4/15/2020
About this project: Creates a structure for containing a name and three associated scores, and array to hold many of such a structure.
Assumptions: Appropriate data type for numerical inputs

All work below was performed by Vicente James Caballero Perez */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct VideoGameData
{
    string Name;
    double lowestScore;
    double highScore;
    double avgScore;
};

void AddData(vector<VideoGameData> &);
void CalculateAvg(vector<VideoGameData> &);
void DisplayData(vector<VideoGameData> &);
void displaymenu();

int main()
{
    //vector of type VideoGameData to hold a dynamic amount of data
    vector<VideoGameData> VGDataVector;

    char menuChoice;        //var for selecting menu options

    //menu choice given once before and quits if user chooses d or D
    do
    {
        cout<<"Please choose an option from below A-D.\n";
        displaymenu();
        cin>>menuChoice;
        //validation for menu choice
        if (toupper(menuChoice)=='A')
            AddData(VGDataVector);
        else if (toupper(menuChoice)=='B')
            CalculateAvg(VGDataVector);
        else if (toupper(menuChoice)=='C')
            DisplayData(VGDataVector);
        else
            cout << "Invalid Option Entered.";
    }
    while (toupper(menuChoice)!='D');
    cout<<"Thank you for using this program.\n";

    return 0;
}

//function for creating new VideoGameData and adding it to the vector in main
void AddData(vector<VideoGameData> &VGDataVector)
{
    VideoGameData* NewData=nullptr;
    NewData = new VideoGameData;
    cout<<"Please enter the video game name\n";
    getline(cin, NewData->Name);
    //validation loop testing if NewData->Name is empty or only spaces
    while ((NewData->Name).empty() || (NewData->Name).find_first_not_of(' ') == string::npos)
    {
        cout<<"Please enter a non-empty name.\n";
        getline(cin, NewData->Name);
    }
    cout<<"Please enter the lowest score\n";
    cin >> NewData->lowestScore;
    //validation for greater than 0 values
    while (NewData->lowestScore <= 0)
    {
        cout<<"Please enter a value greater than 0\n";
        cin >> NewData->lowestScore;
    }
    cout<<"Please enter the highest score\n";
    cin >> NewData->highScore;
    //same validation as low score
    while (NewData->highScore <= 0)
    {
        cout<<"Please enter a value greater than 0\n";
        cin >> NewData->highScore;
    }
    VGDataVector.push_back(*NewData);
}
//function for calculating averages on previously entered data and putting it in the vector.
void CalculateAvg(vector<VideoGameData> &VGDataVector)
{
    for (int count=0; count<VGDataVector.size(); count++)
        VGDataVector[count].avgScore=(VGDataVector[count].lowestScore+VGDataVector[count].highScore)/2;
    cout << "Complete.\n";
}
//cycles through the vector members and displays all values of each structure.
void DisplayData(vector<VideoGameData> &VGDataVector)
{
    for (int count=0; count<VGDataVector.size(); count++)
    {
        cout << "Name: " << VGDataVector[count].Name << endl;
        cout << "Lowest score: " << VGDataVector[count].lowestScore << endl;
        cout << "Highest score: " << VGDataVector[count].highScore << endl;
        cout << "Average score: " << VGDataVector[count].avgScore << endl;
    }
}

void displaymenu()
{
    cout << "A) Add Data\n";
    cout << "B) Compute Averages\n";
    cout << "C) Display Data\n";
    cout << "D) Quit\n";
}