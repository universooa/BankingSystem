#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "String.h"

class Account {

private:
	//char* AccountsID;
	//char* CustomerName;
	String AccountsID;
	String CustomerName;

	double AccountBalance;

public:
	//Account(char* ID, int money, char * name);
	Account(String ID, double money, String name);

	//Account(const Account & copy);
	//Account& operator=(const Account&ref);

	String GetAccID();

	virtual void Deposit(double money);

	double withdraw(double money);
	void ShowAccInfo() const;

	// virtual ~Account();

};

#endif // !ACCOUNT_H
