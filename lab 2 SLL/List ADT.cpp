#include <iostream>
#include <stdexcept>

class Node {
public:
    int data;
    Node* next;

    Node(int item, Node* nextNode = nullptr) {
        data = item;
        next = nextNode;
    }
};

class ListADT {
private:
    Node* head;
    int length;

public:
    ListADT() : head(nullptr), length(0) {}

    ~ListADT() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        length++;
    }

    void addbegin(int item) {
        Node* newNode = new Node(item, head);
        head = newNode;
        length++;
    }

    void addanypos(int pos, int item) {
        if (pos < 0 || pos > length) {
            throw std::out_of_range("Position out of bounds");
        }
        if (pos == 0) {
            addbegin(item);
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* newNode = new Node(item, temp->next);
            temp->next = newNode;
            length++;
        }
    }

    bool contains(int item) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int size() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0;
    }

    int get(int pos) const {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Position out of bounds");
        }
        Node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    int indexOf(int item) const {
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) {
            if (temp->data == item) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void removefirst() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    void removelast() {
        if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next->next != nullptr) {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = nullptr;
            }
            length--;
        }
    }

    void remove(int pos) {
        if (pos < 0 || pos >= length) {
            throw std::out_of_range("Position out of bounds");
        }
        if (pos == 0) {
            removefirst();
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            length--;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void sort() {
        if (length < 2) {
            return;
        }
        for (Node* i = head; i->next != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data > j->data) {
                    std::swap(i->data, j->data);
                }
            }
        }
    }
};

int main() {
    ListADT list;
    list.add(3);
    list.add(1);
    list.add(2);
    list.addbegin(0);

    std::cout << "List contains 2: " << list.contains(2) << std::endl;
    std::cout << "Size of list: " << list.size() << std::endl;
    std::cout << "List is empty: " << list.isEmpty() << std::endl;
    std::cout << "Element at position 2: " << list.get(2) << std::endl;
    std::cout << "Index of element 1: " << list.indexOf(1) << std::endl;

    list.removefirst();
    list.removelast();
    list.addanypos(1, 5);
    list.reverse();
    list.sort();

    for (int i = 0; i < list.size(); i++) {
        std::cout << "Element at position " << i << ": " << list.get(i) << std::endl;
    }

    return 0;
}
