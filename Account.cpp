#include "Account.h"
#include "CommonHeader.h"
#include "AccountException.h"

/*Account::Account(const Account & copy) :AccountBalance(copy.AccountBalance) {
	AccountsID = new char[strlen(copy.AccountsID) + 1];
	strcpy_s(AccountsID, strlen(copy.AccountsID) + 1, copy.AccountsID);
	CustomerName = new char[strlen(copy.CustomerName) + 1];
	strcpy_s(CustomerName, strlen(copy.CustomerName) + 1, copy.CustomerName);
}*/

String Account::GetAccID() {
	return AccountsID;
}

void Account::Deposit(double money) {
	if (money < 0) {
		throw MinusException(money);
	}
	AccountBalance += money;
}
double Account::withdraw(double money) {
	if (money < 0) {
		throw MinusException(money);
	}
	if (AccountBalance < money) {
		throw InsuffException(AccountBalance,money);
	}
	AccountBalance -= money;
	return money;
}
/*
Account& Account::operator=(const Account& ref) {
	delete[] AccountsID;
	delete[] CustomerName;
	AccountsID= new char[strlen(ref.AccountsID)+1];
	strcpy(AccountsID, ref.AccountsID);

	CustomerName = new char[strlen(ref.CustomerName) + 1];
	strcpy(CustomerName, ref.CustomerName);

	AccountBalance = ref.AccountBalance;

	return *this;

}*/
Account::Account(String ID, double money, String name) :AccountBalance(money) {
	//AccountsID = new char[strlen(ID) + 1];
	//strcpy_s(AccountsID, strlen(ID) + 1, ID);
	//CustomerName = new char[strlen(name) + 1];
	//strcpy_s(CustomerName, strlen(name) + 1, name);
	AccountsID = ID;
	CustomerName = name;
}

void Account::ShowAccInfo() const {
	cout << "°èÁÂ ID: " << AccountsID << endl;
	cout << "ÀÌ¸§: " << CustomerName << endl;
	cout << "ÀÜ¾×: " << AccountBalance << endl;

}

/*
Account::~Account() {
	delete[] AccountsID;
	delete[] CustomerName;
}*/