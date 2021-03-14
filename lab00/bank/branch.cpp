#include "branch.h"

static const short NMAX = 20;
short NACC = 0;
BankAccount* accounts[NMAX];
static long ACCNO_BASE = 1000;

void init_branch() {	
	for(int i=0; i < NMAX; i++)
		accounts[i] = NULL;
}

void close_branch() {
	for(int i=0; i < NACC; i++) {
		if (accounts[i] != NULL)
			free(accounts[i]);
		accounts[i] = NULL;
	}	
}

long open_account(string customer, double ini_balance) {
	BankAccount* ba = new_account(customer.c_str(), ini_balance);
	accounts[NACC++] = ba;
	return ba->accno;
}

void close_account(long accno) {
	int n = accno - ACCNO_BASE - 1;
	free(accounts[n]);
	accounts[n] = NULL;
}

BankAccount* find_account(long accno) {
	return accounts[accno - ACCNO_BASE - 1];
}

double get_balance(long accno) {
	return (accounts[accno - ACCNO_BASE] - 1)->balance;
}

