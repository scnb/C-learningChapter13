// 13-14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "dma.h"
#include <iostream>


int main()
{
	using std::cout;
	using std::endl;
	baseDMA shirt("Portabelly", 8);
	lacksDMA ballon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "显示基类对象：\n";
	cout << shirt << endl;
	cout << "显示lacksDMA类对象：\n";
	cout << ballon << endl;
	cout << "显示hasDMA类对象：\n";
	cout << map << endl;
	lacksDMA ballon2(ballon);//调用复制构造函数
	cout << "lacksDMA类对象的复制：\n";
	cout << ballon2 << endl;
	hasDMA map2;
	map2 = map;//调用赋值运算符
	cout << "hasDMA类对象的赋值：\n";
	cout << map2 << endl;
	getchar();
    return 0;
}

