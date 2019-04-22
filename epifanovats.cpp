﻿#include "epifanovats.h"

/**
 * Введение в дисциплину
 */
void epifanovats::lab1()
{
cout<<"Hello World!"<<endl;
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void epifanovats::lab2()
{

double* temp = b;//столбец свободжных членов 
//прямой ход
for (int i = 0, j = 0; (i < N - 1) && (j < N - 1); i++, j++)
{
int cur = i;
double max = A[j][j];
for (int num = j; num < N; num++)
if (abs(max) < abs(A[num][j])) max = A[num][j];

while (A[i][j] != max)
i++;

if (cur != i)
{
swap(temp[cur], temp[i]);
swap(A[cur], A[i]);
i = cur;
}
//обратный элемент нашему 
double t = 1/A[i][j];
temp[i] *= t;
for (int cj = j; cj < N; cj++)//строка
A[i][cj] *= t;

for (int ci = i + 1; ci < N; ci++)
{
temp[ci] += temp[i] * (-A[ci][j]);
t = -A[ci][j];
for (int cj = j; cj < N; cj++)
{
A[ci][cj] += A[i][cj] * t;
}
}
}
//обратный ход
for (int i = N - 1, j = N - 1; (i > 0) && (j > 0); i--, j--)
{
int cur = i;
temp[i] *= 1 / A[i][j];
A[i][j] *= 1 / A[i][j];
for (int ci = i - 1; ci >= 0; ci--)
{
temp[ci] += temp[i] * (-A[ci][j]);
A[ci][j] = 0;
}
}

x = temp;
}



/**
 * Метод прогонки
 */
void epifanovats::lab3()
{
int n1=n-1;
double *alfa = new double[N];
double *beta = new double[N];
double y = A[0][0];
alfa[0] = -A[0][1] / y;
beta[0] = b[0] / y;
for (int i = 1; i < n1; i++) {
y = A[i][i] + A[i][i - 1] * alfa[i - 1];
alfa[i] = -A[i][i + 1] / y;
beta[i] = (b[i] - A[i][i - 1] * beta[i - 1]) / y;
}

x[n1] = (b[n1] - A[n1][n1-1] * beta[n1-1]) / (A[n1][n1] + A[n1][n1-1] * alfa[n1-1]);
for (int i = n1-1; i >= 0; i--) {
x[i] = alfa[i] * x[i + 1] + beta[i];
}
}



/**
 * Метод простых итераций
 */
void epifanovats::lab4()
{

}



/**
 * Метод Якоби или Зейделя
 */
void epifanovats::lab5()
{

}



/**
 * Метод минимальных невязок
 */
void epifanovats::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void epifanovats::lab7()
{

}


void epifanovats::lab8()
{

}


void epifanovats::lab9()
{

}


std::string epifanovats::get_name()
{
  return "Epifanova Tatiana Sergeevna";
}
