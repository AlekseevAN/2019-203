﻿#include "dryginaea.h"
#define  eps 0.000001

/**
 * Введение в дисциплину
 */
void dryginaea::lab1()
{
	cout << "Hello world!" << endl;
}



/**
 * Метод Гаусса с выбором главного элемента
 */

void change(double** a, double* b, int* shift, int line1, int line2, int n)
{
	double temp;
	int temp1;

	for (int i = 0; i < n; i++)
	{
		temp = a[line1][i];
		a[line1][i] = a[line2][i];
		a[line2][i] = temp;
	}

	temp = b[line1];
	b[line1] = b[line2];
	b[line2] = temp;

	temp1 = shift[line1];
	shift[line1] = shift[line2];
	shift[line2] = temp1;
}

void dryginaea::lab2()
{
	double diagonal, temp;
	int max;
	int shift[N];

	for (int i = 0; i < N; i++)
	{
		shift[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		max = i;

		for (int l = i; l < N; l++)
		{
			if (abs(A[l][i]) > abs(A[max][i]))
			{
				max = l;
			}
		}

		if (fabs(A[max][i]) > eps)
		{
			change(A, b,shift,i, max, N);
		}

		diagonal = A[i][i];
		A[i][i] = 1;

		for (int j = i + 1; j < N; j++)
		{
			A[i][j] /= diagonal;
		}

		b[i] /= diagonal;

		for (int j = i + 1; j < N; j++)
		{
			temp = A[j][i];
			A[j][i] = 0;

			for (int k = i + 1; k < N; k++)
			{
				A[j][k] -= A[i][k] * temp;
			}

			b[j] -= b[i] * temp;
		}
	}

    for (int i = N - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			temp = A[j][i];

			for (int k = i; k >= 0; k--)
			{
				A[j][k] -= A[i][k] * temp;
			}

			b[j] -= b[i] * temp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		x[shift[i]] = b[i];
	}
}




/**
 * Метод прогонки
 */
void dryginaea::lab3()
{
	double *alfa = new double[N - 1];
	double *betta = new double[N];

	alfa[0] = -A[0][1] / A[0][0];
	betta[0] = b[0] / A[0][0];

	for (int i = 1; i < N - 1; i++)
	{
		alfa[i] = -A[i][i + 1] / (A[i][i] + A[i][i - 1] * alfa[i - 1]);
		betta[i] = (b[i] - A[i][i - 1] * betta[i - 1]) / (A[i][i] + A[i][i - 1] * alfa[i - 1]);
	}

	betta[N - 1] = (b[N - 1] - A[N - 1][N - 2] * betta[N - 2]) / (A[N - 1][N - 1] + A[N - 1][N - 2] * alfa[N - 2]);

	x[N - 1] = betta[N - 1];

	for (int i = N - 2; i >= 0; i--)
	{
		x[i] = alfa[i] * x[i + 1] + betta[i];;
	}
}



/**
 * Метод простых итераций
 */
void Multi(double **matrix1, double *matrix2, double *otvet, int N) //otvet = matrix1 * matrix2
{
	double sum;

	for (int i = 0; i < N; i++)
	{
		sum = 0;

		for (int j = 0; j < N; j++)
		{
			sum += matrix1[i][j] * matrix2[j];
		}

		otvet[i] = sum;
	}
}

void dryginaea::lab4()
{
	double tau = 0.001;
	double *gapX = new double[N];

	for (int i = 0; i < N; i++)
	{
		x[i] = b[i];
	}

	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			gapX[i] = x[i];
		}

		Multi(A, gapX, x, N);

		for (int i = 0; i < N; i++)
		{
			x[i] = gapX[i] + tau * (b[i] - x[i]);
		}

		int k = 0;

		for (int i = 0; i < N; i++)
		{
			if (fabs(x[i] - gapX[i]) < eps)
			{
				k++;
			}
		}
	}
}



/**
 * Метод Якоби или Зейделя
 */
void dryginaea::lab5()
{
    double *gapX = new double[N];
	int k = 0;
	
    for (int i = 0; i < N; i++)
	{
        x[i] = 0;
	}

    do
    {
        for (int i = 0; i < N; i++)
        {
            gapX[i] = b[i];
            for (int j = 0; j < N; j++)
            {
                if (i == j) continue;
                gapX[i] -= A[i][j]*x[j];
            }

            gapX[i] /= A[i][i];
			
            if (fabs(gapX[i] - x[i]) < eps)
			{
			    k++;
			}
			
            x[i] = gapX[i];
        }

    }while(k < N);
}



/**
 * Метод минимальных невязок
 */
void dryginaea::lab6()
{

}



/**
 * Метод сопряженных градиентов
 */
void dryginaea::lab7()
{

}


void dryginaea::lab8()
{

}


void dryginaea::lab9()
{

}


std::string dryginaea::get_name()
{
  return "Drygina E.A.";
}
