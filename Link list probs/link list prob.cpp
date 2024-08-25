#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to find the node with the smallest key value
    Node* findMinKey() {
        if (head == nullptr) return nullptr; // If the list is empty, return null.

        Node* minNode = head; // Assume the first node has the smallest key.
        Node* current = head->next;

        while (current != nullptr) {
            if (current->key < minNode->key) {
                minNode = current; // Update the node with the smallest key.
            }
            current = current->next;
        }

        return minNode; // Return the node with the smallest key.
    }

    // Function to delete nodes with negative keys
    void deleteNegativeKeys() {
        while (head != nullptr && head->key < 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->key < 0) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    // Function to delete the node following a node with a negative key
    void deleteAfterNegative() {
        Node* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->key < 0) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    // Function to append the list to itself
    void appendSelf() {
        if (head == nullptr) return; // If the list is empty, do nothing.

        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next; // Find the last node in the list.
        }

        Node* current = head;
        while (current != nullptr) {
            Node* newNode = new Node(current->key); // Create a new node with the same key.
            tail->next = newNode; // Append the new node to the end of the list.
            tail = tail->next;
            current = current->next;
        }
    }

    // Function to swap two nodes in the list by position
    bool swapNodes(int pos1, int pos2) {
        if (pos1 == pos2) return true; // If positions are the same, no need to swap.

        Node* prev1 = nullptr, * prev2 = nullptr, * node1 = head, * node2 = head;

        for (int i = 1; i < pos1 && node1 != nullptr; i++) {
            prev1 = node1;
            node1 = node1->next;
        }

        for (int i = 1; i < pos2 && node2 != nullptr; i++) {
            prev2 = node2;
            node2 = node2->next;
        }

        if (node1 == nullptr || node2 == nullptr) return false; // One of the nodes is out of bounds.

        // If node1 or node2 are head nodes, update head.
        if (prev1 != nullptr) {
            prev1->next = node2;
        } else {
            head = node2;
        }

        if (prev2 != nullptr) {
            prev2->next = node1;
        } else {
            head = node1;
        }

        // Swap the next pointers.
        Node* temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;

        return true;
    }

    // Helper function to insert a node at the end of the list
    void insertNode(int key) {
        Node* newNode = new Node(key);
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

    // Helper function to print the list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->key << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    LinkedList list;

    // Insert some nodes
    list.insertNode(10);
    list.insertNode(-5);
    list.insertNode(15);
    list.insertNode(20);
    list.insertNode(-30);
    list.insertNode(25);

    cout << "Original List: ";
    list.printList();

    // Find the node with the smallest key
    Node* minNode = list.findMinKey();
    if (minNode != nullptr) {
        cout << "Node with smallest key: " << minNode->key << endl;
    }

    // Delete nodes with negative keys
    list.deleteNegativeKeys();
    cout << "After deleting nodes with negative keys: ";
    list.printList();

    // Reinsert nodes for further operations
    list.insertNode(-5);
    list.insertNode(-30);

    // Delete node following a node with a negative key
    list.deleteAfterNegative();
    cout << "After deleting nodes following a node with a negative key: ";
    list.printList();

    // Append the list to itself
    list.appendSelf();
    cout << "After appending the list to itself: ";
    list.printList();

    // Swap nodes at positions 2 and 4
    if (list.swapNodes(2, 4)) {
        cout << "After swapping nodes at positions 2 and 4: ";
        list.printList();
    } else {
        cout << "Swap operation failed." << endl;
    }

    return 0;
}
