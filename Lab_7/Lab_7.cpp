#include <iostream>
#include <cmath>
using namespace std;
//Написать функцию, обнуляющую элементы массива, находящиеся между двумя минимальными элементами.
//Массив передать в функцию как параметр, вывести массив до и после обработки в функции main.

//Написать функцию, которая вычисляет для двумерного массива с переменной длинной строк 
//(длина строк случайна в диапазоне от 2 до 10) сумму элементов каждой строки. 
//Длина каждой строки хранится в 0 элементе соответствующей строки. 
//Массив сформировать с помощью случайных чисел, и вывести на экран в главной программе.

//Написать функцию, сортирующую в порядке убывания элементы одномерного массива. 
//В главной программе вызвать функцию для двух разных по количеству элементов массивов N=100 и N=1000.
//Написать две функции поиска заданных элементов в каждом из отсортированных массивов – перебором и бинарным поиском.
//Вывести количество операций сравнения в каждой функции.

void SetNullBetweenMin(int* array,const  int size);
void PrintArray(int* array,const int size);
void FillRand(int* array,const int size);
void CreateArrayOfArray(const int stringsCount);
int CalculateSum(int* string,const int stringSize);
void ShellSort(int* array,const int size);
int BinSearch(int* array,const int size, int key);
int LinearSearch(int* array,const int size, int key);

const int SIZE = 20,fN=100,sN=1000;
int main()
{
	int* array = new int[SIZE];
	FillRand(array, SIZE);// заполняем массив случайными числами 

	PrintArray(array, SIZE);
	cout << "\n";
	SetNullBetweenMin(array, SIZE);
	PrintArray(array, SIZE);
	cout <<"\n"<< string(20, '-') << "\n";
	CreateArrayOfArray(10);

	int* hundredArray = new int[fN];
	int* thousandArray = new int[sN];
	FillRand(hundredArray,fN);
	FillRand(thousandArray,sN);

	ShellSort(hundredArray, fN);
	ShellSort(thousandArray, sN);

	cout << "\nLinerSearch 100 elements: ";
	LinearSearch(hundredArray, fN, 30);

	cout << "\nBinarySearch 100 elements: ";
	BinSearch(hundredArray, fN, 30);

	cout << "\n" << string(20, '-');

	cout << "\nLinerSearch 1000 elements: ";
	LinearSearch(thousandArray, sN, 30);

	cout << "\nBinarySearch 1000 elements: ";
	BinSearch(thousandArray, sN, 30);
	cout << "\n";
}

void SetNullBetweenMin(int* array,const int size)
{
	int leftMinIndex = 0,rightMinIndex = 0;
	int min = pow(10,8);// инициализируем переменную для сравнения поиска минимального значения в массиве 
	for (int i = 0; i < size; i++)// ищем левую границу подмассива
	{
		if (array[i] < min) 
		{
			min = array[i];
			leftMinIndex = i;
		}
	}
	min = pow(10, 8);
	for (int i = size - 1; i > -1; i--)// ищем правую границу подмассива
	{
		if (array[i] < min && i!= leftMinIndex)
		{
			min = array[i];
			rightMinIndex = i;
		}
	}
	if (leftMinIndex > rightMinIndex)// делаем проверку для соблюдения правильности порядка левого и правого индексов
	{
		int tmp = leftMinIndex;
		leftMinIndex = rightMinIndex;
		rightMinIndex = tmp;
	}
	for (int i = leftMinIndex; i < rightMinIndex - 1; i++)// обнуляем элементы между двумя минимальными 
		array[i + 1] = 0;
}

void PrintArray(int* array,const int size) 
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}

void FillRand(int* array,const int size) 
{
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
}

void CreateArrayOfArray(const int stringsCount)
{
	int left = 2, right = 10;
	int** userMatrix = new int* [stringsCount];// обявляем кол-во строк в нашем массиве массивов 
	int* stringElementsCount = new int[stringsCount];

	for (int i = 0; i < stringsCount; i++) 
	{
		int size = (left + rand() % (right - left));// получаем случайный размер (2-10)
		userMatrix[i] = new int[size];// определяем случайное кол-во эл. под строку 
		stringElementsCount[i] = size;// запоминаем длинну строки, память под которую мы выделели случайным образом
	}
		
	int index = 0;
	for (int i = 0; i < stringsCount; i++) 
	{
		for (int j = 0; j < stringElementsCount[index]; j++) 
		{
			userMatrix[i][j] = rand() % 30;  // случайным образом создаем элементы под наш массив массивов 
		}
		index++;// обновляем границы строки 
	} index = 0;
	
	for (int i = 0; i < stringsCount; i++) 
	{
		for (int j = 0; j < stringElementsCount[index]; j++) 
		{
			cout << userMatrix[i][j] << " ";
		}
		index++;
		cout << "\n";
	} index = 0;
	
	cout << string(20, '-') << "\n";
	for (int i = 0; i < stringsCount; i++) 
	{
		cout << "String[" << i << "] sum= " << CalculateSum(userMatrix[i], stringElementsCount[index])<<"\n";
		index++;
	}
}
int CalculateSum(int* string,const int stringSize) 
{
	int sum = 0;
	for (int i = 0; i < stringSize; i++)
		sum += string[i];
	return sum;
}

void ShellSort(int* array,const int size)// сортировка шеллом по убыванию
{
	int h = size / 2, element;
	while (h >= 1)
	{
		for (int i = h; i < size; i++)
		{
			int j = i;
			while ((j >= h) && array[j - h] < array[j])
			{
				element = array[j];
				array[j] = array[j - h];
				array[j - h] = element;
				j = j - h;
			}
		}
		h /= 2;
	}
}
int LinearSearch(int* array, int size,int key)
{
	int iterCount = 0;
	for (int i = 0; i < size; i++) 
	{
		iterCount++;
		if (array[i] == key) 
		{	
			cout << "iterations: " << iterCount;
			return i;
		}	
	}
	cout << "Array has no elements.";
	return 0;
}

int BinSearch(int* array,int size,int key) 
{
	int left = 0, right = size - 1;// l - левая граница поиска, r - правая граница поиска
	int middle = (left + right) / 2;// m - середина области поиска
	int maxIterations = log2(size);
	int iterCount = 0;

	while (array[middle] != key && iterCount<=maxIterations) 
	{
		if (array[middle] > key)
			left = middle;
		else
			right = middle;

		middle = (left + right) / 2;
		iterCount++;
	}

	if (iterCount>maxIterations)
		cout << "Array has no element.";

	cout<<"iterations: " << iterCount;
	return middle;
}