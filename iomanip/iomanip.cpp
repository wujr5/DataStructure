#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

//setiosflags(ios: ...)

int main() {
	int a = 10;
	//dec, hex, oct
	cout << dec << a << endl;
	cout << hex << a << endl;
	cout << oct << a << endl;
	
	//setbase(): 8, 10, 16
	cout << setbase(8) << a << endl;
	cout << setbase(10) << a << endl;
	cout << setbase(16) << a << endl;
	
	//left, right, setw(), setfill()
	cout << left << setbase(10) << setw(5) << setfill('0') << a << endl;
	cout << right << setw(5) << setfill('0') << a << endl;
	
	//fixed, resetiosflags(ios::...), scientific, showpos, uppercase, setprecision() 
	double b = 10.1234567;
	cout << b << endl;
	cout << fixed << setprecision(5) << b << endl;
	cout << resetiosflags(ios::fixed) << setprecision(5) << b << endl;
	cout << scientific << b << endl;
	cout << uppercase << scientific << b << endl;
	cout << resetiosflags(ios::scientific) << showpos << b << endl;
	
	//skipws
	char e, f, g;
	cin >> skipws >> e >> f >> g;
	cout << e << f << g << endl;
	
	
	
	system("pause");
}
