#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> mystack;
	
	//mystack.empty(), mystack.top(), mystack.pop(), mystack.push()
	cout << mystack.empty() << endl;
	
	for (int i = 0; i < 10; i++) mystack.push(i);
	
	int sum = 0;
	while (!mystack.empty()) {
		sum += mystack.top();
		mystack.pop();
	}
	
	//mystack.size()
	cout << mystack.size() << endl;
	
}
