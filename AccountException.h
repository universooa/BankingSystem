#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class ExceptionHandler {
public :
	virtual void ShowExceptionInfo()const = 0;//���������Լ�
};

class MinusException:public ExceptionHandler {
private:
	double exval;

public:
	MinusException(double val):exval(val){}
	void ShowExceptionInfo(void)const {
		cout << "��(��)�ݾ�" << exval << "�� ��ȿ���� �ʽ��ϴ�!" << endl;
	}
};

class InsuffException:public ExceptionHandler {
private:
	double balance;
	double reqval;
public:
	InsuffException(double val, double req):balance(val),reqval(req){}
	void ShowExceptionInfo() const {
		cout << "�ܾ׿��� " << reqval - balance << "��(��) �����մϴ�!" << endl;
	}
};

#endif