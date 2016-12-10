#include "stdafx.h" 
#include "Equation.h"
#include "HTMLtags.h"

using namespace std;

HANDLE hConsole;

class Menu{
#define UP_ARROW 72
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77

static void gotoxy(int x, int y)
{
	COORD cursorLoc;
	cursorLoc.X = x;
	cursorLoc.Y = y;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}
static int Drow(){
	system("CLS");
	gotoxy(10, 0);
	cout << "MathHelper";
	gotoxy(1, 1);
	cout << "Solve Equation";
	gotoxy(1, 2);
	cout << "HTML-tags test";
	gotoxy(1, 3);
	cout << "EXIT";
	int i = 1;
	int KeyStroke;
	gotoxy(0, i);
	cout << '>';
	do
	{
		KeyStroke = _gettch();
		gotoxy(0, i);
		cout << ' ';
		switch (KeyStroke)
		{
		case UP_ARROW:
			if (i == 1)
				i = 3;
			else
				i--;
			break;
		case DOWN_ARROW:
			if (i == 3)
				i = 1;
			else
				i++;
			break;
		}
		gotoxy(0, i);
		cout << '>';
	} while (KeyStroke != VK_RETURN);
	return i;
}
static void SolveEquations(){
	system("cls");
	cout<<"Любая другая клавиша) Вернутса в меню\n1) Решыть уровнение\n2) Извлечь квадратный корень из числа\n3) Вознести в степень\n4) Перевести дробь в десятичную\n";
	string urov;
	double m=0,d=0;
	switch (_gettch()){
		case 48:
			break;
		case 49:
			system("cls");
			cout << "Введите уровнение 1-3 степени\nВ формате f(x)=0 (Перенесите все члены уровнения перед знак \"=\")\nТолько действительные числа!\n(Для приведения коефицыентов к действительным\nрекомендуется использовать функцыи в предыдущем меню)\n";
			cin >> urov;
			yrov::CoofAndResh(urov);
			cout << "Нажмите любую другую клавишу для решения следующего уровнения." << endl;
			cout << endl << "Нажмите пробел для возврата в меню." << endl;
			while (_gettch() != ' ') {
				cout << "Введите уровнение:";
				cin >> urov;
				yrov::CoofAndResh(urov);
			}
			break;
		case 50:
			system("cls");
			cout<<"Введите число: ";
			if(cin>>m){
			cout<<"\nКорень "<<m<<" = "<<sqrt(m)<<endl;
			}else {cout<<"НЕКОРЕКТНО!"<<endl; _gettch(); exit(0);}
			_gettch();
			break;
		case 51:
			system("cls");
			cout<<"Введите число: ";
			if(cin>>m){
			cout<<"Введите степень: ";
			if(cin>>d){
			cout<<endl<<m<<"^"<<d<<" = "<<pow(m,d)<<endl;
			}else {cout<<"НЕКОРЕКТНО!"<<endl; _gettch(); exit(0);}
			}else {cout<<"НЕКОРЕКТНО!"<<endl; _gettch(); exit(0);}
			_gettch();
			break;
			m=0;
			d=0;
			urov.clear();
			_gettch();
			break;
		case 52:
			system("cls");
			cout<<"Введите числитель: ";
			if(cin>>m){
			cout<<"Введите знаменатель: ";
			if(cin>>d){
			if(d){
			cout<<endl<<m<<"/"<<d<<" = "<<m/d<<endl;
			}else cout<<"Деление на ноль!"<<endl;
			}else {cout<<"НЕКОРЕКТНО!"<<endl; exit(0);}
			}else {cout<<"НЕКОРЕКТНО!"<<endl; exit(0);}
			_gettch();
			break;
			m=0;
			d=0;
			urov.clear();
		}
}
static void HTMLTEST(){
		system("cls");
		string adres;
		cout << "Введите полный адрес файла(.txt) для проверки: " << endl;
		cin >> adres;
		tags::pairedtags::TagsTest(adres);
}
public:
static void MENU()
{
	
	setlocale(LC_ALL, "Russian");
	system("cls");
	switch (Drow())
	{
	case 1:
		SolveEquations();
		break;
	case 2:
		HTMLTEST();
		break;
	case 3:
		exit(0);
	}
}
};

int main()
{
	while(true){
		Menu::MENU();
	}
	return 0;
}