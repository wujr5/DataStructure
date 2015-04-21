#include<iostream>
#include<map>
#include<stdlib.h>
using namespace std;

int main() {
	map<string, int> mymap;
	
	//operator[]
	mymap["a"] = 0;
	mymap["b"] = 1;
	mymap["c"] = 2;
	
	//mymap.at()
	mymap.at("a") = 10;
	
	//mymap.begin(), mymap.end()
	map<string, int>::iterator it = mymap.begin();
	for (; it != mymap.end(); it++) {
		cout << it->first << "=>" << it->second << endl;
	}
	
	//mymap.clear()
	mymap.clear();
	
	//mymap.count()
	if (mymap.count("a") > 0) {
		cout << "a is an element of mymap" << endl;
	} else {
		cout << "a is not an element of mymap" << endl;
	}
	
	//mymap.empty()
	cout << mymap.empty() << endl;
	
	while (!mymap.empty()) {
		cout << mymap.begin()->first << "=>" << mymap.begin()->second << endl;
		mymap.erase(mymap.begin());
	}
	
	//mymap.erase(), mymap.find()
	mymap["a"] = 1;
	mymap["b"] = 2;
	mymap["c"] = 3;
	
	it = mymap.find("b");
	mymap.erase(it); //erasing by iterator
	mymap.erase("c"); //erasing by key
	
	it = mymap.find("a");
	mymap.erase(it, mymap.end());//erasing by range
	
	//mymap.insert()
	mymap.clear();
	
	//insert: single parameter
	mymap.insert(pair<string, int>("a", 1));
	mymap.insert(pair<string, int>("b", 2));
	mymap.insert(pair<string, int>("c", 3));
	
	pair<map<string, int>::iterator, bool> ret;
	ret = mymap.insert(pair<string, int>("c", 3));
	if (ret.second == false) {
		cout << "c is already exited with a value of " << ret.first->second << endl;
	}
	
	//insert: hint position
	it = mymap.begin();
	mymap.insert(it, pair<string, int>("d", 4));
	mymap.insert(it, pair<string, int>("e", 5));
	
	//insert: range insertion
	map<string, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find("c"));
	
	//mymap.lower_bound(), mymap.upper_bound()
	it = mymap.lower_bound("b"); // points to b
	it = mymap.upper_bound("d"); //points to e
	
	mymap.erase(mymap.lower_bound("b"), mymap.upper_bound("d"));//erase[lower, upper)
	
	
	//mymap.max_size()
	if (mymap.max_size() > 1000) {
		for (int i = 0; i < 1000; i++) mymap["a"+i] = i;
	}
	
	//operator =
	map<string, int> a;
	a = mymap;
	
	//mymap.size()
	cout << mymap.size() << endl;
	
	
	system("pause");
}
