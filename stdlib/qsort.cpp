#include<iostream>
#include<stdlib.h>
using namespace std;

int comp(const void* a,const void* b) {
	return (*(int*)a-*(int*)b);
}
int comp2(const void* a,const void* b) {
	return (*(int*)b-*(int*)a);
}
int comp1 (const void * a, const void * b)
{
  if ( *(double*)a < *(double*)b ) return 1;
  if ( *(double*)a == *(double*)b ) return 0;
  if ( *(double*)a > *(double*)b ) return -1;
}

int main() {
	int v[] = {1, 2, 3, 4, 5, 6};
	double c[] = {1.1111, 2.4444, 1.0000, 4.5555, 8.2222, 3.4444};
	
	qsort(v, 6, sizeof(int), comp);
	
	for (int i = 0; i < 6; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	qsort(v, 6, sizeof(int), comp2);
	
	for (int i = 0; i < 6; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	qsort(c, 6, sizeof(double), comp1);
	
	for (int i = 0; i < 6; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	
	system("pause");
}
