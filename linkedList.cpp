#include <iostream>
// LINKED LIST
struct Node {
    Node* next;
    int data;
};

class Stack {
private:
    Node* first;           // элемент связного списка
    unsigned int size = 0; // размер списка
public:
    Stack()
    {
        first = nullptr;
    }
    void Add(int data)
    {
        Node* element = new Node;
        element->data = data;
        element->next = first;
        first = element;

        size++;
    }
    bool Remove(int index)
    {
        if (index == 0) {
            Node* temp = first;
            first = temp->next;
            delete temp;
            return true;
        }
        for (int i = 0; i < size; i++) {
            if (i == index) {
                int j = 0;
                Node* temp = first;
                while (j != i - 1) {
                    temp = temp->next;
                    j++;
                }
                temp->next = temp->next->next;
                temp = nullptr;
                return true;
            }
        }
        return false;
    }
    void Print()
    {
        Node* tempFirst = first;
        while (tempFirst) // пока не NULL
        {
            std::cout << tempFirst->data << "\n";
            tempFirst = tempFirst->next; // двигаемся к следующему
        }
    }
};
