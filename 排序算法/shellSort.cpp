#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
	int tem = a;
	a = b;
	b = tem;
}

void shellSort(int a[], int n) {  
    int i, j, gap;  
  
    for (gap = n / 2; gap > 0; gap /= 2)  
        for (i = gap; i < n; i++)  
            for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)  
                Swap(a[j], a[j + gap]);
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
		shellSort(a, n);
		cout << "array after sort: " << endl;
		print_array(a, n);
		
		cout << "input the number of the array: ";
	}
	
} 
