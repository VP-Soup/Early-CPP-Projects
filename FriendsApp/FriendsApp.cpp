/* Name: Vicente James Caballero Perez
Date: 4/23/2020
Section: 3363-0008
Assignment: Friends Program
Due Date: 4/24/2020
About this project: Create three instances of Friend class and display them using a function
Assumptions:

All work below was performed by Vicente James Caballero Perez */

#include <iostream>
#include <string>
#include "Friends.h"

using namespace std;

void displayFriend(Friends const *);

int main()
{
    Friends friend1("A", "123456");
    friend1.changeAge(1);
    friend1.changeRelationshipStatus(true);

    Friends friend2("B", "654321");
    friend2.changeAge(2);

    Friends friend3("C", "000000");
    friend3.changeAge(3);

    displayFriend(&friend1);
    displayFriend(&friend2);
    displayFriend(&friend3);

    cout<<"Total number of people that will be coming to the restaurant: "<<friend1.NumRSVP()+friend2.NumRSVP()+friend3.NumRSVP();

}

void displayFriend(Friends const *friendptr)
{
    string relStatus;
    if (friendptr->getRelationshipStatus())
        relStatus="Yes";
    else
        relStatus="No";

    cout<<"Name: "<<friendptr->getName()<<endl;
    cout<<"Age: "<<friendptr->getAge()<<endl;
    cout<<"PhoneNumber: "<<friendptr->getPhoneNumber()<<endl;
    cout<<"Have A Significant Other: "<<relStatus<<endl<<endl;
}

