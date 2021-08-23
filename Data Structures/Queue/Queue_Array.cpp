#include <iostream>
using namespace std;

template <typename datatype, int length>
class Queue {
    protected:
        datatype queue[length];
        int head = -1;
        int tail = -1;
        int size = 0;

    public:
        Queue() {
            cout << "Created Queue" << endl;
        }

        void enqueue(datatype data) {
            if (head==-1) head++;
            if (tail >= length - 1) {
                cout << "OverFlow" << endl;
                return;
            }

            queue[++tail] = data;
            size++;
            return;
        }

        datatype dequeue() {
            if (head == tail) {
                cout << "UnderFlow" << endl;
                return 0;
            }
            size--;
            return queue[head++];
        }

        void print_queue() {
            if (head == tail) return;
            for(int i=head; i<=tail; i++) cout << queue[i] << endl;
        }

        int get_length() {
            return size;
        }
};


template <typename datatype, int length>
class CircularQueue: public Queue<datatype, length> {
    public:
        void enqueue(datatype data) {
            if (Queue<datatype, length>::size >= length) {
                cout << "OverFlow" << endl;
                return;
            }

            if (Queue<datatype, length>::head==-1) {
                Queue<datatype, length>::head++;
            }
       
            Queue<datatype, length>::tail = (Queue<datatype, length>::tail+1)%length;
            Queue<datatype, length>::queue[Queue<datatype, length>::tail] = data;
            Queue<datatype, length>::size++;
            return;            
        }

        int dequeue() {
            if (Queue<datatype, length>::head == Queue<datatype, length>::tail) {
                cout << "UnderFlow: ";
                return 0;
            }
            Queue<datatype, length>::size--;
            int last_head = Queue<datatype, length>::head; 
            Queue<datatype, length>::head = (Queue<datatype, length>::head+1)%length;
            return Queue<datatype, length>::queue[last_head];
        }

        void print_queue() {
            if (Queue<datatype, length>::size == 0) return;
            for(int i = Queue<datatype, length>::head; i < Queue<datatype, length>::head + Queue<datatype, length>::size; i++)  {
                    cout << Queue<datatype, length>::queue[i%length] << endl;
                }
        }

};


int main() {
    CircularQueue<int, 2> q;
    q.enqueue(2);
    q.enqueue(4);
    cout << "Deque " << q.dequeue() << endl;
    q.enqueue(10);
    
    cout << "Length " << q.get_length() << endl;;
    cout << "=== Printing Queue ===" << endl;
    q.print_queue();
}