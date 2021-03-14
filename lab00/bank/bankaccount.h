#ifndef BANKACCOUNT_H
#define	BANKACCOUNT_H

#include <string>
using std::string;

typedef struct {
   long accno;
   char customer[20];
   double balance;
} BankAccount;

BankAccount* new_account();
BankAccount* new_account(const char* customer, double ini_balance);
void del_account(BankAccount* ba);
void deposit(BankAccount* ba, double amount);
void withdraw(BankAccount* ba, double amount);
string ba_string(BankAccount* t);

#endif	/* BANKACCOUNT_H */