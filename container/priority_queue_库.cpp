#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

int main() {
	priority_queue<int> mypq;
	
	//mypq.empty()
	cout << mypq.empty() << endl;
	
	//mypq.push(), mypq.pop()
	mypq.push(10);
	mypq.push(20);
	mypq.push(30);
	mypq.pop();
	
	//mypq.top()
	cout << mypq.top() << endl;
	
	//mypq.size()
	cout << mypq.size() << endl;
	
	//traverse
	while (!mypq.empty()) {
		//use mypq.top() to do something
		mypq.pop();
	}
	
	system("pause");
}
