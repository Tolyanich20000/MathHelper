#include "StdAfx.h"
#include "Matrex.h"
//реализация конструктора
Matrex::Matrex(char type,int s){
    int i,j;
 
    if(s < 1) size = 1;
    else if(s > 10) size = 10;
    else size = s;
 
    mtx = new int *[size];
    for(i=0; i<size; i++)
        mtx[i] = new int[size];
 
    switch(type){
    case'0':
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
                mtx[i][j] = 0;
        break;
    case'1':
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
                mtx[i][j] = (i==j)? 1:0;
        break;
    case'r':
        srand(time(NULL));
        for(i=0; i<size; i++)
            for(j=0; j<size; j++)
                mtx[i][j] = rand() % 1000;
        break;
    case'm':
        cout << "\n";
        for(i=0; i<size; i++)
            for(j=0; j<size; j++){
                do{
                    cout << "Введите элемента mtx[" << i << "][" << j << "]: "; 
                    fflush(stdin);
                }while(scanf( "%i",&mtx[i][j])!=1 || cin.rdbuf()->in_avail()!=1);
                mtx[i][j]%=1000;
            }
        break;
    }
}
 
//сумма матриц
Matrex Matrex::Add(Matrex ob){
    Matrex result('0',size);
    int i,j;
 
    for(i=0; i<size;i++)
        for(j=0;j<size;j++)
            result.mtx[i][j] = mtx[i][j] + ob.mtx[i][j];
    
    return result;
}
 
//вычитания матриц
Matrex Matrex::Sub(Matrex ob){
    Matrex result('0',size);
    int i,j;
 
    for(i=0; i<size;i++)
        for(j=0;j<size;j++)
            result.mtx[i][j] = mtx[i][j] - ob.mtx[i][j];
    
    return result;
}
 
//умножение матриц
Matrex Matrex::Mul(Matrex ob){
    Matrex result('0',size);
    int i,j,k;
 
    for(k=0; k<size;k++)
        for(i=0;i<size;i++)
            for(j=0;j<size;j++)
                result.mtx [k][i]= result.mtx[k][i] + mtx[k][j] * ob.mtx[j][i];
            
    return result;
}
 
//сумма всех элментов матрицы
int Matrex::SumAllElements(){
    int result = 0;
    
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            result+=mtx[i][j];
    
    return result;
}
 
//сумма элементов на диагонали
int Matrex::SumDiagElements(){
    int result = 0;
    
    for(int i=0; i<size; i++)
        result+=mtx[i][i];
    
    return result;
}
 
//****************************************************
 
//коректировка элементов матрицы
bool CorrectElem(Matrex &ob){
    int i,j,change_val;
    char ch;
    
    do{
        cout << "Хотите изменить элементы матрицы (0-нет, 1 -да): ";
        fflush(stdin);
    }while(scanf("%c", &ch)!=1 || cin.rdbuf()->in_avail()!=1 || ch!='0' && ch !='1');
 
    if(ch == '0') return false;
 
    do{
        cout <<"Введите номер строки, столбца и новое значение (с,с,з): ";
        fflush(stdin);
    }while(scanf("%i,%i,%i",&i,&j,&change_val)!=3 || cin.rdbuf()->in_avail()!=1 ||
        !ob.isValidIndex(i) || !ob.isValidIndex(j));
 
    ob.SetVal(i, j, change_val % 1000);
    return true;
}
 
//показать матрицу
void ShowMatrex(Matrex &ob){
    int i,j;
    
    for(i=0; i<ob.GetSize(); i++){
        for(j=0; j<ob.GetSize(); j++){
            cout.width(6);
            cout << ob.GetVal(i, j) << ' ';
        }
        cout << "\n";   
    }
    cout << "\n";
}
 
//выбор способа заполнения матрицы
void FillMatrex(char &ch){
    cout << "0-Заполнить нулями.\n"
         << "1-Единичная матрица.\n"
         << "r-Случайная матриц.\n"
         << "m-Ручной ввод элементов.\n";
    do{
        cout << "Выберите один из пунктов: ";
        fflush(stdin);
    }while(scanf("%c",&ch)!=1 || cin.rdbuf()->in_avail()!=1 ||
        ch != '0' && ch != '1' &&ch!='r' && ch!='m');
}
 
void Mat(){
    char ch_fill1;        //способ заполнения 1 матрицы
    char ch_fill2;        //способ заполнения 2 матрицы
    char ch_operations;   //выбор операции
    int size;
 
    setlocale(LC_ALL,"Rus");
    
    for(;;){
        system("cls");
        
        cout   << "1.Сумма матриц.\n"
               << "2.Разность матриц.\n"
               << "3.Умножение матриц.\n"
               << "4.Сумма элементов на диагонали.\n"
               << "5.Сумма всех элементов.\n";
        do{
            cout << "Выберите один из пунктов (0 - для выхода): ";
            fflush(stdin);
        }while(scanf("%c", &ch_operations)!=1 || cin.rdbuf()->in_avail()!=1 ||
            ch_operations < '0' || ch_operations > '5');    
        
        if(ch_operations == '0') break; //если надо, то выходим
 
        //узнаем размер матриц
        do{
            cout << "\nВведите размер матриц: ";
            fflush(stdin);
        }while(scanf("%i", &size)!=1 || cin.rdbuf()->in_avail()!=1);
 
        Matrex result;  //матрица для хранения результата операций
 
        if(ch_operations > '0' && ch_operations < '4'){
            cout << "\nМатрица 1:\n";
            FillMatrex(ch_fill1);       //узнаем способ заполнения 1 матрицы
            Matrex ob(ch_fill1,size);   //создали 1 матрицу
            
            cout << "\n";
 
            //показываем и корректируем матрицу, если надо
            do{
                cout << "Вы ввели матрицу 1:\n";
                ShowMatrex(ob);
            }while(CorrectElem(ob));
    
            cout << "\nМатрица 2:\n";
            FillMatrex(ch_fill2);         //заполнили матрицу 2
            Matrex ob2(ch_fill2,size);    //создали 2 матрицу
            
            cout << "\n";
 
            //показываем и корректируем, если надо 2 матрицу
            do{
                cout << "Вы ввели матрицу 2:\n";
                ShowMatrex(ob2);
            }while(CorrectElem(ob2));
            
            //выполнение операции 1,2 или 3
            switch(ch_operations){
            case'1':
                result = ob.Add(ob2);        
                cout << "Результат сложения:\n";
                ShowMatrex(result);      
                break;
            case'2':
                result = ob.Sub(ob2);          
                cout << "Результат вычитания :\n";
                ShowMatrex(result);
                break;
            case'3':
                result = ob.Mul(ob2);
                cout << "Результат умножения\n";
                ShowMatrex(result);
                break;
            }
        }else if(ch_operations == '4' || ch_operations == '5'){
            cout << "Матрица 1:\n";
            FillMatrex(ch_fill1);        //выбор заполнения матрицы
            Matrex ob(ch_fill1,size);    //создали матрицу
        
            //показываем и корректируем матрицу, если надо
            do{
                cout << "Вы ввели матрицу 1:\n";
                ShowMatrex(ob);
            }while(CorrectElem(ob));
 
            //выполнение операции 4 или 5
            switch(ch_operations){
            case'4':
                cout << "Сумма элементов на диагонали: ";
                cout << ob.SumDiagElements() << "\n";                
                break;
            case'5':
                cout << "Сумма всех элементов: ";
                cout << ob.SumAllElements() << "\n";
                break;
            }
        }
        cout << "Для продолжения нажмите любую кнопку.";
        getch();
    }
}