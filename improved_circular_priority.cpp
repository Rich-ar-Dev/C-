#include <iostream>
#include <queue> // Include priority_queue
using namespace std;

class PriorityQueue
{
private:
    priority_queue<int> pq; // Use priority_queue to implement priority queue

public:

    bool isEmpty()
    {
        return pq.empty();
    }

    void enqueue(int val)
    {
        pq.push(val);
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1; // Return some default value indicating empty queue
        }
        int x = pq.top();
        pq.pop();
        return x;
    }

    int count()
    {
        return pq.size();
    }

    void display()
    {
        cout << "All values in the Queue are - " << endl;
        priority_queue<int> temp = pq; // Make a copy to preserve the original
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue q1;
    int value, option;
    do
    {
        cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. Count()" << endl;
        cout << "5. Display()" << endl;
        cout << "6. Clear Screen" << endl
             << endl;
        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
            break;
        case 5:
            cout << "Display Function Called - " << endl;
            q1.display();
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
