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
	
	//���˿��Դ洢�����ͬ����֮�⣬����������set��һ���� 
	
	system("pause");
}
