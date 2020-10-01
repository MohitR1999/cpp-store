#include <iostream>
#include "Stack.cpp"
using namespace std;


int main()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	return 0;
}
