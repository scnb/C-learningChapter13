// 13-7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "brass.h"
#include <iostream>

int main()
{
	using std::cout;
	using std::endl;
	Brass Piggy("Porcelot Pigg", 381299, 4000);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Hogg Account:\n";
	Hoggy.Deposit(1000);
	cout << "New balance: $" << Hoggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Pigg Account:\n";
	Piggy.Withdraw(4200);
	cout << "Piggy account balance: $" << Piggy.Balance() << endl;
	cout << "Withdrawing $4200 from the Hoggy Account:\n";
	Hoggy.Withdraw(4200);
	Hoggy.ViewAcct();
	getchar();
    return 0;
}

