#include "AccountHandler.h"
#include "CommonHeader.h"

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

AccountHandler::AccountHandler():accNum(0) {
}

void AccountHandler::ShowMenu() const {
	cout << "-----------Menu--------" << endl;
	cout << "기능 1. 계좌개설" << endl;
	cout << "기능 2. 입금" << endl;
	cout << "기능 3. 출금" << endl;
	cout << "기능 4. 전체고객 잔액조회" << endl;
	cout << "기능 5. 프로그램 종료" << endl;
}
void AccountHandler::DepositMoney() {
	double money;
	char id[100];

	cout << "[입금]" << endl;

	cout << "계좌 ID:";
	cin >> id;

	while (true) {
		cout << "입금액: ";
		cin >> money;

		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->GetAccID() == id) {
					accArr[i]->Deposit(money);
					cout << "입금완료" << endl << endl;
					return;
				}
			}
			cout << "유효하지 않은 ID" << endl << endl;
			return;
		}
		catch (ExceptionHandler& expt) {
			expt.ShowExceptionInfo();
			cout << "입금액만 재 입력하세요" << endl;
		}
	}
}

void AccountHandler::WithdrawMoney() {
	double money;
	char id[100];
	cout << "[ 출 금 ] " << endl;

	cout << "계좌ID: ";
	cin >> id;

	while (true) {
		cout << "출금액: "; cin >> money;

		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->GetAccID() == id) {
					if (accArr[i]->withdraw(money) == 0) {
						cout << "잔액부족" << endl;
						return;

					}
					cout << "출금완료" << endl << endl;
					return;
				}
			}
			cout << "유효하지 않은 ID입니다" << endl << endl;
			return;
		}
		catch (ExceptionHandler& expt) {
			expt.ShowExceptionInfo();
			cout << "출금액만 재 입력하세요" << endl;
		}
	}

}


void AccountHandler::MakeAccount() {
	//char id[100];
	//char name[NAME_LEN];
	String id;
	String name;
	double balance;
	double interestRate = 0.0;

	cout << "[계좌 종류 선택]" << endl;
	cout << "1. 보통 예금 계좌 2. 신용 신뢰 계좌" << endl;

	int choosenNumber = 0;
	cin >> choosenNumber;

	if (choosenNumber == 1) {

		cout << "[보통 예금 계좌개설]";
		cout << "계좌ID:";
		cin >> id;
		cout << "이름:";
		cin >> name;
		cout << "입금액:";
		cin >> balance;
		cout << "이자율:";
		cin >> interestRate;
		cout << endl;

		accArr[accNum++] = new NormalAccount(id, balance, name, interestRate);

	}
	else if (choosenNumber == 2) {

		int CreditClass = 0;

		cout << "[신용 신뢰 계좌개설]";
		cout << "계좌ID:";
		cin >> id;
		cout << "이름:";
		cin >> name;
		cout << "입금액:";
		cin >> balance;
		cout << "이자율:";
		cin >> interestRate;
		cout << "신용 등급(1toA,2toB,3toC):";
		cin >> CreditClass;
		cout << endl;

		accArr[accNum++] = new HighCreditAccout(id, balance, name, interestRate, CreditClass);

	}

}


void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}


AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete accArr[i];
	}
}
