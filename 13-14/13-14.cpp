// 13-14.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "��ʾ�������\n";
	cout << shirt << endl;
	cout << "��ʾlacksDMA�����\n";
	cout << ballon << endl;
	cout << "��ʾhasDMA�����\n";
	cout << map << endl;
	lacksDMA ballon2(ballon);//���ø��ƹ��캯��
	cout << "lacksDMA�����ĸ��ƣ�\n";
	cout << ballon2 << endl;
	hasDMA map2;
	map2 = map;//���ø�ֵ�����
	cout << "hasDMA�����ĸ�ֵ��\n";
	cout << map2 << endl;
	getchar();
    return 0;
}

