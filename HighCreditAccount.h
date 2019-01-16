
#ifndef HIGH_CREDIT_ACCOUNT_H__
#define HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "CommonHeader.h"
#include "String.h"

class HighCreditAccout :public NormalAccount {

private:
	int CreditClass;
public:
	/*HighCreditAccout(char* ID, int money, char * name, int _interestRate, int _CreditClass) :NormalAccount(ID, money, name, _interestRate) {
		CreditClass = _CreditClass;

	}*/

	HighCreditAccout(String ID, double money, String name, double _interestRate, int _CreditClass) :NormalAccount(ID, money, name, _interestRate) {
		CreditClass = _CreditClass;

	}
	void ShowAccInfo() const {
		NormalAccount::ShowAccInfo();
		cout << "신용 등급 : " << char(CreditClass + 'A') << endl;

	}
	virtual void Deposit(double money) {

		if (money < 0.0) {
			throw MinusException(money);
		}
		NormalAccount::Deposit(money);

		if (CreditClass == 1) {
			Account::Deposit(money*(7 / 100));
		}
		else if (CreditClass == 2) {
			Account::Deposit(money*(4 / 100));
		}
		else if (CreditClass == 3) {
			Account::Deposit(money*(2 / 100));
		}

	}

};

#endif
