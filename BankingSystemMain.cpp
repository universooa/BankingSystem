#include "CommonHeader.h"
#include "AccountHandler.h"

int main() {

	int choosenNumber = 0;
	AccountHandler acHandler;

	while (1) {
		acHandler.ShowMenu();
		cout << "선택: (숫자로)";

		cin >> choosenNumber;
		cout << endl;

		switch (choosenNumber) {
		case MAKE:
			acHandler.MakeAccount();
			break;

		case DEPOSIT:
			acHandler.DepositMoney();
			break;
		case WITHDRAW:
			acHandler.WithdrawMoney();
			break;
		case INQUIRE:
			acHandler.ShowAllAccInfo();
			break;
		case EXIT:

			return 0;

		default:
			cout << "Illegal selection" << endl;
		}
	}
	return 0;
}


