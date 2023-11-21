#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <fstream>

using namespace std;

class Transaction
{
    public:
        // Constructors
        Transaction();
        Transaction(const string fromAccountNumber, const string toAccountNumber, const string amount);
        Transaction(const Transaction & copy);
        ~Transaction();

        // Utility methods
        void print() const;

        // Encryption methods - THESE ARE PROVIDED TO YOU
        void encrypt(const string accountNumber, const string PIN);
        bool decrypt(const string accountNumber, const string PIN);
        string shiftCipherEncoder(const string message, const string key);
        string shiftCipherDecoder(const string message, const string key);

        // Getters
        string getFromAccountNumber() const;
        string getToAccountNumber() const;
        string getAmount() const;

        // Setters
        void setFromAccountNumber(const string fromAccountNumber);
        void setToAccountNumber(const string toAccountNumber);
        void setAmount(const string amount);

    private:
        // Transaction attributes
        string fromAccountNumber;
        string toAccountNumber;
        string amount;
};

#endif

