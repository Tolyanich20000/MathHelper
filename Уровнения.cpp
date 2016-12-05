#include "stdafx.h" 
#include "Equation.h"
#include "HTMLtags.h"

#define UP_ARROW 72
#define LEFT_ARROW 75
#define DOWN_ARROW 80
#define RIGHT_ARROW 77

using namespace std;

HANDLE hConsole;

void gotoxy(int x, int y)
{
	COORD cursorLoc;
	cursorLoc.X = x;
	cursorLoc.Y = y;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, cursorLoc);
}

void MENU()
{
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
	string urov, adres;
	setlocale(LC_ALL, "Russian");
	system("cls");
	double m=0;
	int d=0;
	switch (i)
	{
	case 1:
		cout<<"Любая другая клавиша) Вернутса в меню\n1) Решыть уровнение\n2) Извлечь квадратный корень из числа\n3) Вознести в степень\n";
		switch (_gettch()){
			system("cls");
		case 48:
			break;
		case 49:
			cout << "Введите уровнение 1-3 степени\nВ формате f(x)=0 (Перенесите все члены уровнения перед знак \"=\")\n";
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
			cout<<"Введите число: ";
			cin>>m;
			cout<<"\nКорень "<<m<<" = "<<sqrt(m)<<endl;
			_gettch();
			break;
		case 51:
			cout<<"Введите число: ";
			cin>>m;
			cout<<"Введите степень: ";
			cin>>d;
			cout<<endl<<m<<"^"<<d<<" = "<<pow(m,d)<<endl;
			_gettch();
			break;
		}
		break;
	case 2:
		cout << "Введите полный адрес файла(.txt) для проверки: " << endl;
		cin >> adres;
		tags::pairedtags::TagsTest(adres);
		break;
	case 3:
		exit(0);
	}
}

int main()
{
	while(true){
		MENU();
	}
	return 0;
}
