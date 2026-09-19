#include <iostream>
using namespace std;
// this is my C++
class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 99;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = rear + 1;
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
    }

    int peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.printQueue();

    cout << "Front element: " << q.peekFront() << endl;

    q.dequeue();
    cout << "After dequeue, Queue: ";
    q.printQueue();

    cout << "Front element: " << q.peekFront() << endl;

    return 0;
}