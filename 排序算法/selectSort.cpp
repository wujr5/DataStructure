#include<iostream>
using namespace std;

void Swap(int &a, int &b) {
	int tem = a;
	a = b;
	b = tem;
}

void selectSort(int a[], int n) {  
    int i, j, nMinIndex;  
    for (i = 0; i < n; i++)  {  
        nMinIndex = i; //����СԪ�ص�λ��  
        for (j = i + 1; j < n; j++)  
            if (a[j] < a[nMinIndex])  
                nMinIndex = j;  
        Swap(a[i], a[nMinIndex]); //�����Ԫ�طŵ��������Ŀ�ͷ  
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
		selectSort(a, n);
		cout << "array after sort: " << endl;
		print_array(a, n);
		
		cout << "input the number of the array: ";
	}
	
} 
