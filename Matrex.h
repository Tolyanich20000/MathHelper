#pragma once
#include "stdafx.h"

using namespace std;
 
class Matrex{
    int **mtx;   //здеь хранится матрица
    int size;    //здесь хранится размер матрицы
public:
    //конструкторы
    Matrex(char type ,int size);
    Matrex(){};
 
    //арифметические операции над матрицами
    Matrex Add(Matrex ob);        
    Matrex Sub(Matrex ob);        
    Matrex Mul(Matrex ob);        
 
    //дополнительные операции над матрицами
    int SumDiagElements();
    int SumAllElements();
 
    //функции доступа
    int GetSize(){ return size; }
    void SetVal(int i, int j, int val) {
        mtx[i][j] = val;
    }
    int GetVal(int i, int j){ return mtx[i][j]; }
 
    //проверяет является ли индекс допустимым
    bool isValidIndex(int x){ 
        if(x < 0 || x > size - 1) return false;
        return true;
    }
};
bool CorrectElem(Matrex &ob);
void ShowMatrex(Matrex &ob);
void FillMatrex(char &ch);
void Mat();
