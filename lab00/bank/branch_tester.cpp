#include <stdio.h>
#include <string.h>
#include <string>
#include "branch.h"

extern short NACC;
extern BankAccount* accounts[];

int main(int argc, char **argv) {

	
	init_branch();

	long accno1 = open_account("Sanjay", 10000);
	long accno2 = open_account("Pankaj", 1000);
	long accno3 = open_account("Arnav", 5000);
	long accno4 = open_account("Sanjay", 3000);

	//Now suppose you want to depsoit 3000 to 
	//   accno 1003.
	BankAccount* acc = find_account( 1003 );
	deposit(acc, 3000);
	//Show new balance of the account
	printf("Account: %s\n", ba_string(acc).c_str());
	
	//1001
	acc = find_account( 1001 );
	withdraw(acc, 3000);	
	printf("Account: %s\n", ba_string(acc).c_str());

	//1002
	close_account( 1002 );
	acc = find_account( 1002 );
	if (acc == NULL)
		printf("Account 1002 Closed\n");
	else
		printf("Account: %s\n", ba_string(acc).c_str());
	
	//List All accounts
	for (int i=0; i < NACC; i++ ) {
		acc = accounts[i];
		if (acc != NULL)
			printf("Account: %s\n", ba_string(acc).c_str());		
	} 

	close_branch();
	
	return 0;

}
