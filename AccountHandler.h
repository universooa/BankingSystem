#ifndef ACCOUNT_HANDLER_H__
#define ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler {

private:

	int accNum;
	BoundCheckArray<Account*> accArr;
public:

	AccountHandler();

	void ShowMenu() const;
	void MakeAccount();

	void DepositMoney();

	void WithdrawMoney(); 
	
	void ShowAllAccInfo() const;

	~AccountHandler();


};

#endif // !ACCOUNT_HANDLER_H__
