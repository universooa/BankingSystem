#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class ExceptionHandler {
public :
	virtual void ShowExceptionInfo()const = 0;//순수가상함수
};

class MinusException:public ExceptionHandler {
private:
	double exval;

public:
	MinusException(double val):exval(val){}
	void ShowExceptionInfo(void)const {
		cout << "입(출)금액" << exval << "은 유효하지 않습니다!" << endl;
	}
};

class InsuffException:public ExceptionHandler {
private:
	double balance;
	double reqval;
public:
	InsuffException(double val, double req):balance(val),reqval(req){}
	void ShowExceptionInfo() const {
		cout << "잔액에서 " << reqval - balance << "가(이) 부족합니다!" << endl;
	}
};

#endif