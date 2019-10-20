/*
 * get_min() in O(1)
 * Example using existing c++ stack library
 * 
 * Note:
 *  * Basic error handling is done to make code easier to read.
 *  * Example includes a print method which is not very efficient.   
 */

#include <iostream>
#include <stack>
using namespace std;

class stack_min {

    stack<int> container;
    stack<int> mn;

    public:

    stack_min() {}

    void push(int val) { 
        if(mn.empty() || val < mn.top()) 
            mn.push(val);
        container.push(val);
    }

    int top() {
        return (container.empty())?-1:container.top();
    }

    int get_min() {
        return (mn.empty())?-1:mn.top();
    }

    void pop() {
        if(container.empty()) return;
        if(mn.top() == container.top())
            mn.pop();
        container.pop();
    }

    void print() {
        cout << "Top -> ";
        stack<int> tmp { container };

        while(!tmp.empty()) {

            cout << tmp.top() << " ";
            tmp.pop();
        }
        cout << endl;
    }

};

int main() {
    
    stack_min st;

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
                    st.push(num);
                    st.print();
                    break;

            case 2: st.pop();
                    st.print();
                    break;
            
            case 3: cout << "Top = " << st.top() << endl;
                    break;

            case 4: cout << "Minimum = " << st.get_min() << endl;
                    break;

            default: stop = true;
        }
    }
}


