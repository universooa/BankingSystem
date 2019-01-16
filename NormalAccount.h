
#ifndef NORMAL_ACCOUNT_H__
#define NORMAL_ACCOUNT_H__

#include "Account.h"
#include "CommonHeader.h"
#include "String.h"
#include "AccountException.h"
class NormalAccount :public Account {

private: double interestRate;
public:
	/*NormalAccount(char* ID, int money, char * name, int _interestRate) :Account(ID, money, name) {
		interestRate = _interestRate;
	}*/
	NormalAccount(String ID, double money, String name, double _interestRate) :Account(ID, money, name) {
		interestRate = _interestRate;
	}

	void ShowAccInfo() const {
		Account::ShowAccInfo();
		cout << "ÀÌÀÚÀ² : " << interestRate << endl;

	}
	double GetInterestRate() {
		return interestRate;
	}
	virtual void Deposit(double money) {
		if (money < 0.0) {
			throw MinusException(money);
		}
		Account::Deposit(money);
		Account::Deposit(money*(interestRate / 100.0));
	}
};


#endif // !NORMAL_ACCOUNT_H__
