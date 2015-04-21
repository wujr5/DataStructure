#include<iostream>
#include<stdlib.h>
#include<set>
using namespace std;

int main() {
	int myints[] = {1, 5, 3, 2, 4};
	set<int> myset(myints, myints+5);
	
	//myset.begin(), myset.end()
	cout << "myset contains: ";
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
		cout << " " << *it;
	}
	cout << endl;
	
	//myset.clear()
	myset.clear();
	
	for (int i = 0; i < 5; i++) myset.insert(i);
	
	//myset.count()
	cout << myset.count(3) << endl;
	cout << myset.count(5) << endl;
	
	myset.insert(3);
	
	cout << myset.count(3) << endl;
	
	for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
		cout << " " << *it;
	} 
	cout << endl;
	
	//myset.empty()
	cout << myset.empty() << endl;
	
	//myset.erase()
	myset.erase(myset.begin());
	myset.erase(3);
	myset.erase(myset.begin(), myset.end());	
	
	cout << myset.empty() << endl;
	
	//myset.find()
	for (int i = 0; i < 5; i++) myset.insert(i);
	
	set<int>::iterator it = myset.find(2);
	myset.erase(it);
	cout << myset.count(2) << endl;
	
	//myset.insert()
	it = myset.find(3);
	myset.insert(it, 10);
	myset.insert(it, 20);
	
	myset.insert(myints, myints+5);
	
	//operator = 
	set<int> a = myset;
	
	//myset.size()
	cout << myset.size() << endl;
	
	system("pause");
	return 0;
}
