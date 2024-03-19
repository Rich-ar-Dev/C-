#include <iostream>
#include <queue>
using namespace std;

struct QueueElement {
    int value; 
   int priority;

    // Parameterized constructor
    QueueElement(int v, int p) : value(v), priority(p) {}

    // Default constructor
    QueueElement() : value(0), priority(0) {}
};

class PriorityQueue {
private:
    int front;
    int rear;
    QueueElement arr[5];
    int itemCount;

public:
    PriorityQueue() {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = QueueElement(); // Use default constructor
        }
    }

   bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % 5 == front);
    }

    void enqueue(int val, int priority) {
        if (isFull()) {
            cout << "Queue full" << endl;
            return;
        } else if (isEmpty()) {
            rear = 0;
            front = 0;
            arr[rear] = QueueElement(val, priority);
        } else {
            rear = (rear + 1) % 5;
            arr[rear] = QueueElement(val, priority);
        }
        itemCount++;
        reorder();
    }

    QueueElement dequeue() {
        QueueElement x(0, 0);
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return x;
        } else if (rear == front) {
            x = arr[rear];
            rear = -1;
            front = -1;
            itemCount--;
            return x;
        } else {
            x = arr[front];
            front = (front + 1) % 5;
            itemCount--;
            return x;
        }
    }

    void reorder() {
        // Bubble sort (can be optimized for larger queues)
        for (int i = 0; i < itemCount; i++) {
            for (int j = 0; j < itemCount - i - 1; j++) {
                if (arr[j].priority < arr[j + 1].priority) {
                    // Swap elements
                    QueueElement temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    int count() {
        return itemCount;
    }

    void display() {
        cout << "All values in the Queue are - " << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << "Value: " << arr[i].value << ", Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue q1;
    int option;

    do {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;
        cin >> option;

        switch (option) {
            case 0:
                break;
            case 1: {
                int value, priority;
                cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
                cout << "Value: ";
                cin >> value;
                cout << "Priority: ";
                cin >> priority;
                q1.enqueue(value, priority);
                break;
            }
            case 2: {
                QueueElement dequeued = q1.dequeue();
                cout << "Dequeue Operation \nDequeued Value : " << dequeued.value << ", Priority: " << dequeued.priority << endl;
                break;
            }
            case 3:
                if (q1.isEmpty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            case 4:
                if (q1.isFull())
                    cout << "Queue is Full" << endl;
                else
                    cout << "Queue is not Full" << endl;
                break;
            case 5:
                cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
                break;
            case 6:
                cout << "Display Function Called - " << endl;
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);

    return 0;
}