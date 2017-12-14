#include "stdafx.h"
#include "acctabc.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;
using std::string;

//抽象基类型
AcctABC::AcctABC(const string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
	{
		cout << "Deposit can't be negative.\n";
	}
	else
	{
		balance += amt;
	}
}

void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

//用于设置格式的保护方法
AcctABC::Formatting AcctABC::SetFormat()const
{
	//set up ###.##格式
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting & f)const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}

//Brass类的方法
void Brass::Withdraw(double amt)
{
	if (amt < 0)
	{
		cout << "Withdraw amount must be positive; withdraw cancelled.\n";
	}
	else if (amt <= Balance())
	{
		AcctABC::Withdraw(amt);
	}
	else
	{
		cout << "Withdraw amount of $ " << amt << " exceeds your balance.\n" << "Withdraw cancelled.\n";
	}
}

void Brass::ViewAcct()const
{
	Formatting f = SetFormat();
	cout << "Brass client:" << FullName() << endl;
	cout << "Account number: " << AcctNum() << endl;
	cout << "Balance : $" << Balance() << endl;
	Restore(f);
}

//BrassPlus 类方法
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) :AcctABC(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) :AcctABC(ba)
{
	maxLoan = ml;
	owesBank = 0;
	rate = r;
}

void BrassPlus::ViewAcct()const
{
	Formatting f = SetFormat();
	cout << "BrassPlus Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << "%\n";
	Restore(f);
}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();
	double bal = Balance();
	if (amt <= bal)
	{
		AcctABC::Withdraw(amt);
	}
	else if (amt <= bal +maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
	{
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	}
	Restore(f);
}