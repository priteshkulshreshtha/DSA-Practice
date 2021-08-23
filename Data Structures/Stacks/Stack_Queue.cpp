#include <iostream>
#include <list>

using namespace std;

template <typename datatype>
class Stack {
    protected:
        list<datatype> stack;

    public:
        void push(datatype data) {
            stack.push_front(data);
        }

        void pop() {
            stack.pop_front();
        }

        datatype peek() {
            return *(stack.begin());
        }

        void print_stack() {
            for (auto i=stack.begin(); i!=stack.end(); i++) {
                cout << *(i) << endl;
            }
        }
};

int main() {
    Stack<int> s;
    s.push(5);
    s.push(6);
    cout << "Top: " << s.peek() << endl;
    s.push(8);
    s.pop();
    s.print_stack();
}