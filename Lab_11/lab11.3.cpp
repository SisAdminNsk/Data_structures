#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::cin;
using std::left;
using std::setw;
using std::string;

/*Запись имеет вид: ФИО пассажира, количество занимаемых багажом мест, общий вес вещей. Используя функции и режим меню:
а) создать  файл из N записей;
б) просмотреть файл;
в) добавить в конец файла новую запись;
г) найти и удалить из файла записи о пассажирах, общий вес вещей  которых   меньше, чем 10 кг.
д) изменить вес вещей пассажира по заданной фамилии.*/

struct passenger
{
	string name;
	string midname;
	string lastname;

	int count;
	float weight;

} pass;

void ShowMenu() 
{
	cout << "MENU:\n";
	cout << "1 - Read a file" << "\n";
	cout << "2 - Add to  file" << "\n";
	cout << "3 - Search and change " << "\n";
	cout << "4 - Remove" << "\n";
	cout << "0 - Exit" << "\n";
}

void DrawPassagerTableHead()
{
	cout << left << setw(10) << "Passager" << left << setw(15) << "Firstname" << left << setw(15) << "Lastname" <<
		left << setw(15) << "Surname" << left << setw(8) << "Weight" << left << setw(8) << "Enga.Places" << "\n";
}

void ShowPassagerInfo(const int number) 
{
	cout << left << setw(10) << number << left << setw(15) << pass.name << left << setw(15) << pass.lastname <<
		left << setw(15) << pass.midname << left << setw(8) << pass.weight << left << setw(8) << pass.count << "\n";
}

void Print(const string name)
{
	int i = 1;
	std::ifstream file(name, std::ios::binary);

	system("CLS");
	DrawPassagerTableHead();// рисуем шапку таблицы
	while (file.read((char*)(&pass), sizeof(pass)))
	{
		ShowPassagerInfo(i);
		i++;
	}
	file.close();
	cout << "\nEND OF TABLE.\n";
	cout << "Any key to continue...";
	_getch();
	system("CLS");
}

void Add(const string name)//добавление в файл
{
	char ch;
	std::ofstream file(name, std::ios::out | std::ios::app | std::ios::binary);
	file.seekp(0, std::ios::end);
	do
	{
		system("CLS");
		cout << "Surname: "; cin >> pass.lastname;
		cout << "Name: "; cin >> pass.name;
		cout << "Secname: "; cin >> pass.midname;
		cout << "Baggage taked positions: "; cin >> pass.count;
		cout << "Weight: "; cin >> pass.weight;

		file.write((char*)(&pass), sizeof(pass));
		if (cin.fail()) 
		{
			cin.clear(); // Сбрасываем флаг ошибки
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Удаляем оставшиеся символы в буфере
			cout << "\nError. You must input the number\n";
			ch = 'n';
		}

		else 
		{
			system("CLS");
			cout << "Success! One more or stop?  'y' / 'n'\n";
			ch = _getch();
		}

	} while (ch != 'n');
	system("CLS");
	file.close();
}

void Find(const string name)//поиск и изменение
{
	system("CLS");
	char c; bool find = false;
	std::string sur;
	long int i = 0;
	std::fstream file(name, std::ios::in | std::ios::out | std::ios::binary);

	cout << "Input Lastname for search: ";
	cin >> sur;
	while (file.read((char*)(&pass), sizeof(pass)))
	{
		i++;
		if (pass.lastname == sur)
		{
			DrawPassagerTableHead();// Шапка таблицы
			ShowPassagerInfo(i);// информация о пассажире
			cout << "\nchange weight? y/n ";

			c = _getch();
			find = true;
			if (c == 'y')
			{
				cout << "\nweight: "; cin >> pass.weight;
				file.seekg(-(long long)(sizeof(pass)), std::ios::cur); // переход на одну запись в файле
				file.write((char*)(&pass), sizeof(pass)); // вывод в файл измененной записи
				file.flush();//очистка буферов ввода-вывода
				cout << "Success!";
				_getch();
			}
		}
	}
	if (!find)
		cout << "Surname has not found\nAny key to continue...";

	_getch();
	system("CLS");
	file.close();
}

void Del(const string name)//удаление
{
	system("CLS");
	char c;
	std::fstream file(name, std::ios::in | std::ios::out | std::ios::binary);
	while (file.read((char*)(&pass), sizeof(pass)))
	{
		if (pass.weight < 10)
		{
			pass.count = 0; pass.weight = 0; pass.name = "NONE"; pass.midname = "NONE"; pass.lastname = "NONE";
			file.seekg(-(long long)(sizeof(pass)), std::ios::cur); // переход на одну запись в файле
			file.write((char*)(&pass), sizeof(pass)); // вывод в файл измененной записи
			file.flush();//очистка буферов ввода-вывода
		}
	}
	cout << "Success!\nAll passangers,that weight was < 10Kg was deleted.";
	file.close();
	_getch();
	system("CLS");
}

int main() 
{
	char c;
	while (true)
	{
		system("CLS");
		ShowMenu();// вывод меню в консоль
		c = _getch();
		switch (c)
		{
		case '1':
			Print("passanger.dat"); break;
		case '2':
			Add("passanger.dat"); break;
		case '3':
			Find("passanger.dat"); break;
		case '4':
			Del("passanger.dat"); break;
		case '0':
			return 0;
		default:
			system("CLS");
			cout << "INCORRECT MODE!\n";
			cout << "Any key to continue...";
			_getch();
		}
	}
}