#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
	int tem = a;
	a = b;
	b = tem;
}

void bubbleSort(int *a, int n) {
	int j, k;
	int flag;
	
	flag = n;
	while (flag > 0) {
		k = flag;
		flag = 0;
		for (j = 1; j < k; j++) {
			if (a[j-1] > a[j]) {
				Swap(a[j-1], a[j]);
				flag = j;
			}
		}
	}
}

void print_array(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[100];
	int n;
	
	cout << "input the number of the array: ";
	while (cin >> n) {
		cout << "input " << n << " numbers :" << endl;
		for (int i = 0; i < n; i++) {
			int tem;
			cin >> tem;
			a[i] = tem;
		}
		bubbleSort(a, n);
		cout << "array after sort: " << endl;
		print_array(a, n);
		
		cout << "input the number of the array: ";
	}
	
} 
