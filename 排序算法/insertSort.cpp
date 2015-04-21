#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
	int tem = a;
	a = b;
	b = tem;
} 

void insertSort(int a[], int n) {  
    int i, j;  
    for (i = 1; i < n; i++)  
        for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)  
            Swap(a[j], a[j + 1]);  
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
		insertSort(a, n);
		cout << "array after sort: " << endl;
		print_array(a, n);
		
		cout << "input the number of the array: ";
	}
	
} 
