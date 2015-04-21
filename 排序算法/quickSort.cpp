#include<iostream>
using namespace std; 

//��������  
void quickSort(int s[], int l, int r) {
    if (l < r) {
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ��������
        int i = l, j = r, x = s[l];
        while (i < j) {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // �ݹ����
        quickSort(s, i + 1, r);
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
		quickSort(a, 0, n-1);
		cout << "array after sort: " << endl;
		
		print_array(a, n);
		cout << "input the number of the array: ";
	}
}
