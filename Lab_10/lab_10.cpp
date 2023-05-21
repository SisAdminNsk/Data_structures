#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

//Создать текстовый файл из нескольких строк, в каждой строке несколько слов.
//Задание.
//Считать строки из файла.Строки разбить на слова.Слова отсортировать по алфавиту и вывести во второй файл.
//Слова сохранить с списке или динамическом массиве(количество элементов в структуре данных должен быть равен количеству слов в файле)

template<typename T>
void ReadFromFile(string path, list<T>& output);

template<typename T>
void TakeWordsFromString(string str,list<T>& output);

void WriteInFile(fstream& file, list<string>& data);

int main()
{
	list<string> stringsFromFile;// объявляем список в которой положим все строки из файла
	ReadFromFile("text.txt",stringsFromFile);// читаем файл и забираем оттуда строки

	list<string> wordsFromFile;// объявляем список в который положим все слова из stringsFromFile
	for (string str : stringsFromFile) 
		TakeWordsFromString(str, wordsFromFile);
	
	wordsFromFile.sort();// сортируем слова по алфавиту 
	for (string str : wordsFromFile)// выводим слова 
		cout << str << "\n";

	fstream secondFile("output.txt",ios::app);// создаем файл в репозитории и открываем его под запись в конец файла
	WriteInFile(secondFile, wordsFromFile);// записываем слова во второй файл
}

template <typename T>
void ReadFromFile(string path,list<T>& output)// читает файл
{
	ifstream file(path);
	string line = "";

	if (file.is_open())// проверяем получилось ли открыть файл
		while (getline(file, line))// пока в файле есть строки
			output.push_back(line);// кладем эти строки в список
			
	file.close();
}

template<typename T>
void TakeWordsFromString(string str,list<T>& output)// достает из строки слова
{
	string word = "";// строка для слова которое мы будем собирать и класть в output
	for (int i = 0; i < str.length(); i++)// идем по строке
	{
		if(str[i] != ' ')
			word += str[i];

		else 
		{
			output.push_back(word);
			word = "";
		}

		if(i == str.length()-1 && word.length()>0)// кладем последние слова в строке
			output.push_back(word);
	}
}

void WriteInFile(fstream& file, list<string>& data) 
{
	if (file.is_open())// проверяем открыт ли файл 
		for (string str : data) // записываем строки в файл
			file << str << "\n";
			
	file.close();// закрываем файл
}
