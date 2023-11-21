#include "Account.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Account::Account(){
    this->firstName = "";
    this->lastName = "";
    this->PIN = "9999";
    this->accountNumber = "9999999999";

}

Account::Account(const string firstName,const string lastName,const string PIN, const string accountNumber){
   this->firstName = firstName;
   this->lastName = lastName;
   this->PIN = PIN;
   this->accountNumber = accountNumber;
}

Account::Account(const Account & copy){
    this->firstName = copy.firstName;
    this->lastName = copy.lastName;
    this->PIN = copy.PIN;
    this->accountNumber = copy.accountNumber;
}

Account::~Account()
{
}

void Account::print() const{
   cout << this->firstName << " ";
   cout << this->lastName << " ";
   cout << this->PIN << " ";
   cout << this->accountNumber << " ";
   cout << endl;

}

string Account::getFirstName() const{
    return this->firstName;
}

string Account::getLastName() const{
    return this->lastName;
}

string Account::getPIN() const{
    return this->PIN;
}

string Account::getAccountNumber() const{ 
    return this->accountNumber;
}

void Account::setFirstName(const string firstName)
{
    this->firstName = firstName;
}

void Account::setLastName(const string lastName)
{
    this->lastName = lastName;
}
void Account::setPIN(const string PIN)
{
    this->PIN = PIN;
}
void Account::setAccountNumber(const string accountNumber)
{
    this->accountNumber = accountNumber;
}

