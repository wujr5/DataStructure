#include<iostream>
#include<queue>
using namespace std; 

int main() {
	queue<int> myqueue;
	
	//myqueue.push(int val), myqueue.back()
	myqueue.push(10);
	cout << "myqueue.back() is : " << myqueue.back() << endl;
	myqueue.back() = 50;
	cout << myqueue.back() << endl;

	//myqueue.empty()
	cout << "Is myqueue empty? " << myqueue.empty() << endl;
	
	//myqueue.front()
	cout << "myqueue.front() is : " << myqueue.front() << endl;
	myqueue.front() = 100;
	cout << myqueue.front() << endl; 
	
	//myqueue.pop()
	myqueue.push(20);
	myqueue.pop();
	cout << "After myqueue.pop(), myqueue.front() is : " << myqueue.front() << endl;
	
	//myqueue.size()
	cout << "myqueue.size() is : " << myqueue.size() << endl;
	
	int a;
	cin >> a;
}
