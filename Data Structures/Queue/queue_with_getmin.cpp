/*
 * get_min() in O(1)
 * Example using existing c++ deque library
 * 
 * Note:
 *  * Basic error handling is done to make code easier to read.
 */

#include <iostream>
#include <deque>
using namespace std;

class queue_min {

    deque<int> container;
    deque<int> mn;

    public:

    queue_min() {}

    void push(int val) { 
        container.push_back(val);
        while(!mn.empty() && mn.back() > val)
            mn.pop_back();
        mn.push_back(val);
    }

    int top() {
        return (container.empty())?-1:container.front();
    }

    int get_min() {
        return (mn.empty())?-1:mn.front();
    }

    void pop() {
        if(container.empty()) return;
        if(mn.front() == container.front())
            mn.pop_front();
        container.pop_front();
    }

    void print() {
        cout << "Top -> ";
        for(auto x: container)
            cout << x << " ";
        cout << endl;
    }

};

int main() {
    
    queue_min qm;

    bool stop = false;

    while(!stop) {

        cout << "Choices : \n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Top Element\n"
             << "4. Get Minimum\n"
             << "5. Exit" << endl;

        cout << "Enter option: ";
        int opt;
        cin >> opt;
        int num;
        switch(opt) {

            case 1: cout << "Number = ";
                    cin >> num;
                    qm.push(num);
                    qm.print();
                    break;

            case 2: qm.pop();
                    qm.print();
                    break;
            
            case 3: cout << "Top = " << qm.top() << endl;
                    break;

            case 4: cout << "Minimum = " << qm.get_min() << endl;
                    break;

            default: stop = true;
        }
    }
}


