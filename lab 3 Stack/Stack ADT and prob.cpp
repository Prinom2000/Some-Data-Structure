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

// Function to copy elements from one stack to another
void copyStack(Stack& source, Stack& destination) {     // &=passing a reference to the original variable rather than a copy.
    Stack temp;

    // Move elements from source to temp
    while (!source.IsEmpty()) {
        temp.Push(source.Top());
        source.Pop();
    }

    // Move elements from temp to both source and destination
    while (!temp.IsEmpty()) {
        int value = temp.Top();
        source.Push(value);
        destination.Push(value);
        temp.Pop();
    }
}

//3
// Function to convert a decimal number to binary using stack
void DecimalToBinary(int decimal) {
    Stack stack;

    // Process to convert decimal to binary
    while (decimal > 0) {
        int remainder = decimal % 2;
        stack.Push(remainder);
        decimal /= 2;
    }

    // Print the binary number by popping elements from the stack
    std::cout << "Binary: ";
    stack.PrintStack();
}


//4
// Function to reverse the contents of a stack
void ReverseStack(Stack& stack) {
    Stack tempStack;

    // Move all elements from the original stack to the temporary stack
    while (!stack.IsEmpty()) {
        tempStack.Push(stack.Top());
        stack.Pop();
    }

    // Now tempStack contains the elements in reverse order
    stack = tempStack;
}


//5
bool isBalanced(const std::string& expression) {
    Stack stack;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.Push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.IsEmpty()) {
                return false;
            }

            char top = stack.Top();
            stack.Pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                {
                return false;
            }
        }
    }

    // If stack is not empty, then parentheses are unbalanced
    return stack.IsEmpty();
}
///////////////////////////////////////////////////////////////////////////////////


int main() {
    Stack source;
    Stack destination;

    // Push elements into the source stack
    source.Push(1);
    source.Push(2);
    source.Push(3);


    //2
    // Print the source stack
    std::cout << "Source stack before copying:" << std::endl;
    source.PrintStack();

    // Copy elements from source stack to destination stack
    copyStack(source, destination);

    // Print the source and destination stacks
    std::cout << "Source stack after copying:" << std::endl;
    source.PrintStack();

    std::cout << "Destination stack after copying:" << std::endl;
    destination.PrintStack();

    //3
    int number;

    // Input: decimal number
    std::cout << "Enter a decimal number: ";
    std::cin >> number;

    // Convert to binary
    DecimalToBinary(number);

    //4
    Stack s;

    // Push elements into the stack
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    std::cout << "Original Stack: ";
    s.PrintStack();

    // Reverse the stack
    ReverseStack(s);

    std::cout << "Reversed Stack: ";
    s.PrintStack();



    //5
    std::string expression;

    std::cout << "Enter an expression: ";
    std::cin >> expression;

    if (isBalanced(expression)) {
        std::cout << "The expression is balanced." << std::endl;
    } else {
        std::cout << "The expression is not balanced." << std::endl;
    }



    return 0;
}
