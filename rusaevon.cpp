﻿#include "rusaevon.h"

/**
 * Введение в дисциплину
 */
void rusaevon::lab1()
{
cout<<"Hello world!";
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void rusaevon::lab2()
{
  double p;
	int maxn;

    for (int k=0; k<N-1; k++)
    {
        maxn = k;
        for (int i=k+1; i<N; i++)
			if(abs(A[i][k]) > abs(A[maxn][k])) maxn = i; 
        std::swap(A[maxn], A[k]); 
        std::swap(b[maxn], b[k]);

        for (int i=k+1; i<N; i++)
        {
            p = A[i][k]/A[k][k];
            for (int j=k; j<N; j++)
                A[i][j] -= p*A[k][j];
            b[i] -= p*b[k];
        }
    }

    for(int i = 0; i<N; i++)
    {
        x[i]=b[i];
    }

    for (int i=N-1; i>=0; i--)
    {
        for (int j=i+1;j<N;j++)
            x[i]-=A[i][j]*x[j];
        x[i] /= A[i][i];
    }
}



/**
 * Метод прогонки
 */
void rusaevon::lab3()
{
double *P = new double [N]; 
	double *Q = new double [N]; 

	P[0] = -A[0][1]/A[0][0];
	Q[0] = b[0]/A[0][0];

	for(int i=1; i<N; i++) 
	{
		P[i] = A[i][i+1]/(-A[i][i] - A[i][i-1]*P[i-1]);
		Q[i] = (-b[i] + A[i][i-1]*Q[i-1])/(-A[i][i] - A[i][i-1]*P[i-1]);
	}

	x[N-1] = Q[N-1];
	for(int i=N-2; i>=0; i--) 
		x[i] = P[i]*x[i+1] + Q[i];

	delete [] P;
	delete [] Q;
}



/**
 * Метод простых итераций
 */
void rusaevon::lab4()
{
double Eps=1e-15;
double Err;
double *nx = new double[N];

for (int i=0;i<N;i++)
	x[i]=b[i];
int step=0;
	
do{
step++;
  for(int i=0;i < N;i++)
  {
   nx[i]=-b[i];
 
   for(int j=0;j < N;j++)
   {
    if(i!=j)
     nx[i]+=A[i][j]*x[j];
   }
 
   nx[i]/=-A[i][i];
  }
  Err=0;
for(int i=0; i<N; i++) { 
if(std::abs(x[i]-nx[i]) > Err)
Err = std::abs(x[i]-nx[i]);
}
for(int i=0; i<N; i++) 
	x[i]=nx[i];
std::cout<<step<<"    "<<Err<<endl;
}while (Err>Eps);

delete[] nx;

}



/**
 * Метод Якоби или Зейделя
 */
void rusaevon::lab5()
{
double *oldx = new double[N]; 

for (int i=0; i<N; i++) { 
x[i]=0; 
} 

double Err=0.0; 
double eps=1e-20; 
int k=0; 

do { 
k++; 
Err=0.0; 
for(int i=0; i<N; i++) 
oldx[i]=x[i]; 
for(int i=0; i<N; i++) 
{ 
double s=0; 
for(int j=0; j<i; j++) 
s += A[i][j] * oldx[j]; 
for(int j=i+1; j<N; j++) 
s += A[i][j] * oldx[j]; 
x[i]=(b[i] - s)/A[i][i]; 
} 
Err= std::abs(oldx[0]-x[0]); 
for(int i=0; i<N; i++) 
{ 
if(std::abs(oldx[i]-x[i]) > Err) 
Err = std::abs(oldx[i]-x[i]);
} 
} while(Err >= eps); 
delete [] oldx; 
}



/**
 * Метод минимальных невязок
 */
void rusaevon::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void rusaevon::lab7()
{

}


void rusaevon::lab8()
{

}


void rusaevon::lab9()
{

}


std::string rusaevon::get_name()
{
  return "Ruzaev O.N.";
}
