#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
//#include <stdio.h>
using namespace std;

// 9.1
//Сформировать односвязный список, состоящий из структур, содержащих информацию: 
// фамилия студента и 4 оценки. Отсортировать список  по возрастанию (по фамилии).  
// Вывести полученный список.

// 9.2
//Сформировать двусвязный список, состоящий из структур, содержащих информацию : фамилия студента и 4 оценки.
//Найти и удалить из списка студентов, имеющих хотя бы одну неудовлетворительную оценку.
//Вывести список до и после удаления записей.

struct student 
{
	string surname;
	short firstMark = 0;
	short SecondMark = 0;
	short thirdMark = 0;
	short fourthMark = 0;
};

template <typename T>// объяляем струкутру шаблонной, для возможности работы с разными типами данных
struct Node// реализация узла односвязного списка
{
	T val;// значение,которое будет задавать пользователь
	Node* next;// указатель на следующий узел

	Node(T _val)// конструктор  
	{
		val = _val;
		next = nullptr;
	}
};

template <typename T>// объявляем класс шаблонным, для возможности работы с разными типами данных
class list 
{
	Node<T>* first;// указатель на первый узел
	Node<T>* last;// указатель на последний узел

	int Size = 0;// хранит размер списка 
	void ShowStudentInfo(const student& record);// показывает информацию о студенте 
	void CompareFunc(Node<T>* t1, Node<T>* t2, Node<T>* p, bool& f);// функция сравнения 

public:
	int size()// возвращает размер списка 
	{
		return Size;
	}

	list()// конструктор
	{
		first = nullptr;// по умолчанию указывают на nullptr
		last = nullptr;

		student st{};// костыль!
		push_back(st);
	}

	bool is_empty()// функция проверки, является ли узел списка пустым
	{
		return first == nullptr;
	}

	void push_back(T _val)// добавляет элемент в конец списка
	{
		Node<T>* p = new Node<T>(_val);
		Size++;// после добавления каждого элемента увеличиваем размер списка
		if (is_empty())//Если список пустой,присваиваем указателю на первый узел и последний узел указатель на новый узел
		{
			first = p;
			last = p;
			return;
		}
		last->next = p;//Раз мы добавляем в конец, надо указать, что новый узел стоит после последнего узла.
		last = p;//Меняем значения указателя last.
	}

	void remove_first()// удалить первый элемент
	{
		if (is_empty()) return;
		Node<T>* p = first;
		first = p->next;
		delete p;
	}

	void print()// печетает наш список 
	{
		if (is_empty()) return;
		Node<T>* p = first;//Cоздаем указатель p на первый узел
		while (p)// p != nullptr
		{ 
			ShowStudentInfo(p->val);// выводим информацию о каждой записи
			p = p->next;// переходим к следующему узлу
		}
		cout << endl;
	}

	void Sort()// сортирует список
	{
		Node<T>* t1, * t2;
		bool f;
		do
		{
			f = 0;
			for (Node<T>* p = first; p->next->next; p = p->next) 
			{
				t1 = p->next; t2 = t1->next;
				CompareFunc(t1,t2,p,f);
			}
		}while (f);
		remove_first();
	}
};

void list<student> :: ShowStudentInfo(const student& record)// выводит информацию о студенте 
{
	if (record.surname != "") 
	{
		cout << left << setw(12) << record.surname << left << setw(2) << record.firstMark
			<< left << setw(2) << record.SecondMark << left << setw(2) << record.thirdMark
			<< left << setw(2) << record.fourthMark << "\n";
	}
}

void list<student> :: CompareFunc(Node<student>* t1, Node<student>* t2, Node<student>* p, bool& f)
{
	if (t1->val.surname > t2->val.surname) 
	{
		p->next = t2; 
		t1->next = t2->next; 
		t2->next = t1; 
		f = 1;
	}
}

struct student_2// структура студента для двусвязного списка
{
	string surname;
	int grades[4];
	student_2* next;
	student_2* previous;
};

class doubleLinkedList 
{
public:
	void AddStudent(student_2* head, string surname, int fMark, int sMark, int tMark, int ftMark)// функция добавления студента в двусвязный список 
	{
		student_2* new_student = new student_2;
		new_student->grades[0] = fMark;
		new_student->grades[1] = sMark;
		new_student->grades[2] = tMark;
		new_student->grades[3] = ftMark;

		head->previous = new_student;
		new_student->next = head;
	}
		
	void Printlist(student_2* head)// распечатать весь список
	{
		if (head->next == nullptr)// если список пустой, выходим из функции
			return;

		student_2* current = head->next->previous;
		while (current != nullptr)// пока не дошли до конца списка, выводим данные о студенте 
		{
			cout << left << setw(12) << current->surname << left << setw(2) << current->grades[0]
				<< left << setw(2) << current->grades[1] << left << setw(2) << current->grades[2]
				<< left << setw(2) << current->grades[3] << "\n";

			current = current->next;
		}
	}

	void RemoveStudent(student_2* head)// функция удаления студента из списка,если он имеет плохую оценку
	{
		for (int i = 0; i < 4; i++)// пробегаемся по всем оценкам
		{
			if (head->grades[i] == 2)// если встретили плохую отметку
			{
				if (head->next != nullptr)
					head->next->previous = head->previous;
				if (head->previous != nullptr)
					head->previous->next = head->next;
				delete head;
			}
		}
	}

	void ClearFromRemovedStudent(student_2* head) 
	{
		student_2* current = head;
		student_2* next;
		do 
		{
			next = current->next;
			RemoveStudent(current);
			current = next;
		} while (next != nullptr);
	}
};


int main() 
{
	vector<student> studentsRecords;// Объявялем вектор записей
	studentsRecords.push_back({ "Petrov",3,3,4,4 }); studentsRecords.push_back({ "Alexandrov", 4, 4, 4, 5 });
	studentsRecords.push_back({ "Sidorov",4,4,3,5 }); studentsRecords.push_back({"Ivanov",5,4,3,5});
	studentsRecords.push_back({ "Baranov",5,4,3,5 }); studentsRecords.push_back({ "Pyatkov",5,4,3,5 });
	
	list<student> gradeBook;// создаем журнал с оценками студентов
	gradeBook.push_back(studentsRecords[0]); gradeBook.push_back(studentsRecords[1]);// добавляем студентов в наш журнал с оценками
	gradeBook.push_back(studentsRecords[2]); gradeBook.push_back(studentsRecords[3]);
	gradeBook.push_back(studentsRecords[4]); gradeBook.push_back(studentsRecords[5]);
	
	gradeBook.print();// выводим наш журнал с оценками до сортировки
	gradeBook.Sort();// сортируем журнал с оценками
	gradeBook.print();// печатаем журнал с оценками после сортировки


	student_2* ivan = new student_2{ "Ivan", {5, 5, 5, 4}, nullptr,nullptr };// первое поле next, второе previous
	student_2* dmitry = new student_2{ "Dmitry", {5, 2, 2, 5}, nullptr,ivan };
	student_2* oleg = new student_2{ "Oleg", {4, 4, 4, 5}, nullptr,dmitry };
	student_2* fedor = new student_2{ "Fedor",{4,2,5,5},nullptr,oleg };

	ivan->next = dmitry;
	dmitry->next = oleg;
	oleg->next = fedor;

	doubleLinkedList doublelinkedlist;
	doublelinkedlist.Printlist(ivan);// выводим до удаления 
	cout << "\n";
	doublelinkedlist.ClearFromRemovedStudent(ivan);// удаляем
	doublelinkedlist.Printlist(ivan);// выводим после удаления
}
