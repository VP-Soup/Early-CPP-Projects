//Friends Class implementation file

#include"Friends.h"
#include <string>

//default constructor
Friends::Friends()
{
    name="";
    phoneNumber="";
    age=0;
    haveASignificantOther=false;
}

//alternate constructor
Friends::Friends(std::string newName, std::string newPhoneNumber)
{
    name=newName;
    phoneNumber=newPhoneNumber;
    haveASignificantOther=false;
}

//Accessors for each private member variable
std::string Friends::getName() const
{
    return(name);
}
std::string Friends::getPhoneNumber() const
{
    return(phoneNumber);
}
int Friends::getAge() const
{
    return(age);
}
bool Friends::getRelationshipStatus() const
{
    return (haveASignificantOther);
}

//Mutators
void Friends::changeName(std::string newName)
{
    name=newName;
}
void Friends::changePhoneNumber(std::string newNumber)
{
    phoneNumber=newNumber;
}
void Friends::changeAge(int newAge)
{
    age=newAge;
}
void Friends::changeRelationshipStatus(bool newStatus)
{
    haveASignificantOther=newStatus;
}

//
int Friends::NumRSVP()
{
    if (haveASignificantOther)
        return 2;
    else
        return 1;
}