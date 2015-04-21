#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int main() {
	vector<int> myvector;
	vector<int> first;
	int myints[] = {1, 2, 3, 4, 5};
	
	//myvector.assign()
	myvector.assign(7, 100);
	first.assign(myvector.begin()+1, myvector.end()-1);
	myvector.assign(myints, myints+5);
	cout << myvector.size() << endl;
	
	//myvector.at()
	myvector.at(1) = 100;
	cout << myvector.at(1) << endl;
	
	//myvector.back()
	cout << myvector.back() << endl;
	myvector.back() = 100;
	
	//myvector.begin(), myvector.end()
	for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
	
	//myvector.clear(), myvector.empty()
	myvector.clear();
	cout << myvector.empty() << endl;
	
	//myvector.erase()
	for (int i = 0; i < 10; i++) myvector.back() = i;
	
	myvector.erase(myvector.begin());
	myvector.erase(myvector.begin(), myvector.begin()+3);
	
	//myvector.front()
	myvector.front() = 100;
	cout << myvector.front() << endl;
	
	//myvector.insert()
	myvector.insert(myvector.begin(), 200);
	
	first.clear();
	first.assign(5, 100);
	
	myvector.insert(myvector.begin()+1, first.begin(), first.end());
	
	myvector.insert(myvector.begin(), myints, myints+5);
	
	//operator = []
	first = myvector;
	cout << myvector[0] << endl;
	
	//myvector.pop_back()
	myvector.pop_back();
	
	//myvector.push_back()
	myvector.push_back(1000);
	
	//myvector.size()
	cout << myvector.size() << endl;
	
	
	system("pause");
	
} 
