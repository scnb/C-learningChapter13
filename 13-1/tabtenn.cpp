#include "stdafx.h"
#include "tabtenn.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht)
{
	//�ù��캯��ʹ���˳�Ա��ʼ���б��﷨
}

void TableTennisPlayer::Name()const
{
	std::cout << lastname << ", " << firstname;
}