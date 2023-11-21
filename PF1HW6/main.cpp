#include <iostream>
#include <fstream>
#include <vector>
#include "Account.h"
#include "Transaction.h"
using namespace std;

// Reads the accounts vector //
void accountRead(const string filename, vector<Account> & accounts){
   ifstream din;

   din.open(filename);

   string firstName, lastName, PIN, accountNumber;

   while(!din.eof()){
    din >> firstName >> lastName >> PIN >> accountNumber;
    Account account(firstName, lastName, PIN, accountNumber);

    if(!din.eof()){
        accounts.push_back(account);
    }
   }
   din.close();
};

// Writes the accounts into a separate txt file //
void accountWrite(string filename, vector<Account> accounts){
    ofstream dout;
    dout.open(filename);
    for(int i = 0; i < accounts.size(); i++){
        dout << accounts[i].getFirstName() << " " << accounts[i].getLastName() << " " << accounts[i].getPIN() << " " << accounts[i].getAccountNumber() << " " << endl;
        }
        dout.close();
}
// Reads the transaction vector //
void transactionRead(string filename, vector<Transaction> & transactions){
    ifstream din;
    din.open(filename);
    string from, to, amount;
    while(!din.eof()){
        din >> from >> to >> amount;
        Transaction transaction(from, to, amount);
        if(!din.eof()){
            transactions.push_back(transaction);
        }
    }
}

// Writes the transactions into a separate txt file //
void transactionWrite(string filename, vector<Transaction> transactions){
    ofstream dout;

    dout.open(filename);
    for(int i = 0; i < transactions.size(); i++){
        dout << transactions[i].getFromAccountNumber() << " " << transactions[i].getToAccountNumber() << " " << transactions[i].getAmount() << " " << endl;
    }
}


int main()
{
    // Declarations //
    vector<Account> accounts;
    vector<Transaction> transactions;
    Account donnasAccount;

    
    accountRead("accounts.txt", accounts);
    transactionRead("encryptedTransactions.txt", transactions);

    // Prints all the accounts and shows that Donna is found //
    for(int i = 0; i < accounts.size(); i++){
        accounts[i].print();
        if(accounts[i].getFirstName() == "Donna"){
            cout << endl << "************" << endl << "Donna Found" << endl << "************" << endl << endl;
            donnasAccount = accounts[i];
        }
    }
    cout << endl << endl;

    // Prints all the transactions //
   
    for(int i = 0; i < transactions.size(); i++){
        transactions[i].print();
    }
    
    // Shows whether Donna is innocent or not //
    for(int i = 0; i < transactions.size(); i++){
        if(transactions[i].decrypt(donnasAccount.getAccountNumber(), donnasAccount.getPIN())){
            cout << endl << endl << "*******************" << endl;
            cout << "Donna is innocent." << endl;
            cout << "*******************" << endl << endl;
            break;
        }
        }
    
    for(int i = 0; i < accounts.size(); i++){
        for(int j = 0; j < transactions.size(); j++){
            transactions[j].decrypt(accounts[i].getAccountNumber(), accounts[i].getPIN());
        }
    }
    
    // This for loop shows who they hackers are. The rest of main, other than the declarations, needs to be commented out before running this, or it glitches. //
    /*
   for(int i = 0; i < accounts.size(); i++){
        bool innocent = false;
        for(int j = 0; j < transactions.size(); j++){
            //cout << accounts[i].getAccountNumber() << " " << accounts[i].getPIN() << " " << transactions[j].decrypt(accounts[i].getAccountNumber(), accounts[i].getPIN()) << endl;
            if(transactions[j].decrypt(accounts[i].getAccountNumber(), accounts[i].getPIN())){
                innocent = true;
                break;
            }
            
            
        }
        if(innocent == false){
                accounts[i].print();
                cout << "Hacker Found" << endl;
            }
    }
    */
    transactionWrite("decryptedTransactions.txt", transactions);

    return 0;
}