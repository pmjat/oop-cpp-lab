#include <stdio.h>
#include <math.h>
#include <string.h>
#include "bankaccount.h"

static long next_accno = 1000;

BankAccount* new_account() {
	BankAccount* ba = (BankAccount *) malloc(sizeof(BankAccount) );
	ba->accno = ++next_accno;
	strcpy(ba->customer, "No Name");
	ba->balance = 0;
	return ba;
}

BankAccount* new_account(const char* customer, double ini_balance) {
    BankAccount* ba = (BankAccount *) malloc(sizeof(BankAccount) );
	ba->accno = ++next_accno;
	strncpy(ba->customer, customer, 19);
	ba->balance = ini_balance;
	return ba;
}

void del_account(BankAccount* ba) {
	free(ba);	
}

void deposit(BankAccount* ba, double amount) {
	double newBalance = ba->balance + amount;
	ba->balance = newBalance;
}

void withdraw(BankAccount* ba, double amount) {
	double newBalance = ba->balance - amount;
	ba->balance = newBalance;
}

string ba_string(BankAccount* ba) {
	char buffer[100];
    sprintf(buffer, "BankAccount(Acc No: %ld, Customer: %s, Balance: %6.2lf)",
		ba->accno, ba->customer, ba->balance);
    return buffer;
}