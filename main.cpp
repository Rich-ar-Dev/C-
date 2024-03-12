#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int top;
    int arr[5]; // Assuming a fixed size for simplicity

public:
    Stack() : top(-1) { // Initializer list for top
        fill_n(arr, 5, 0); // Initialize array to 0
    }

    bool isEmpty() const {
        return top == -1;
    }
    
    bool isFull() const {
        return top == 4; // Assuming array size is 5
    }

    void push(int val) {
        if (!isFull()) {
            arr[++top] = val; // Increment top and assign value
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            int popValue = arr[top];
            arr[top--] = 0; // Retrieve top value and decrement top
            return popValue;
        } else {
            cout << "Stack underflow" << endl;
            return 0;
        }
    }

    int count() const {
        return top + 1;
    }
    
    int peek(int pos) const {
        if (!isEmpty() && pos <= top && pos >= 0) {
            return arr[pos];
        } else {
            cout << "Invalid position or stack underflow" << endl;
            return 0;
        }
    }

    void change(int pos, int val) {
        if (pos <= top && pos >= 0) {
            arr[pos] = val;
            cout << "Value changed at location " << pos << endl;
        } else {
            cout << "Invalid position" << endl;
        }
    }

    void display() const {
        cout << "All values in the Stack:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s1;
    int option, position, value;
    do {
        cout << "What operation do you want to perform? Enter 0 to exit." << endl;
        cout << "1. Push()\n2. Pop()\n3. isEmpty()\n4. isFull()\n5. peek()\n6.count()\n7.change()\n8.display()\n9.Clear Screen " << endl;

        cin >> option;
        switch (option) {
        case 1:
            cout << "Enter an item to push in the stack:" << endl;
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Pop Function Called - Popped Value: " << s1.pop() << endl;
            break;
        // Additional cases remain similar to the original code
        case 9:
            system("clear"); // Use "cls" for Windows
            break;
        default:
            cout << "Enter Proper Option number" << endl;
        }
    } while (option != 0);

    return 0;
}