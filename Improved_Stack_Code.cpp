// Improved_Stack_Code.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Improved Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits
using namespace std;
class Stack
{
private:
    static const int size = 5;
    int top;
    int arr[size];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == size - 1;
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }
    int count()
    {
        return top + 1;
    }
    int peek(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Position out of bounds" << endl;
            return 0;
        }
        else if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        if (pos < 0 || pos >= size)
        {
            cout << "Position out of bounds" << endl;
        }
        else
        {
            arr[pos] = val;
            cout << "Value changed at location " << pos << endl;
        }
    }
    void display()
    {
        cout << "All values in the Stack are: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
    static void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
};
int main()
{
    Stack s1;
    int option, position, value;
    do
    {
        cout << "What operation do you want to perform? Select Option number.Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl << endl;
        while (!(cin >> option))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number" << endl;
        }
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter an item to push in the stack" << endl;
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number" << endl;
            }
            s1.push(value);
            break;
        case 2:
            cout << "Pop Function Called - Popped Value: " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
                cout << "Stack is Empty" << endl;
            else
                cout << "Stack is not Empty" << endl;
            break;
        case 4:
            if (s1.isFull())
                cout << "Stack is Full" << endl;
            else
                cout << "Stack is not Full" << endl;
            break;
        case 5:
            cout << "Enter position of item you want to peek: " << endl;
            while (!(cin >> position))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid position" << endl;
            }
            cout << "Peek Function Called - Value at position " << position << " is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Count Function Called - Number of Items in the Stack are : " << s1.count() << endl;
                      break;
        case 7:
            cout << "Change Function Called - " << endl;
            cout << "Enter position of item you want to change : ";
            while (!(cin >> position))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid position" << endl;
            }
            cout << "Enter value of item you want to change : ";
            while (!(cin >> value))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number" << endl;
            }
            s1.change(position, value);
            break;
        case 8:
            s1.display();
            break;
        case 9:
            Stack::clearScreen();
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);

    return 0;
}