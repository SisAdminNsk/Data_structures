#pragma once
#include <cmath>

class sorts// contains sorts and alghoritms 
{
private:
	template<typename T>
	static void CreatePyramid(int left, int right, T arr[])
	{
		int x = arr[left], i = left, j;
		while (true)
		{
			j = 2 * i + 1;
			if (j > right) break;

			if ((j < right) && (arr[j + 1] > arr[j])) j++;

			if (x > arr[j]) break;// сравнение с добавляемым в пирамиду

			arr[i] = arr[j];
			i = j;
		}
		arr[i] = x;
	}

	static int log(int len)
	{
		int x = 1;
		while (pow(2, x) <= len)
			x++;

		return x - 1;
	}

	static int step(int M)
	{
		if (M == 1) return 1;
		return step(M - 1) * 2 + 1;
	}

public:
	template<typename T>
	static void PyramidalSort(T arr[],const int n)
	{
		int left = n / 2;
		while (left > -1)
		{
			CreatePyramid(left, n - 1, arr);
			left--;
		}
		int right = n - 1;
		while (right > 0)
		{
			int temp = arr[0];
			arr[0] = arr[right];
			arr[right] = temp;
			CreatePyramid(0, right - 1, arr);
			right--;
		}
	}

	template<typename T>
	static void Quicksort(T* arr, int left,const int right)
	{
		int i = left, j = right, mid = (left - 1 + right - 1) / 2;
		int tmp;
		int a = arr[mid];

		while (i <= j)
		{
			while (arr[i - 1] < a)
				i++;

			while (arr[j - 1] > a)
				j--;

			if (i <= j)
			{
				tmp = arr[i - 1];
				arr[i - 1] = arr[j - 1];
				arr[j - 1] = tmp;
				i++;
				j--;
			}
		};

		if (left < j) // сортировка для левой части 
			Quicksort(arr, left, j);

		if (i < right)// сорировка для правой части
			Quicksort(arr, i, right);
	}

	template<typename T>
	static void ShellSort(T arr[],const int len)
	{
		int i, j, k, temp, M = log(len) - 1;
		while (M > 0)
		{
			k = step(M);
			for (i = k; i < len; i++)
			{
				temp = arr[i];
				j = i - k;

				while ((j > -1) && (temp < arr[j]))
				{
					arr[j + k] = arr[j];
					j = j - k;
					if ((j > -1) && (temp < arr[j]));
				}
				arr[j + k] = temp;
			}
			M--;
		}
	}

	template<typename T>
	static void ShakerSort(T arr[], const int len)
	{
		int left = 0, right = len - 1, k = len, j, temp = 0;
		do
		{
			for (j = right; j > left; j--)
			{
				if (arr[j] < arr[j - 1])
				{
					temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
					k = j;
				}
			}
			left = k;
			for (j = left; j < right; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					k = j;
				}
			}
			right = k;
		} while (left < right);
	}
};