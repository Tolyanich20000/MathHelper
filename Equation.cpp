#include "stdafx.h" 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <windows.h>
using namespace std;

#define TwoPi 6.28318530717958648 
const double eps = 1e-14;

struct Cof {
	double a, b, c, d;
};

class Equation {//линейные вида х+а=0 
protected:
	double a;
public:
	Equation() {};
	Equation(double a) { this->a = a; };
	~Equation() {};
	virtual void Solve() {
		cout << "Корень " << -a;
	};
};
class Equation2 :public Equation {//квадратные вида х^2+a*x+b=0 
protected:
	double b;
public:
	Equation2() {};
	Equation2(double a, double b) { this->a = a; this->b = b; };
	~Equation2() {};
	virtual void Solve() {
		if ((a*a - 4 * b) >= 0) {
			cout << "Первый корень = " << (-1 * a + sqrt(a*a - 4 * b)) / 2 << endl;
			cout << "Второй корень = " << (-1 * a - sqrt(a*a - 4 * b)) / 2 << endl;
		}
		else {
			cout << "Дискриминант меньше 0, корни невещественные." << endl;
		}
	};
};
class Equation3 :public Equation2 {//кубические вида x^3+a*x^2+b*x+c=0 
private:
	double c;
public:
	Equation3() {};
	Equation3(double a, double b, double c) { this->a = a; this->b = b; this->c = c; };
	~Equation3() {};
	virtual void Solve() {
		double a2 = a*a;
		double q = (a2 - 3 * b) / 9;
		double r = (a*(2 * a2 - 9 * b) + 27 * c) / 54;
		double r2 = r*r;
		double q3 = q*q*q;
		double A, B;
		if (r2<q3) {
			double t = r / sqrt(q3);
			if (t<-1) t = -1;
			if (t> 1) t = 1;
			t = acos(t);
			a /= 3; q = -2 * sqrt(q);
			cout << "Первый корень = " << q*cos(t / 3) - a << endl;
			cout << "Второй корень = " << q*cos((t + TwoPi) / 3) - a << endl;
			cout << "Третий корень = " << q*cos((t - TwoPi) / 3) - a << endl;
		}
		else {
			A = -pow(fabs(r) + sqrt(r2 - q3), 1. / 3);
			if (r<0) A = -A;
			B = A == 0 ? 0 : B = q / A;

			a /= 3;
			cout << "Первый корень = " << (A + B) - a << endl;
			cout << "Второй корень = " << -0.5*(A + B) - a << endl;
			cout << "Третий корень = " << 0.5*sqrt(3.)*(A - B) << endl;
		}
	};
};

void CoofAndResh(string equation) {
	int i = 0,oblom=0;
	Cof abc;
	abc.a = 0;
	abc.b = 0;
	abc.c = 0;
	abc.d = 0;
	unsigned int L=equation.size();
	for(i=0;i<L;i++)
		if(equation[i]=='=' && equation[L-1]!='0' && equation[L-2]!='='){
			cout<<"Перенесите все члены уровнения перед знак \"=\"\n";
			system("Pause");
			exit(0);
		}
		else if(equation[L-1]=='0' && equation[L-2]=='=')
			L-=2;
	
	
	i=0;
	while (i < L) {
		if (equation[i] <= '9' && equation[i] >= '0') {
			bool dot = false;
			int dotstep = 0;
			double coof = equation[i] - 48;
			if (i > 0 && equation[i - 1] == '-')
				coof = -coof;
				i++;
			if (equation[i] == '.')
			{
				i++;
				dot = true;
			}
			while (equation[i] <= '9' && equation[i] >= '0' && i < L) {
				if (dot == false && coof>=0)
					coof = coof * 10 + (int)(equation[i] - 48);
				else if(coof>=0){
					dotstep++;
					coof = coof + (int)(equation[i] - 48) / pow(10., dotstep);//Округливает?!?!?
				}
				if (dot == false && coof<0)
					coof = coof * 10 - (int)(equation[i] - 48);
				else if(coof<0) {
					dotstep++;
					coof = coof - (int)(equation[i] - 48) / pow(10., dotstep);//Округливает?!?!?
				}
				i++;
				if (equation[i] == '.')
				{
					i++;
					dot = true;
				}
			}
			if(equation[i]=='*')
				i++;
			if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '3') {
				abc.a += coof;
				i += 3;
			}
			else if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '2') {
				abc.b += coof;
				i += 3;
			}
			else if (equation[i] == 'x') {
				abc.c += coof;
				i++;
			}
			else
				abc.d += coof;
		}
		if (equation[i] == '+'){
			i++;
			if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '3') {
				abc.a ++;
				i += 3;
			}
			else if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '2') {
				abc.b ++;
				i += 3;
			}
			else if (equation[i] == 'x') {
				abc.c ++;
				i++;
			}
		}
		else if(equation[i]=='-'){
			i++;
			if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '3') {
				abc.a --;
				i += 3;
			}
			else if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '2') {
				abc.b --;
				i += 3;
			}
			else if (equation[i] == 'x') {
				abc.c --;
				i++;
			}
		}
		else{
			if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '3') {
				abc.a ++;
				i += 3;
			}
			else if (equation[i] == 'x' && equation[i + 1] == '^' && equation[i + 2] == '2') {
				abc.b ++;
				i += 3;
			}
			else if (equation[i] == 'x') {
				abc.c ++;
				i++;
			}
			}
		oblom++;
		if (oblom > L) {
			cout << "Уровнение некоректно!"<<endl;
			cout << "Программа самозакроется через " << 5 << " Секунд!" <<endl;
			for (int s = 4; s >= 0; s--) {
				Sleep(1000);
				cout << "Программа самозакроется через "<< s << " Секунд!"<<endl;
			}
			exit(0);

		}
	}
	//cout << endl <<"a="<< abc.a << endl << "b=" << abc.b << endl << "c=" << abc.c<<endl<< "d="<< abc.d << endl;
	Equation* ur=NULL;
	if (abc.a == 0 && abc.b==0) {
		cout<<endl<<equation<<" - Линейное уровнение\n\n";
		if(abc.c!=0){
		ur = new Equation(abc.d/abc.c);
		}
		else cout<<"Х-Любое число\n";
	}
	else if (abc.a==0) {
		cout<<endl<<equation<<" - Квадратное уровнение\n\n";
		ur = new Equation2(abc.c/abc.b, abc.d / abc.b);
	}
	else {
		cout<<endl<<equation<<" - Кубическое уровнение\n\n";
		ur = new Equation3(abc.b/abc.a, abc.c/abc.a, abc.d/abc.a);
	}
	ur->Solve();
}
