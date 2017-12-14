#include "stdafx.h"
#include "brass.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//�йظ�ʽ�Ĳ����ͺ���
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass �ķ�������
Brass::Brass(const string & s, long an, double bal)
{
	fullname = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)//���
{
	if (amt < 0)
	{
		cout << "Negative deposit not allowed;" << " deposit is cancelled.\n";
	}
	else
	{
		balance += amt;
	}
}

void Brass::Withdraw(double amt)
{
	//����###.##��ʽ
	format initialState = setFormat();
	precis prec = cout.precision(2);
	if (amt < 0)
	{
		cout << "Withdraw amount must be positive; " << "withdraw cancelled.\n";
	}
	else if (amt <= balance)
	{
		balance -= amt;
	}
	else
	{
		cout << "Withdraw amount of $" << amt << " exceeds your balance.\n" << "Withdrawal cancelled.\n";
	}
	restore(initialState, prec);
}

double Brass::Balance()const
{
	return balance;
}

void Brass::ViewAcct()const
{
	//���ó�###.##��ʽ
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullname << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);//�洢ԭʼ��ʽ
}

//BrassPlus ��������
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) :Brass(ba)
{
	maxLoan = ml;
	owesBank = 0;
	rate = r;
}

//��BrassPlus�������¶���ViewAcct()����
void BrassPlus::ViewAcct()const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();//��ʾ���ಿ�ֵ����ݳ�Ա
	cout << "Maxium Loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << "%\n";
	restore(initialState, prec);
}

//��BrassPlus�������¶���Withdraw()����
void BrassPlus::Withdraw(double amt)
{
	//���ó�###.##��ʽ
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= bal + maxLoan - owesBank)//��������¾���Ҫȡ��Ǯ�ȴ��࣬���Ǳȴ���͸֧������
	{
		double advance = amt - bal;//͸֧�Ĳ���
		owesBank += advance*(1.0 + rate);//Ƿ���е�Ǯ���������Ϣ
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);//�Ȱ�͸֧�Ĳ��ִ��ȥ������ȡ����
		Brass::Withdraw(amt);
	}
	else
	{
		cout << "Credit limit exceeded. Transcation cancelled.\n";
	}
	restore(initialState, prec);
}

format setFormat()
{
	//���ó�###.##��ʽ
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}