// 13-1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "tabtenn.h"
#include <iostream>
#include <string>


int main()
{
	using std::cout;
	TableTennisPlayer player1("Chuck","Blizzerd", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
	{
		cout << " : has a table.\n";
	}
	else
	{
		cout << " : hasn't a table.\n";
	}
	player2.Name();
	if (player2.HasTable())
	{
		cout << " : has a table.\n";
	}
	else
	{
		cout << " : hasn't a table.\n";
	}
	getchar();
    return 0;
}

