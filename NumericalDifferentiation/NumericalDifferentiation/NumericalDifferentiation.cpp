// NumericalDifferentiation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double h = 0.0001;

double F(vector<double> x)
{
	//return x[0] * x[0] + x[1] * x[1];
	return pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2) + pow(x[3], 2);
	//return (x[0] + 2) * (x[0] + 2) + (x[1] + 5) * (x[1] + 5) + (x[2] + 6) * (x[2] + 6) + (x[3] + 10) * (x[3] + 10);
}


vector<double> dF1(vector<double> x)
{
	vector<double> temp(x.size());
	vector<double> temp2(x.size());
	vector<double> res(x.size());

	int n = x.size();
	int i = 0, j = 0;

	for(i=0; i<n; i++)
	{

		for (j = 0; j < n; j++)
		{
			if (j == i)
			{
				temp[j] = x[j] + h;
				temp2[j] = x[j] - h;
			}
			else
			{
				temp[j] = x[j];
				temp2[j] = x[j];
			}
		}
		j = 0;
		res[i] = (F(temp) - F(temp2)) / (2 * h);
	}
	return res;
}

int main()
{
	vector<double> df1;
	vector<double> function;
	int n, i;
	double point;
	cout << "n: ";
	cin >> n;
	cout << "Point: ";
	for (i = 0; i < n; i++)
	{
		cin >> point;
		function.push_back(point);
	}

	df1 = dF1(function);

	for (i = 0; i < n; i++)
	{
		cout << df1[i] << "\t";
	}
	cout << endl;


	return 0;
}

