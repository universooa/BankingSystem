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
	cout << "��� 1. ���°���" << endl;
	cout << "��� 2. �Ա�" << endl;
	cout << "��� 3. ���" << endl;
	cout << "��� 4. ��ü�� �ܾ���ȸ" << endl;
	cout << "��� 5. ���α׷� ����" << endl;
}
void AccountHandler::DepositMoney() {
	double money;
	char id[100];

	cout << "[�Ա�]" << endl;

	cout << "���� ID:";
	cin >> id;

	while (true) {
		cout << "�Աݾ�: ";
		cin >> money;

		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->GetAccID() == id) {
					accArr[i]->Deposit(money);
					cout << "�ԱݿϷ�" << endl << endl;
					return;
				}
			}
			cout << "��ȿ���� ���� ID" << endl << endl;
			return;
		}
		catch (ExceptionHandler& expt) {
			expt.ShowExceptionInfo();
			cout << "�Աݾ׸� �� �Է��ϼ���" << endl;
		}
	}
}

void AccountHandler::WithdrawMoney() {
	double money;
	char id[100];
	cout << "[ �� �� ] " << endl;

	cout << "����ID: ";
	cin >> id;

	while (true) {
		cout << "��ݾ�: "; cin >> money;

		try {
			for (int i = 0; i < accNum; i++) {
				if (accArr[i]->GetAccID() == id) {
					if (accArr[i]->withdraw(money) == 0) {
						cout << "�ܾ׺���" << endl;
						return;

					}
					cout << "��ݿϷ�" << endl << endl;
					return;
				}
			}
			cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
			return;
		}
		catch (ExceptionHandler& expt) {
			expt.ShowExceptionInfo();
			cout << "��ݾ׸� �� �Է��ϼ���" << endl;
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

	cout << "[���� ���� ����]" << endl;
	cout << "1. ���� ���� ���� 2. �ſ� �ŷ� ����" << endl;

	int choosenNumber = 0;
	cin >> choosenNumber;

	if (choosenNumber == 1) {

		cout << "[���� ���� ���°���]";
		cout << "����ID:";
		cin >> id;
		cout << "�̸�:";
		cin >> name;
		cout << "�Աݾ�:";
		cin >> balance;
		cout << "������:";
		cin >> interestRate;
		cout << endl;

		accArr[accNum++] = new NormalAccount(id, balance, name, interestRate);

	}
	else if (choosenNumber == 2) {

		int CreditClass = 0;

		cout << "[�ſ� �ŷ� ���°���]";
		cout << "����ID:";
		cin >> id;
		cout << "�̸�:";
		cin >> name;
		cout << "�Աݾ�:";
		cin >> balance;
		cout << "������:";
		cin >> interestRate;
		cout << "�ſ� ���(1toA,2toB,3toC):";
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
