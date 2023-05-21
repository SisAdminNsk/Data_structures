#include <iostream>
#include <vector>
using namespace std;
const int n = 10;

int* GenerateArray()
{
	int* linearArray = new int[n];

	for (int i = 0; i < n; i++)
		linearArray[i] = rand() % 100;

	int userSize = 0;
	cout << "Input number less than 10 ==> ";
	cin >> userSize;

	if (userSize < n)
	{

		int stringsCount = 0;

		if (10 % userSize != 0)// проверям кратность, чтобы правильно определить кол-во строк в будущей матрице
			stringsCount = (n / userSize) + 1;

		else
			stringsCount = n / userSize;


		int* matrix = new int[stringsCount * userSize];
		int linearArrayIndex = 0;
		bool putZero = false;

		for (int i = 0; i < stringsCount && !putZero; i++)
		{
			for (int j = 0; j < userSize && !putZero; j++)
			{
				matrix[i * userSize + j] = linearArray[linearArrayIndex];
				linearArrayIndex++;

				if (linearArrayIndex > n)
					putZero = true;
			}
		}
		linearArrayIndex--;
		if (putZero)
		{
			int zeroCount = (stringsCount * userSize) - n;
			for (int i = 0; i < zeroCount; i++)
			{

				matrix[linearArrayIndex] = 0;
				linearArrayIndex++;
			}
		}

		for (int i = 0; i < stringsCount; i++)
		{
			for (int j = 0; j < userSize; j++)
			{
				cout << matrix[i * userSize + j] << " | ";
			}
			cout << "\n";
		}
		return matrix;
	}
	else
		cout << "Number bigger than 10.\nProcess is closing...";
}

void GenerateLadderMatrix() 
{
	int** array = (int**)malloc(sizeof(int*) * n);// объявялем двумерный массив кол-во строк 
	for (int i = 0; i < n; i++)
	{
		array[i] = (int*)malloc(sizeof(int) * i);

		for (int j = 0; j < i + 1; j++)
			array[i][j] = (i + 1) * (j + 1);
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < i + 1; j++) 
			cout << array[i][j] << " | ";
		cout << "\n";
	}
}
