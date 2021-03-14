#include <stdio.h>
#include <string.h>
#include "bankaccount.h"

int main(int argc, char **argv) {

	BankAccount* ba1 = new_account();
	strcpy(ba1->customer, "Sunil");
	printf("Account-1: %s\n", ba_string(ba1).c_str());
	BankAccount* ba2 = new_account("Pankaj", 5000);

	deposit(ba1, 3000);
	withdraw(ba2, 1000);

	printf("Account-1: %s\n", ba_string(ba1).c_str());
	printf("Account-2: %s\n", ba_string(ba2).c_str());
	
	del_account(ba1);
	del_account(ba2);

	return 0;
}
