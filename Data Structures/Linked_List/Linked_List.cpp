#include <iostream>
using namespace std;

template <typename datatype>
class Node {
    public:
        datatype data;
        Node<datatype> *next = 0;
        bool valid = false;
};

template <typename datatype>
class DoubleLinkedNode: public Node<datatype> {
    public:
        DoubleLinkedNode<datatype> *prev = 0;
        DoubleLinkedNode<datatype> *next = 0;
};

template <typename datatype>
class SinglyLinkedList {
    protected:
        Node<datatype> *headptr;
        Node<datatype> *tailptr;

        int list_length = 0;


    public:
        SinglyLinkedList() {
            cout << "List Created" << endl;
        }

        void add_node(datatype value) {
            // Creating new Node object with reqired value
            Node<datatype> *new_node = new Node<datatype>;
            new_node->data = value;
            new_node->valid = true;
            list_length++;

            // Adding the new value at the end of list if the head has beeen declared
            if (headptr->valid == 1) {
                tailptr->next = new_node;
                tailptr = new_node;
                return;
            }
            
            headptr = new_node;
            tailptr = new_node;
        }

        void print_list() {
            // Creating new pointer to iterate with starting at head;
            Node<datatype> *cur_ptr;
            cur_ptr = headptr;
            cout << "Priting List\n\t";

            if (!cur_ptr->valid) return;

            // Traversing the list printing each value at the time
            while (cur_ptr) {
                cout << cur_ptr->data << " ---> ";
                cur_ptr = cur_ptr->next;
            }
            cout << "END" << endl;
            return ;
        }

        int count_nodes() {
            return list_length;
        }

};

template <typename datatype>
class DoublyLinkedList {
    public:
        DoubleLinkedNode<datatype> *headptr;
        DoubleLinkedNode<datatype> *tailptr;

        int list_length = 0;


    public:
        DoublyLinkedList() {
            cout << "List Created" << endl;
        }

        void add_node(datatype value) {
            // Creating new Node object with reqired value
            DoubleLinkedNode<datatype> *new_node = new DoubleLinkedNode<datatype>;
            new_node->data = value;
            new_node->valid = true;
            new_node->prev = tailptr;
            list_length++;

            // Adding the new value at the end of list if the head has beeen declared
            if (headptr->valid == 1) {
                tailptr->next = new_node;
                tailptr = new_node;
                return;
            }
            
            headptr = new_node;
            tailptr = new_node;
        }

        void print_list() {
            // Creating new pointer to iterate with starting at head;
            DoubleLinkedNode<datatype> *cur_ptr;
            cur_ptr = headptr;
            cout << "Priting List\n\t";

            if (!cur_ptr->valid) return;

            // Traversing the list printing each value at the time
            while (cur_ptr) {
                cout << cur_ptr->data << " ---> ";
                cur_ptr = cur_ptr->next;
            }
            
            cout << "END" << endl;
            return ;
        }

        int count_nodes() {
            return list_length;
        }

};

int main() {
    // DoublyLinkedList<int> list;
    // list.add_node(5);
    // list.add_node(6);
    // list.add_node(7);
    // list.print_list();
}