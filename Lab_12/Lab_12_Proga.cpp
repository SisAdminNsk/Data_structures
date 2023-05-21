#include <iostream>
#include <functional>
#include <time.h> 
#include "Library.h"

template <typename T>
double timer(std::function<void(T*,T)> func, T* arr,const int size);// функция для оценки времени работы др. функций 
/////////////////////
template <typename T>
double timer(std::function<void(T*, T, T)> func, T* arr,const int size);// перегруженный инвариант
////////////////////
template<typename T>
void fillRand(T* array);
///////////////////////

const int SIZE = 1000000;
int main()
{
	double time = 0;
	int* arrayShell = new int[SIZE];
	int* arrayPyramid = new int[SIZE];
	int* arrayQuick = new int[SIZE];

	fillRand(arrayShell);
	fillRand(arrayPyramid);
	fillRand(arrayQuick);

	std::function<void(int*,int)> shellSortTime = sorts::ShellSort<int>;
	std::function<void(int*, int)> pyramidSortTime = sorts::PyramidalSort<int>;
	std::function<void(int*, int, int)> quickSortTime = sorts::Quicksort<int>;

	time = timer(shellSortTime, arrayShell, SIZE);
	std::cout << "SHELL run time: " << time;
	time = timer(pyramidSortTime, arrayPyramid, SIZE);
	std::cout << "\nPYRAMIDAL run time: " << time;
	time = timer(quickSortTime, arrayQuick, SIZE);
	std::cout <<"\nQUICK run time: " << time;
}

template <typename T>
double timer(std::function<void(T*,T)> func, T* arr,const int size)// функция для оценки времени работы др. функций 
{
	clock_t start = clock();
	func(arr,size);
	clock_t end = clock();

	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	return seconds;
}

template <typename T>
double timer(std::function<void(T*, T,T)> func, T* arr,const int size)
{
	clock_t start = clock();
	func(arr,1,size-1);
	clock_t end = clock();

	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	return seconds;
}

template <typename T>
void fillRand(T* array) 
{
	for (int i = 0; i < SIZE; i++)
		array[i] = rand() % 10000;
}