#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void showlist(list <int> g) {
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

template <typename datatype>
class Queue {
    protected:
        list<datatype> queue;

    public:
        void enque(datatype data) {
            queue.push_back(data);
        }

        datatype deque() {
            datatype data =  queue.front();
            queue.pop_front();
            return data;
        }

        void print_queue() {
            cout << "=== Printing queue ===" << endl;
            showlist(queue);
        }
};

int main() {
    Queue<int> q;
    q.enque(5);
    q.enque(10);
    q.enque(6);
    cout << "deque element: " << q.deque() << endl;
    q.print_queue();
}