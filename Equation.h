#pragma once
#include "stdafx.h" 

using namespace std;
namespace yrov{
#define TwoPi 6.28318530717958648 
const double eps = 1e-14;

struct Cof {
	double a, b, c, d;
};

class Equation {//�������� ���� �+�=0 
protected:
	double a;
public:
	Equation();
	Equation(double a);
	~Equation();
	virtual void Solve();
};
class Equation2 :public Equation {//���������� ���� �^2+a*x+b=0 
protected:
	double b;
public:
	Equation2();
	Equation2(double a, double b);
	~Equation2();
	virtual void Solve();
};
class Equation3 :public Equation2 {//���������� ���� x^3+a*x^2+b*x+c=0 
private:
	double c;
public:
	Equation3();
	Equation3(double a, double b, double c);
	~Equation3();
	virtual void Solve();
};

void CoofAndResh(string equation);

}