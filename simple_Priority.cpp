#include <iostream>
#include <queue>
using namespace std;

// Structure to represent each item in the priority queue
struct PQItem {
    int value;
    int priority;

    // Constructor
    PQItem(int val, int prio) : value(val), priority(prio) {}

    // Overloading '<' operator for comparison
    bool operator<(const PQItem& other) const {
        // Higher priority items have lower priority values
        return priority > other.priority;
    }
};

class PriorityQueue {
private:
    priority_queue<PQItem> pq;

public:
    // Function to enqueue an item with priority
    void enqueue(int val, int priority) {
        pq.push(PQItem(val, priority));
    }

    // Function to dequeue the item with the highest priority
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1; // Return -1 or any other error value
        }
        int val = pq.top().value; // Extract value from the item with highest priority
        pq.pop(); // Remove the item
        return val;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return pq.empty();
    }

    // Function to display all values in the priority queue
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is Empty" << endl;
            return;
        }
        cout << "All values in the Priority Queue are: ";
        priority_queue<PQItem> temp = pq; // Create a copy of the priority queue
        while (!temp.empty()) {
            cout << temp.top().value << " "; // Display the value of each item
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq1;
    int value, priority, option;
    do {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. Display()" << endl;
        cout << "0. Exit" << endl;

        cin >> option;

        switch (option) {
        case 0:
            break;
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cout << "Enter priority: ";
            cin >> priority;
            pq1.enqueue(value, priority);
            break;
        case 2:
            cout << "Dequeued value: " << pq1.dequeue() << endl;
            break;
        case 3:
            if (pq1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            pq1.display();
            break;
        default:
            cout << "Enter Proper Option number " << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
