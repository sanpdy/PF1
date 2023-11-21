#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <fstream>

using namespace std;

class Account
{
    public:
      // Constructors
      Account();
      Account(const string firstName, const string lastName, const string PIN, const string accountNumber);
      Account(const Account & copy);
      ~Account();

      // Utility methods
      void print() const;

      // Getters
      string getFirstName() const;
      string getLastName() const;
      string getPIN() const;
      string getAccountNumber() const;

      // Setters
      void setFirstName(const string firstName);
      void setLastName(const string lastName);
      void setPIN(const string PIN);
      void setAccountNumber(const string accountNumber);

      // Public Account attributes
      string firstName;
      string lastName;

    private:
      // Private Account attributes
      string PIN;
      string accountNumber;
};

#endif

