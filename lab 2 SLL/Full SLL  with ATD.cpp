#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class SLL {
private:
    Node* head;
    int length;

public:
    SLL() : head(nullptr), length(0) {}

    void add(int item) {
        Node* newNode = new Node(item);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        length++;
    }

    void addbegin(int item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void addanypos(int pos, int item) {
        if (pos < 0 || pos > length) throw out_of_range("Invalid position!");
        Node* newNode = new Node(item);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        length++;
    }

    bool contains(int item) {
        Node* temp = head;
        while (temp) {
            if (temp->data == item) return true;
            temp = temp->next;
        }
        return false;
    }

    int size() { return length; }

    bool isEmpty() { return length == 0; }

    int get(int pos) {
        if (pos < 0 || pos >= length) throw out_of_range("Invalid position!");
        Node* temp = head;
        for (int i = 0; i < pos; i++) temp = temp->next;
        return temp->data;
    }

    int indexOf(int item) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == item) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void removefirst() {
        if (!head) throw underflow_error("List is empty!");
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void removelast() {
        if (!head) throw underflow_error("List is empty!");
        if (!head->next) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        length--;
    }

    void remove(int pos) {
        if (pos < 0 || pos >= length) throw out_of_range("Invalid position!");
        if (pos == 0) {
            removefirst();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) temp = temp->next;
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        length--;
    }

    void reverse() {
        Node* prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void sort() {
        if (!head || !head->next) return;
        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data) swap(i->data, j->data);
            }
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~SLL() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SLL s;
    int choice, item, pos;

    while (true) {
        cout << "\n---- Singly Linked List Menu ----\n";
        cout << "1. Add item at the end\n";
        cout << "2. Add item at the beginning\n";
        cout << "3. Add item at any position\n";
        cout << "4. Display list\n";
        cout << "5. Search item\n";
        cout << "6. Get element at position\n";
        cout << "7. Get index of element\n";
        cout << "8. Remove first element\n";
        cout << "9. Remove last element\n";
        cout << "10. Remove element at position\n";
        cout << "11. Reverse list\n";
        cout << "12. Sort list\n";
        cout << "13. Get size of list\n";
        cout << "14. Check if list is empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                cout << "Enter item to add: ";
                cin >> item;
                s.add(item);
            }
            else if (choice == 2) {
                cout << "Enter item to add at beginning: ";
                cin >> item;
                s.addbegin(item);
            }
            else if (choice == 3) {
                cout << "Enter position and item: ";
                cin >> pos >> item;
                s.addanypos(pos, item);
            }
            else if (choice == 4) {
                cout << "List elements: ";
                s.display();
            }
            else if (choice == 5) {
                cout << "Enter item to search: ";
                cin >> item;
                cout << (s.contains(item) ? "Item found\n" : "Item not found\n");
            }
            else if (choice == 6) {
                cout << "Enter position: ";
                cin >> pos;
                cout << "Element at position " << pos << " is: " << s.get(pos) << endl;
            }
            else if (choice == 7) {
                cout << "Enter item to find index: ";
                cin >> item;
                cout << "Index of " << item << ": " << s.indexOf(item) << endl;
            }
            else if (choice == 8) {
                s.removefirst();
                cout << "First element removed.\n";
            }
            else if (choice == 9) {
                s.removelast();
                cout << "Last element removed.\n";
            }
            else if (choice == 10) {
                cout << "Enter position to remove: ";
                cin >> pos;
                s.remove(pos);
                cout << "Element removed.\n";
            }
            else if (choice == 11) {
                s.reverse();
                cout << "List reversed.\n";
            }
            else if (choice == 12) {
                s.sort();
                cout << "List sorted.\n";
            }
            else if (choice == 13) {
                cout << "List size: " << s.size() << endl;
            }
            else if (choice == 14) {
                cout << (s.isEmpty() ? "List is empty.\n" : "List is not empty.\n");
            }
            else if (choice == 0) {
                cout << "Exiting...\n";
                break;
            }
            else {
                cout << "Invalid choice! Try again.\n";
            }
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
