/* Name: Vicente James Caballero Perez
Date: 3/9/2020
Section: 3363-0008
Assignment: Help With Grading Program
Due Date: 3/9/2020
About this project:
Assumptions:

All work below was performed by Vicente James Caballero Perez */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int getValidGrade();
int getValidAssignmentNumber(int);
void displayGrades (string [], vector <int> []);
void AddGrades (string [], vector<int> []);
void RemoveGrades (string [], vector<int> []);
void displayAverageForEachStudent (string [], vector<int> []);
void displayStudentNameLowestScoreEachAssign (string [], vector <int> []);
void displaySortedAverageForEachStudent (string [], vector<int> []);
void swap (int &, int &);
void displaymenu();

const int NUM_STUDENTS =3;

int main()
{
    string students[NUM_STUDENTS] = {"Tom","Jane","Jo"};
    vector <int> grades[NUM_STUDENTS] {{78,98,88,99,77},{62,99,94,85,93}, {73,82,88,85,78}};
    int menuChoice;             //var for storing user menu choice.

    //begin loop until user chooses 7 to quit menu
    do
    {
        displaymenu();
        cin>>menuChoice;
        //validation for menu choice
        while (menuChoice <1 || menuChoice >7)
        {
            cout<<"Invalid choice. Please select 1-7\n";
            cin>>menuChoice;
        }
        if (menuChoice==1)
            displayGrades(students, grades);
        else if (menuChoice==2)
            AddGrades(students, grades);
        else if (menuChoice==3)
            RemoveGrades(students, grades);
        else if (menuChoice==4)
            displayAverageForEachStudent(students, grades);
        else if (menuChoice==5)
            displayStudentNameLowestScoreEachAssign(students, grades);
        else if (menuChoice==6)
            displaySortedAverageForEachStudent(students, grades);
        else;
    }
    while (menuChoice !=7);
        cout<<"Thank you for using this program.\n";

    return 0;
}

//validation for grade input
int getValidGrade(int grade)
{
    while (grade<0 || grade>100)
    {
        cout << "Invalid entry. Please enter an integer from 0-100\n";
        cin>>grade;
    }
    return grade;
}

//validation for assignment number, input will be current size of grade vector for 1 person
int getValidAssignmentNumber(int Max)
{
    int AssignmentNumber;
    cout<<"Please enter an assignment number from 1-"<<Max<<endl;
    cin>>AssignmentNumber;
    while (AssignmentNumber<1 || AssignmentNumber>Max)
    {
        cout << "Invalid entry. Please enter an assignment number from 0-"<<Max<<endl;
        cin>>AssignmentNumber;
    }
    return AssignmentNumber;
}

//displays grades for each student
void displayGrades (string students[], vector <int> grades[])
{
    for (int cycle=0; cycle<NUM_STUDENTS; cycle++)
    {
        cout<<setw(6) << left <<students[cycle]<<"\t";
        for (auto gradeValue : grades[cycle])
            cout << gradeValue <<"\t";
        cout<<endl;
    }
}

//cycles through each student allowing you to add one grade to each
void AddGrades (string students[], vector<int> grades[])
{
    for (int cycle=0; cycle<NUM_STUDENTS; cycle++)
        {
            int NewGrade;
            cout<<" Please enter a grade for student "<< students[cycle]<<":\n";
            cin>>NewGrade;
            //below uses function getValidGrade to validate the new grade
            grades[cycle].push_back(getValidGrade(NewGrade));
        }
}

//removes a grade for a particular assignment from all students
void RemoveGrades (string students[], vector<int> grades[])
{
    //initialize variable for vector position by using getValidAssignmentNumber and subtracting 1 to adjust for array numbering
    int targetPosition = getValidAssignmentNumber(grades[1].size())-1;
    //loop to erase value at targetPosition for each student
    for (int cycle=0; cycle<NUM_STUDENTS; cycle++)
    {
        cout << "Erasing a " << grades[cycle].at(targetPosition) << " for "<<students[cycle]<<endl;
        grades[cycle].erase (grades[cycle].begin() + targetPosition);
    }
    displayGrades(students, grades);
}

//displays the average grade of each student
void displayAverageForEachStudent (string students[], vector<int> grades[])
{
    for (int cycle=0; cycle<NUM_STUDENTS; cycle++)
    {
        //initialize accumulator variable for grade
        int totalGrade = 0;
        for (auto gradeValue : grades[cycle])
            totalGrade += gradeValue;
        //divide by total number of assignments, aka size of vector
        int averageGrade = totalGrade/grades[cycle].size();
        cout <<students[cycle]<<"'s average is: "<<averageGrade<<endl;
    }

}

//displays which student(s) had the lowest score for each assignment
void displayStudentNameLowestScoreEachAssign (string students[], vector <int> grades[])
{
    cout<<"in program\n";
    for (int cycle=0; cycle<grades[1].size(); cycle++)
    {
        cout<< "in first loop\n";
        // variable for storing the lowest grade for an assignment, used for comparison
        int lowestGrade = 101;
        // variable for determining which student had the lowest score
        int lowestStudent = -1;
        for (int studentCycle=0; studentCycle<NUM_STUDENTS; studentCycle++)
        {
            cout<<"in second loop\n";
            //if a particular student had the lowest score then lowest student will simply hold their array position
            if (grades[studentCycle].at(cycle) < lowestGrade)
            {
                lowestGrade = grades[studentCycle].at(cycle);
                lowestStudent = studentCycle;
            }
            //if 2 or more students shared the lowest score, a value will be generated below to determine the situation
            else if (grades[studentCycle].at(cycle) == lowestGrade)
                lowestStudent += studentCycle+2;
            else;
        }

        //displays what student(s) had the lowest score based on value of lowestStudent.
        if (lowestStudent != 3 && lowestStudent !=4 && lowestStudent !=5 && lowestStudent !=7)
            cout<<"The student with the lowest grade for assignment #"<<cycle+1<<" was "<<students[lowestStudent]<<endl;
        else if (lowestStudent == 3)
            cout<<"Students "<<students[0]<<" and "<<students[1]<<" had equally low scores for assignment #"<<cycle+1<<"\n";
        else if (lowestStudent == 4)
            cout<<"Students "<<students[0]<<" and "<<students[2]<<" had equally low scores for assignment #"<<cycle+1<<"\n";
        else if (lowestStudent == 5)
            cout<<"Students "<<students[1]<<" and "<<students[2]<<" had equally low scores for assignment #"<<cycle+1<<"\n";
        else if (lowestStudent == 7)
            cout<<"All students had equally low scores for assignment #"<<cycle+1<<"\n";
    }
}

//creates new student array and new array with each students average and orders them together in ascending order
void displaySortedAverageForEachStudent (string students[], vector<int> grades[])
{
    string newStudents[NUM_STUDENTS];
    //copies old student array to a new one
    for (int i=0; i<NUM_STUDENTS; i++)
        newStudents[i]=students[i];
    int avgGradeArray[NUM_STUDENTS];
    //enters student averages into an array
    for (int cycle=0; cycle<NUM_STUDENTS; cycle++)
    {
        int totalGrade = 0;
        for (auto gradeValue : grades[cycle])
            totalGrade += gradeValue;
        int averageGrade = totalGrade/grades[cycle].size();
        avgGradeArray[cycle]=averageGrade;
    }
    //bubblesort the two above arrays based on avgGradeArray
    for (int maxElement = NUM_STUDENTS - 1; maxElement > 0; maxElement--)
        for (int index = 0; index < maxElement; index++)
            if (avgGradeArray[index] > avgGradeArray[index + 1])
            {
                swap(avgGradeArray[index], avgGradeArray[index + 1]);
                swap(newStudents[index], newStudents[index+1]);
            }
    //outputs new arrays in their new order
    for (int cycle=0; cycle<NUM_STUDENTS; cycle++)
    {
        cout << setw(6) << left << newStudents[cycle] << "\t" << avgGradeArray[cycle] << "\t";
        cout << endl;
    }
}

//function for swapping element positions in array
void swap (int &a, int &b)
{
    int temp=b;
    b=a;
    a=temp;
}

//function for repeated menu display.
void displaymenu()
{
    cout<<"1) Display the grades\n";
    cout<<"2) Add grade\n";
    cout<<"3) Remove grade for all students for a selected assignment\n";
    cout<<"4) Display Average for each student\n";
    cout<<"5) Display the name of the student with the lowest grade for each assignment\n";
    cout<<"6) Display a sorted list of the average scores of students\n";
    cout<<"7) Quit\n";
}
