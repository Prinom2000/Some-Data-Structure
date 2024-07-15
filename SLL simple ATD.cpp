
#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }  // Default constructor

    Node(int d) {
        data = d;
        next = nullptr;
    }  // Parameterized constructor

};

class SLL {
private:
    Node* head;

public:

    void create(int d) {
        Node* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SLL* s = new SLL();
    s->create(5);
    s->create(6);
    s->create(7);

    std::cout << "The elements in the list are: ";
    s->display();

    delete s;  // Clean up dynamically allocated memory
    return 0;
}
