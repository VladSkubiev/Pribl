#include <iostream>  
#include <math.h>  
#include <windows.h>
#include <iomanip>

using namespace std;

void Out(double* matrix, int i)
{
	for (int j = 0; j < i; j++)
	{
		cout << matrix[j] << " ";
	}
	cout << "\n";
}

double numerator(double X1, double* matrix, int length, int i)  //Вычисляем числитель  
{
	double numer = 1;
	for (int j = 0; j < length; j++)
	{
		if (j != i)
		{
			numer = numer * (X1 - matrix[j]);
		}
	}
	return numer;
}

double Denominator(double* matrix,  int i, int length)
{
	double  Denom = 1;
	for (int j = 0; j < length; j++)
	{
		if (j != i)
		{
			Denom = Denom * (matrix[i] - matrix[j]);
		}

	}
	return Denom;
}


int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	long double P = 0;
	double h = 0.1, sum = 0, pr = 1;
	int len = 11, Xj_len = 21;
	double* X = new double[len];
	double* Y = new double[len];
	double* Xj = new double[Xj_len];
	double* Approx = new double[Xj_len];
	double app = 0;
	X[0] = 1;
	for (int j = 0; j < Xj_len; j++)       //
	{
		Approx[j] = 0;
	}

	for (int j = 1; j < len; j++)       //Заполнеиние Х 
	{
		X[j] = X[j - 1] + 0.1;
	}
	cout << "X" << "\n";
	Out(X, len);

	for (int j = 0; j < len; j++)       //Заполнение Y 
	{
		Y[j] = X[j] * X[j];
		Y[j] = X[j] * log(X[j]);
	}
	cout << "Y" << "\n";
	Out(Y, len);

	for (int j = 0; j < Xj_len; j++)      //Заполнеиние Хj 
	{
		Xj[j] = 1 + j * (h / 2);
	}
	cout << "Xj" << "\n";
	Out(Xj, Xj_len);

	for (int i = 0; i < Xj_len; i++)
	{
		for (int j = 0; j < len; j++)
		{

			Approx[i] +=  Y[j] *(numerator(Xj[i], X, len, j) / Denominator(X, j, len));
			
		}

	}
		for (int i = 0; i < len - 1 ; i++)
		{
			pr *= 2 - X[i];
		
		}
		cout << "pr:" << "\n" << pr << "\n";
		P = 362880. / pow(2,10) / 39916800 * pr ;
	cout << "Значения полинома:" << "\n";
	Out(Approx, Xj_len);
	cout << "Погрешность равна:" << "\n" << setprecision(20) << P << "\n";
}