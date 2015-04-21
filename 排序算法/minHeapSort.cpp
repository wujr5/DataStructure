#include<iostream>
using namespace std;

//  �¼���i���  �丸���Ϊ(i - 1) / 2  
void MinHeapFixup(int a[], int i) {  
    int j, temp;  
      
    temp = a[i];  
    j = (i - 1) / 2;      //�����  
    while (j >= 0 && i != 0) {  
        if (a[j] <= temp)  
            break;  
          
        a[i] = a[j];     //�ѽϴ���ӽ�������ƶ�,�滻�����ӽ��  
        i = j;  
        j = (i - 1) / 2;  
    }  
    a[i] = temp;  
}

/*����̵ı��Ϊ��
void MinHeapFixup(int a[], int i) {  
    for (int j = (i - 1) / 2; (j >= 0 && i != 0) && a[i] > a[j]; i = j, j = (i - 1) / 2)  
        Swap(a[i], a[j]);
}
*/

//����С���м����µ�����nNum
void MinHeapAddNumber(int a[], int n, int nNum) {  
    a[n] = nNum;
    MinHeapFixup(a, n);
}

//  ��i�ڵ㿪ʼ����,nΪ�ڵ����� ��0��ʼ���� i�ڵ���ӽڵ�Ϊ 2*i+1, 2*i+2  
void MinHeapFixdown(int a[], int i, int n) {
    int j, temp;

    temp = a[i];
    j = 2 * i + 1;
    while (j < n) {
        if (j + 1 < n && a[j + 1] < a[j]) //�����Һ���������С��
            j++;

        if (a[j] >= temp)  
            break;

        a[i] = a[j];     //�ѽ�С���ӽ�������ƶ�,�滻���ĸ����  
        i = j;  
        j = 2 * i + 1;  
    }  
    a[i] = temp;  
}
//����С����ɾ����  
void MinHeapDeleteNumber(int a[], int n) {
    Swap(a[0], a[n - 1]);  
    MinHeapFixdown(a, 0, n - 1);  
}

//������С��  
void MakeMinHeap(int a[], int n) {  
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapFixdown(a, i, n);
}

void MinheapsortTodescendarray(int a[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        Swap(a[i], a[0]);
        MinHeapFixdown(a, 0, i);
    }
}

void print_array(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[200];
	int n;
	
	cout << "input the number of the array: ";
	while (cin >> n) {
		cout << "input " << n << " numbers: " << endl;
		
		for (int i = 0; i < n; i++) {
			int tem;
			cin >> tem;
			a[i] = tem;
		}
		mergeSort(a, n);
		cout << "array after sort: " << endl;
		print_array(a, n);
		
		cout << "input the number of the array: ";
	}
	return 0;
}

