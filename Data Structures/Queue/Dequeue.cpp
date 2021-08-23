#include <iostream>
using namespace std;

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

template <typename datatype, int maxLength>
class Dequeue {
    protected:
        datatype queue[maxLength];
        int head = -1;
        int tail = -1;
        int size = 0;

    public:
        bool isFull() {
            return (tail+1)%maxLength == head;
        }

        void insertFront(datatype data) {

            if (head==-1 && tail==-1) {
                head = 0;
                tail = 0;
                queue[head] = data;
                return;
            }

            if (isFull()) {
                cout << "Overflow" << endl;
                return;
            }

            head = mod(head-1, maxLength);
            queue[head] = data;
            size++;
            return;
        }

        void insertLast(datatype data) {

            if (head==-1 && tail==-1) {
                head = 0;
                tail = 0;
                queue[head] = data;
                return;
            }

            if (isFull()) {
                cout << "Overflow" << endl;
                return;
            }

            tail = (tail+1)%maxLength;
            queue[tail] = data;
            size++;
            return;
        }

    void print_queue() {
        cout << "Printing" << endl;
        for(int i=head; i<=head+size; i++) {
            cout << queue[i%maxLength] << endl;
        }
    }

    void deleteFront() {
        head = (head+1)%maxLength;
        size--;
        return;
    }

    void deleteLast() {
        tail = mod(tail-1, maxLength);
        size--;
        return;
    }

    datatype getFront() {
        return queue[head];
    }
    
    datatype getRear() {
        return queue[tail];
    }

    bool isEmpty() {
        return size==0;
    }
};

int main() {
    Dequeue<int, 5> q;
    q.insertFront(5);
    q.insertFront(5);
    q.insertLast(7);
    q.insertFront(5);
    q.insertLast(7);
    q.insertLast(7);
    q.deleteLast();
    cout << q.getRear() << endl;
    q.print_queue();
}

        