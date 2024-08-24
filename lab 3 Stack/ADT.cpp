#include <iostream>

// Node class representing each element in the stack
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class representing the stack ADT
class Stack {
private:
    Node* top;  // Pointer to the top of the stack
    int size;   // Size of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Destructor to destroy the stack
    ~Stack() {
        Destroy();
    }

    // Push function to add an element to the stack
    void Push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop function to remove an element from the stack
    void Pop() {
        if (IsEmpty()) {
            std::cout << "Stack Underflow!" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // Function to get the current size of the stack
    int Size() const {
        return size;
    }

    // Function to check if the stack is empty
    bool IsEmpty() const {
        return top == nullptr;
    }

    // Function to return the top element of the stack
    int Top() const {
        if (IsEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;  // Return an invalid value to indicate an error
        }
        return top->data;
    }

    // Function to destroy the stack and free memory
    void Destroy() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    // Function to print all elements in the stack
    void PrintStack() const {
        Node* current = top;
        std::cout << "Stack elements (top to bottom): ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


int main() {
    // Example usage of the Stack ADT
    Stack stack;

    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    std::cout << "Top element: " << stack.Top() << std::endl;  // Output: 30
    std::cout << "Stack size: " << stack.Size() << std::endl;  // Output: 3

    stack.Pop();
    std::cout << "Top element after pop: " << stack.Top() << std::endl;  // Output: 20

    stack.Destroy();
    std::cout << "Stack size after destroy: " << stack.Size() << std::endl;  // Output: 0

    return 0;
}

