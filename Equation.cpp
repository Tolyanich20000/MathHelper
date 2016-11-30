#include "stdafx.h"
#include "Equation.h"
using namespace yrov;
Equation::Equation(double a) { this->a = a; };
Equation::Equation(){};
Equation::~Equation(){};
void Equation::Solve() {
		cout << "Корень " << -a;
	};

Equation2::Equation2(double a, double b) { this->a = a; this->b = b; };
Equation2::Equation2(){};
Equation2::~Equation2(){};
void Equation2::Solve() {
		if ((a*a - 4 * b) >= 0) {
			cout << "Первый корень = " << (-1 * a + sqrt(a*a - 4 * b)) / 2 << endl;
			cout << "Второй корень = " << (-1 * a - sqrt(a*a - 4 * b)) / 2 << endl;
		}
		else {
			cout << "Дискриминант меньше 0, корни невещественные." << endl;
		}
	};

Equation3::Equation3(double a, double b, double c) { this->a = a; this->b = b; this->c = c; };
Equation3::Equation3(){};
Equation3::~Equation3(){};
void Equation3::Solve() {
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

void CoofAndResh(string equation) {
	int g = 0,oblom=0;
	Cof abc;
	abc.a = 0;
	abc.b = 0;
	abc.c = 0;
	abc.d = 0;
	unsigned int L=equation.size();
	for(g=0;g<L;g++)
		if(equation[g]=='=' && equation[L-1]!='0' && equation[L-2]!='='){
			cout<<"Перенесите все члены уровнения перед знак \"=\"\n";
			system("Pause");
			exit(0);
		}
		else if(equation[L-1]=='0' && equation[L-2]=='=')
			L-=2;
	
	
	g=0;
	while (g < L) {
		if (equation[g] <= '9' && equation[g] >= '0') {
			bool dot = false;
			int dotstep = 0;
			double coof = equation[g] - 48;
			if (g > 0 && equation[g - 1] == '-')
				coof = -coof;
				g++;
			if (equation[g] == '.')
			{
				g++;
				dot = true;
			}
			while (equation[g] <= '9' && equation[g] >= '0' && g < L) {
				if (dot == false && coof>=0)
					coof = coof * 10 + (int)(equation[g] - 48);
				else if(coof>=0){
					dotstep++;
					coof = coof + (int)(equation[g] - 48) / pow(10., dotstep);//Округливает?!?!?
				}
				if (dot == false && coof<0)
					coof = coof * 10 - (int)(equation[g] - 48);
				else if(coof<0) {
					dotstep++;
					coof = coof - (int)(equation[g] - 48) / pow(10., dotstep);//Округливает?!?!?
				}
				g++;
				if (equation[g] == '.')
				{
					g++;
					dot = true;
				}
			}
			if(equation[g]=='*')
				g++;
			if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '3') {
				abc.a += coof;
				g += 3;
			}
			else if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '2') {
				abc.b += coof;
				g += 3;
			}
			else if (equation[g] == 'x') {
				abc.c += coof;
				g++;
			}
			else
				abc.d += coof;
		}
		if (equation[g] == '+'){
			g++;
			if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '3') {
				abc.a ++;
				g += 3;
			}
			else if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '2') {
				abc.b ++;
				g += 3;
			}
			else if (equation[g] == 'x') {
				abc.c ++;
				g++;
			}
		}
		else if(equation[g]=='-'){
			g++;
			if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '3') {
				abc.a --;
				g += 3;
			}
			else if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '2') {
				abc.b --;
				g += 3;
			}
			else if (equation[g] == 'x') {
				abc.c --;
				g++;
			}
		}
		else{
			if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '3') {
				abc.a ++;
				g += 3;
			}
			else if (equation[g] == 'x' && equation[g + 1] == '^' && equation[g + 2] == '2') {
				abc.b ++;
				g += 3;
			}
			else if (equation[g] == 'x') {
				abc.c ++;
				g++;
			}
			}
		oblom++;
		if (oblom > L) {
			cout << "Уровнение НЕКОРЕКТНО!"<<endl;
			cout << "Программа самозакроется через " << 5 << " Секунд!" <<endl;
			for (int s = 4; s >= 0; s--) {
				Sleep(1000);
				cout << "Программа самозакроется через " << s << " Секунд!" <<endl;
			}
			exit(0);

		}
	}
	//cout << endl <<"a="<< abc.a << endl << "b=" << abc.b << endl << "c=" << abc.c<<endl<< "d="<< abc.d << endl;
	if (abc.a == 0 && abc.b==0) {
		cout<<endl<<equation<<" - Линейное уровнение\n\n";
		if(abc.c!=0){
		Equation ur(abc.d/abc.c);
		ur.Solve();
		}
		else cout<<"Х-Любое число\n";
	}
	else if (abc.a==0) {
		cout<<endl<<equation<<" - Квадратное уровнение\n\n";
		Equation2 ur(abc.c/abc.b, abc.d / abc.b);
		ur.Solve();
	}
	else {
		cout<<endl<<equation<<" - Кубическое уровнение\n\n";
		Equation3 ur(abc.b/abc.a, abc.c/abc.a, abc.d/abc.a);
		ur.Solve();
	}
}
