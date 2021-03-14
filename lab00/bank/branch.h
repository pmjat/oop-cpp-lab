#include <stdio.h>
#include <string.h>
#include <string>
#include "bankaccount.h"
using std::string;

void init_branch();
void close_branch();
long open_account(string customer, double ini_balance);
void close_account(long accno);
BankAccount* find_account(long accno);
double get_balance(long accno);