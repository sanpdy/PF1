#include <iostream>
#include <fstream>
#include "Account.h"
#include "Transaction.h"
#include <vector>
using namespace std;


void accountRead(const string filename, vector<Account> & accounts){
   ifstream din;

   din.open(filename);

   string firstName, lastName, PIN, accountNumber;

   while(!din.eof()){
    din >> firstName;
    din >> lastName;
    din >> PIN;
    din >> accountNumber;
    Account account(firstName, lastName, PIN, accountNumber);

    if(!din.eof()){
        accounts.push_back(account);
    }
   }
   din.close();
};


void accountWrite(string filename, vector<Account> accounts){
    ofstream dout;
    dout.open(filename);
    for(int i = 0; i < accounts.size(); i++){
        dout << accounts[i].getFirstName() << " ";
        dout << accounts[i].getLastName() << " ";
        dout << accounts[i].getPIN() << " ";
        dout << accounts[i].getAccountNumber() << " ";
        dout << endl;
        }

        dout.close();
}

void transactionRead(string filename, vector<Transaction> & transactions){
    ifstream din;
    din.open(filename);
    string from, to, amount;
    while(!din.eof()){
        din >> from;
        din >> to;
        din >> amount;
        Transaction transaction(from, to, amount);
        
        if(!din.eof()){
            transactions.push_back(transaction);
        }
    }
}

void transactionWrite(string filename, vector<Transaction> transactions){
    ofstream dout;

    dout.open(filename);
    for(int i = 0; i < transactions.size(); i++){
        dout << transactions[i].getFromAccountNumber() << " ";
        dout << transactions[i].getToAccountNumber() << " ";
        dout << transactions[i].getAmount() << " ";
        dout << endl;
    }
}

int main()
{
    vector<Account> accounts;
    vector<Transaction> transactions;
    Account donnasAccount;
    accountRead("accounts.txt", accounts);
    accountWrite("accounts.txt", accounts);
    transactionRead("encryptedTransactions.txt", transactions);
    transactionWrite("encryptedTransactions.txt", transactions);


    return 0;
}