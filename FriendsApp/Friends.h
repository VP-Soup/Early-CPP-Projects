//Friends Class header file
#ifndef FRIENDS_H
#define FRIENDS_H
#include <string>

class Friends
{
private:
    std::string name;
    std::string phoneNumber;
    int age;
    bool haveASignificantOther;

public:
    Friends();
    Friends(std::string, std::string);
    std::string getName() const;
    std::string getPhoneNumber() const;
    int getAge() const;
    bool getRelationshipStatus() const;
    void changeName(std::string);
    void changePhoneNumber(std::string);
    void changeAge(int);
    void changeRelationshipStatus(bool);
    int NumRSVP();
};

#endif