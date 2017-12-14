#include "stdafx.h"
#include "brass.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//有关格式的操作和函数
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass 的方法定义
Brass::Brass(const string & s, long an, double bal)
{
	fullname = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)//存款
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
	//设置###.##格式
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
	//设置成###.##格式
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullname << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);//存储原始格式
}

//BrassPlus 方法定义
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

//在BrassPlus类中重新定义ViewAcct()函数
void BrassPlus::ViewAcct()const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();//显示基类部分的数据成员
	cout << "Maxium Loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate: " << 100 * rate << "%\n";
	restore(initialState, prec);
}

//在BrassPlus类中重新定义Withdraw()函数
void BrassPlus::Withdraw(double amt)
{
	//设置成###.##格式
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = Balance();
	if (amt <= bal)
	{
		Brass::Withdraw(amt);
	}
	else if (amt <= bal + maxLoan - owesBank)//这种情况下就是要取得钱比存款多，但是比存款加透支上限少
	{
		double advance = amt - bal;//透支的部分
		owesBank += advance*(1.0 + rate);//欠银行的钱，本金加利息
		cout << "Bank advance: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);//先把透支的部分存进去，才能取出来
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
	//设置成###.##格式
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}