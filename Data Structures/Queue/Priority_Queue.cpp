#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template <typename datatype>
class PriorityQueue {
    protected:
        vector<pair<int, datatype>> queue;
        

    public:
        void insert(int priority, datatype data) {
            auto i = queue.begin();
            for (i; i != queue.end(); ++i)
                if ((*i).first < priority) break;

            pair<int, datatype> new_element(priority, data);
            queue.insert(i, new_element);
        }

        void print_queue() {
            if (queue.empty()) return;

            cout << "( Priority\t|\tData )" << endl;
            for (auto i = queue.begin(); i != queue.end(); ++i) {
                cout << "( " << (*i).first << "\t|\t" << (*i).second << " )" << endl;
            }
        }

        datatype getHighestPriority() {
            return (*(queue.begin())).second;
        }

        void removeHighestPriority() {
            if (queue.empty()) return;
            
            queue.erase(queue.begin());
            return;
        }
};


int main() {
    PriorityQueue<int> q;
    q.print_queue();
    q.removeHighestPriority();
    q.insert(5, 3);
    q.insert(5, 5);
    q.print_queue();
    cout << q.getHighestPriority() << endl;
    q.removeHighestPriority();
    q.print_queue();
    return 0;
}


