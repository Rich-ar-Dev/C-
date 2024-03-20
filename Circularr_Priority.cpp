#include <iostream>
#include <queue>
using namespace std;

class PriorityQueue {
private:
    priority_queue<int> pq;

public:
    void enqueue(int val) {
        pq.push(val);
    }

    int dequeue() {
        if (pq.empty()) {
            cout << "Queue is Empty" << endl;
            return 0; // Return a default value or throw an exception in a real-world scenario
        }
        int top = pq.top();
        pq.pop();
        return top;
    }

    bool isEmpty() {
        return pq.empty();
    }

    int count() {
        return pq.size();
    }

    void display() {
        priority_queue<int> temp = pq;
        cout << "All values in the Queue are - " << endl;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq1;
    int value, option;
    do {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. count()" << endl;
        cout << "5. display()" << endl;
        cout << "6. Clear Screen" << endl << endl;
        cin >> option;
        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
                cin >> value;
                pq1.enqueue(value);
                break;
            case 2:
                cout << "Dequeue Operation \nDequeued Value : " << pq1.dequeue() << endl;
                break;
            case 3:
                if (pq1.isEmpty())
                    cout << "Queue is Empty" << endl;
                else
                    cout << "Queue is not Empty" << endl;
                break;
            case 4:
                cout << "Count Operation \nCount of items in Queue : " << pq1.count() << endl;
                break;
            case 5:
                cout << "Display Function Called - " << endl;
                pq1.display();
                break;
            case 6:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option number " << endl;
        }
    } while (option != 0);
    return 0;
}
