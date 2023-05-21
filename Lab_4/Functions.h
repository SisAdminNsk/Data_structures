#include <iostream>
#include <stdlib.h>
using namespace std;

const int stringLenght = 5;
// function's header's =>
void PrintMatrix(int* matrix, int strings, bool printResizeArray = false);
int CalculateSumOfMatrixString(int* matrix, int high, int width, int stringIndex = 0, int columnIndex = 0, bool stringOrColumn = false);
int CalculateNewMatrixString(int* matrix, int high, int width, int stringIndex = 0, int columnIndex = 0, bool stringOrColumn = false);
// function's header's <=

void CreateMatrix(int strings = 0)
{
	cout << "Input count of matrix's strings => ";
	cin >> strings;

	int* matrix = new int[strings * stringLenght];
	
	for (int i = 0; i < strings; i++) 
		for (int j = 0; j < stringLenght; j++) 
			matrix[i * stringLenght + j] = rand() % 50;
	
	int indexOfMaxValue = 0;
	int maxValue = 0;
	// finding string and column index of max value 
	for (int i = 0; i < strings; i++)
		for (int j = 0; j < stringLenght; j++) 
			if (matrix[i * stringLenght + j] > maxValue) 
			{
				indexOfMaxValue = i * stringLenght + j;
				maxValue = matrix[i * stringLenght + j];
			}

	int maxValueStringIndex = indexOfMaxValue / stringLenght;
	int maxValueColumnIndex = indexOfMaxValue - (indexOfMaxValue / stringLenght) * stringLenght;
	cout << "\nIndex's of max value: \n";
	cout << "Index of string: " << maxValueStringIndex << "\nIndex of column: " << maxValueColumnIndex <<"\n";

	int* newMatrix = new int[(strings - 1) * (stringLenght - 1)];
	int stringIndex = 0, columnIndex = 0;
	//Filling newMatrix by values of matrix
	for (int i = 0; i < strings; i++) 
	{
		if (i == maxValueStringIndex)
			continue;

		for (int j = 0; j < stringLenght; j++)
		{
			if (j == maxValueColumnIndex)
				continue;

			newMatrix[stringIndex * (stringLenght - 1) + columnIndex] = matrix[i * stringLenght + j];
			columnIndex++;

			if (j == stringLenght)
				stringIndex++;
		}
	}
	cout << "\n";
	PrintMatrix(newMatrix, strings, true);
	cout << "\n";
	PrintMatrix(matrix, strings);
}

void PrintMatrix(int* matrix,int strings, bool printResizeArray)
{
	if (printResizeArray) 
	{
		for (int i = 0; i < strings - 1; i++)
		{
			for (int j = 0; j < stringLenght - 1; j++)
				cout << matrix[i * (stringLenght - 1) + j] << "  ";
			cout << "\n";
		}
		return;
	}
		
	for (int i = 0; i < strings; i++) 
	{
		for (int j = 0; j < stringLenght; j++)
			cout << matrix[i * stringLenght + j] << "  ";
		cout << "\n";
	}
}

void CreateUserMatrix(int high = 0,int width = 0) 
{
	cout << "Input count of strings: => ";
	cin >> high;
	cout << "Input count of columns: = > ";
	cin >> width;

	int* userMatrix = new int[high * width];
	for (int i = 0; i < high; i++)
		for (int j = 0; j < width; j++)
			userMatrix[i * width + j] = rand() % 101;

	cout << "\nFirst matrix:\n";
	for (int i = 0; i < high; i++) 
	{
		for (int j = 0; j < width; j++)
			cout << userMatrix[i * width + j] << " | ";
		cout << "\n";
	}
	int stringSum = CalculateSumOfMatrixString(userMatrix, high, width, 0);
	int columnSum = CalculateSumOfMatrixString(userMatrix, high, width, NULL, 0, true);

	int* newUserMatrix = new int[(high + 1) * (width + 1)];
	for (int i = 0; i < high; i++)
		for (int j = 0; j < width; j++) 
			newUserMatrix[i * (width+1) + j] = userMatrix[i * width + j];

	int inc = 0;
	while (inc != high + 1) 
	{
		newUserMatrix[width + width * inc + inc] = CalculateSumOfMatrixString(userMatrix,high,width,inc);
		inc++;
	}
	inc = 0;
	while (inc != width + 1) 
	{
		newUserMatrix[high * (width+1) + inc] = CalculateSumOfMatrixString(userMatrix, high, width, NULL, inc, true);
		inc++;
	}
	newUserMatrix[(high+1) * (width+1) - 1] = CalculateNewMatrixString(newUserMatrix, high, width, high) + CalculateNewMatrixString(newUserMatrix, high, width, NULL, width, true);
	cout << "\n\nNew matrix:\n";
	for (int i = 0; i < high + 1; i++) 
	{
		for (int j = 0; j < width + 1; j++)
			cout << newUserMatrix[i * (width+1) + j] << " | ";
		cout << "\n";
	}
}

int CalculateSumOfMatrixString(int* matrix, int high, int width, int stringIndex, int columnIndex, bool stringOrColumn)
{
	int sum = 0;
	if (stringOrColumn == false)
	{
		for (int i = 0; i < width; i++)
			sum += matrix[stringIndex * width + i];
		return sum;
	}

	else 
		for (int i = 0, dec = 0; i < high; i++, dec += width)
			sum += matrix[columnIndex * 1 + dec];
		return sum;
}
		
int CalculateNewMatrixString(int* matrix, int high, int width, int stringIndex, int columnIndex, bool stringOrColumn)
{
	int sum = 0;
	if (stringOrColumn == false)
	{
		for (int i = 0; i < width; i++)
			sum += matrix[stringIndex * (width+1) + i];
		return sum;
	}

	else
		for (int i = 0, dec = 0; i < high; i++, dec += width+1)
			sum += matrix[columnIndex * 1 + dec];
	return sum;
}
