#include<iostream>
using namespace std; 

//快速排序  
void quickSort(int s[], int l, int r) {
    if (l < r) {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
        int i = l, j = r, x = s[l];
        while (i < j) {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数  
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // 递归调用
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
