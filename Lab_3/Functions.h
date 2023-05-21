#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

//***** Заголовки функций *****
void PrintArray(int* array, int size);
void PrintArray(float* array, int size);
void PrintSieve(int number);
int comp(const int*, const int*);
//***** Загаловки функций *****

void AllocateArray() 
{
	cout << "Input array size => ";
	int size = 0;
	cin >> size;

	int* array = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++)
		array[i] = rand() % 101 - 50;

	int positiveElementsCount = 0;
	int negativeElementsCount = 0;

	for (int i = 0; i < size; i++)
		if (array[i] >= 0)
			positiveElementsCount++;
		else
			negativeElementsCount++;

	int* positiveElementsArray = (int*)malloc(sizeof(int) * positiveElementsCount);
	int* negativeElementsArray = (int*)malloc(sizeof(int) * negativeElementsCount);
	int positiveStartIndex = 0, negativeStartIndex =0;

	for (int i = 0; i < size; i++) 
	{
		if (array[i] >= 0) 
		{
			positiveElementsArray[positiveStartIndex] = array[i];
			positiveStartIndex++;
		}
		else
		{
			negativeElementsArray[negativeStartIndex] = array[i];
			negativeStartIndex++;
		}
	}
	string line(20, '-');
	cout << "\nFirst array:" << "\n";
	PrintArray(array, size);
	cout << "\n\n" << line << "\n";
	cout << "Positive elements array:" << "\n";
	PrintArray(positiveElementsArray, positiveElementsCount);
	cout << "\n\n" << line << "\n";
	cout << "Negative elements array:" << "\n";
	PrintArray(negativeElementsArray, negativeElementsCount);
	cout << "\n";

	free(array);
	free(negativeElementsArray);
	free(positiveElementsArray);

}

void AllocateWithNew() 
{
	cout << "Input array size: => ";
	int size = 0;
	cin >> size;

	float* array = new float[size];
	float* pArray = array;// создаем массив указателей, испольщующий одну область памяти вместе с исходным массивом 

	for (int i = 0; i < size; i++)
		array[i] = 0.01 * (rand() % 101);

	cout << "\nFirst array: \n";
	PrintArray(array, size);// вывод исходного массива до сортировки массива указателей
	cout << "\n";
	// сортируем массив указателей, а вместе с ним сортируется и исходный массив т.к как они оба указывает на одну область
	qsort(pArray,size,sizeof(float), (int(*) (const void*, const void*)) comp);
	cout << "First array sorted by pointers array: \n";
	PrintArray(array, size);// вывод  исходного массива после сортировки массива указателей
}


void PrintArray(int* array,int size) 
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}

void PrintArray(float* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
}

void PrintArray(vector <bool> array, int size)
{
	for (int i = 2; i < size; i++)
		if(array[i] != 0)
			cout << i << " ";
}

int comp(const int *i, const int *j)// функция сравнения, указываем чтобы сортировка была по возрастанию
{
	return *i - *j;
}

void PrintSieve(int number = 1) 
{
	cout << "\n\nInput number: => ";
	cin >> number;

	vector<bool> prime(number+1);
	for (int i = 2; i < number; i++)
		prime[i] = true;

	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= number; ++i)
		if (prime[i])
			for (int j = i * i; j <= number; j += i)
				prime[j] = false;

	PrintArray(prime,number);
}
