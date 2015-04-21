#include<set>
#include<iostream>
#include<stdlib.h> 
using namespace std;

int main() {
	int myints[] = {2, 3, 1, 4, 5, 5, 5};
	multiset<int> mymultiset(myints, myints+7);
	
	//mymultiset.begin()
	for (multiset<int>::iterator it = mymultiset.begin(); it != mymultiset.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
	
	//mymultiset.count()
	cout << mymultiset.count(5) << endl;
	
	//除了可以存储多个相同的数之外，其他内容与set是一样的 
	
	system("pause");
}
