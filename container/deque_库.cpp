#include<iostream>
#include<deque>
#include<vector>
#include<stdlib.h>
using namespace std;

int main () {
	deque<int> first;
	deque<int> second;
	deque<int> third;
	
	//deque.assign(), deque.begin(), deque.end()
	int myints[] = {1, 2, 3};
	
	first.assign(7, 100); //100, 100, 100, 100, 100, 100, 100
	second.assign(first.begin()+1, first.end()-1); //100, 100, 100, 100, 100
	third.assign(myints, myints+3); //1, 2, 3
	
	//deque.at(), deque.size()
	deque<int> mydeque(10);//0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	for (int i = 0; i < mydeque.size(); i++) {
		mydeque.at(i) = i;
	}// 0 1 2 3 4 5 6 7 8 9
	
	//deque.back(), deque.push_back()
	mydeque.push_back(10);
	while (mydeque.back() != 0) 
		mydeque.push_back(mydeque.back()-1);// 0 1 2 3 4 5 6 7 8 9 10 9 8 7 6 5 4 3 2 1 0
	
	//iterator
	deque<int>::iterator it = mydeque.begin();
	
	while (it != mydeque.end()) {
		cout << " " << *it++;
	}
	cout << endl;
	
	//deque.cbegin(), deque.cend() : const_iterator

	
	//deque.clear()
	mydeque.clear();
	
	//deque.crbegin(), deque.crend()

	
	//deque.empty()
	cout << mydeque.empty() << endl;
	
	//deque.erase()
	mydeque.push_back(10);
	while (mydeque.back() != 0) {
		mydeque.push_back(mydeque.back()-1);
	} 
	
	//erase the 6th element
	mydeque.erase(mydeque.begin()+5);
	//erase the first 3 element
	mydeque.erase(mydeque.begin(), mydeque.begin()+3);
	
	//deque.front()
	cout << mydeque.front() << endl;
	
	//deque.insert()
	mydeque.clear();
	mydeque.push_back(10);//10
	mydeque.insert(mydeque.begin(), 1);//1, 10
	mydeque.insert(mydeque.begin()+1, 3, 5);//1, 5, 5, 5, 10
	
	vector<int> myvector(2, 30);
	mydeque.insert(mydeque.begin()+2, myvector.begin(), myvector.end());//1, 5, 30, 30, 5, 5, 10
	
	//mydeque.max_size(), mydeque.resize()
	if (100 < mydeque.max_size()) mydeque.resize(100);
	
	//operator = ;
	deque<int> anthordeque;
	anthordeque = mydeque;
	
	//operator [];
	mydeque[0] = 1;
	cout << mydeque[0] << endl;
	
	//mydeque.pop_back(), mydeque.pop_front()
	//mydeque.push_back(), mydeque.push_front()
	mydeque.pop_back();
	mydeque.pop_front();
	
	mydeque.push_back(9);
	mydeque.push_front(2);
	
	//mydeque.rbegin(), mydeque.rend()
	deque<int>::reverse_iterator rit;
	rit = mydeque.rbegin();
	rit = mydeque.rend();
	
	//mydeque.resize()
	mydeque.clear();
	
	for (int i = 0; i < 10; i++) mydeque.push_back(i+1);
	
	mydeque.resize(5); // 1, 2, 3, 4, 5
	mydeque.resize(8, 100); //1, 2, 3, 4, 5, 100, 100, 100
	mydeque.resize(12); //1, 2, 3, 4, 5, 100, 100, 100, 0, 0, 0, 0
	
	//mydeque.size()
	cout << mydeque.size();
	
	system("pause");
	return 0;
}
