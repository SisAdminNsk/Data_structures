#pragma once
#include <iostream>
// связный список (очередь)
template<typename T>
struct Node {
	Node* next;
	T data;

	Node(T data) {
		next = NULL;
		this->data = data;
	}
};

template <typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
	size_t Size = 0;
public:
	const T& operator[](unsigned int i);
	List();
	~List();
	void push_back(T data);
	void pop_front();
	void pop_back();
	bool isEmpty() const;
	void print() const;
	std::pair<size_t,bool> getIndexByKey(T key) const;// first - index if was find, second bool (find or not)
	size_t size() const;
};

template<typename T>
inline const T& List<T>::operator[](unsigned int i)
{
	Node<T>* temp = head;
	unsigned int startIndex = 0;
	while (temp) {
		if (startIndex == i)
			return temp->data;
		startIndex++;
		temp = temp->next;
	}
	return NULL;
}

template<typename T>
inline List<T>::List() : head(NULL), tail(NULL) {};


template<typename T>
inline List<T>::~List()
{
	Node<T>* temp = head;
	while (temp != NULL) {
		temp = head->next;
		delete head;
		head = temp;
	}
}


template<typename T>
inline bool List<T>::isEmpty() const
{
	bool result;
	result = (head == NULL);
	return result;
}


template<typename T>
inline void List<T>::push_back(T data)
{
	Node<T>* temp = new Node<T>(data);
	if (!isEmpty()) {
		tail->next = temp;
		tail = temp;
	}
	else {
		head = tail = temp;
	}
	Size++;
}


template<typename T>
inline void List<T>::pop_front()
{
	if (Size == 1) {
		return;
	}
	Node<T>* temp = head;
	while (temp->next != tail) {
		temp = temp->next;
	}
	temp->next = NULL;
	delete tail;
	tail = temp;
	Size--;
}


template<typename T>
inline void List<T>::pop_back()
{
	Node<T>* temp = head;
	temp = temp->next;
	delete head;
	head = temp;
}


template<typename T>
inline void List<T>::print() const
{
	Node<T>* temp = head;
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}


template<typename T>
inline std::pair<size_t, bool> List<T>::getIndexByKey(T key) const
{
	size_t index = 0;
	Node<T>* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			return std::make_pair(index, true);// return if find 
		}
		temp = temp->next;
		index++;
	}
	return std::make_pair(-1, false);// return if not find
}


template<typename T>
inline size_t List<T>::size() const
{
	return Size;
}