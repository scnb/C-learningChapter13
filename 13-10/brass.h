#pragma once
#ifndef BRASS_H_
#define BRASS_H_

#include <string>

class Brass
{
private:
	std::string fullname;
	long acctNum;//�˻�����
	double balance;//�˻����
public:
	Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);//virtual��ʲô,�麯��
	double Balance()const;
	virtual void ViewAcct()const;
	virtual ~Brass() {}
};

//Brass Account Plus Class
class BrassPlus :public Brass
{
private:
	double maxLoan;//͸֧����
	double rate;//����
	double owesBank;//��ǰ͸֧�ܶ�
public:
	BrassPlus(const std::string & s = "NUllbody", long an = -1, double bal = 0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct()const;
	virtual void Withdraw(double amt);
	void  ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif // !BRASS_H_

