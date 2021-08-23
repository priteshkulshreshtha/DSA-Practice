#include <iostream>
using namespace std;

template <typename datatype, int length>
class Stack {
    protected:
        datatype stack[length];
        int top = 0;

    public:
        void push(datatype data) {
            if (isFull()) {
                cout << "Overflow" << endl;
                return;
            }

            stack[top++] = data;
            return;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Underflow" << endl;
                return;
            }

            top--;
            return;
        }

        datatype peek() {
            return stack[top - 1];
        }

        bool isEmpty() {
            return top == 0;
        }

        bool isFull() {
            return top >= length; 
        }

        void print_stack() {
            cout << "Printing" << endl;
            for(int i=0; i<top; i++) {
                cout << stack[i] << endl;
            }
        }
};

int main() {
    Stack<int, 5> s;
    s.push(5);
    s.push(6);
    cout << "Top: " << s.peek() << endl;
    s.push(8);
    s.pop();
    s.print_stack();
}