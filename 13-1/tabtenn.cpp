#include "stdafx.h"
#include "tabtenn.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht)
{
	//该构造函数使用了成员初始化列表语法
}

void TableTennisPlayer::Name()const
{
	std::cout << lastname << ", " << firstname;
}