#include <iostream>
// DOUBLE LINKED LIST
struct Node {
    Node* previous;
    Node* next;
    int data;
};

class List {
public:
    void Add(int data);
    void Print();

private:
    Node* first = nullptr;
    Node* last = nullptr;
};

void List::Add(int data)
{
    Node* element = new Node;
    element->data = data;
    element->next = nullptr;

    if (first != nullptr) {
        element->previous = last;
        last->next = element;
        last = element;
    } else {
        element->previous = nullptr;
        first = last = element;
    }
}

void List::Print()
{
    std::cout << "My list is:\n";
    Node* temp = first;
    while (temp != nullptr) {
        std::cout << temp->data;
        temp = temp->next;
    }
}