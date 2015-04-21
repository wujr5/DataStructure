#include<iostream>
using namespace std;

void move(int count, int start, int finish, int temp) {
	if (count > 0) {
		move(count-1, start, temp, finish);
		cout << "Move disk " << count << " from " << start << " to " << finish << "." << endl;
		move(count-1, temp, finish, start);
	}
}

int main() {
	int n;
	cout << "input the number of the disk: ";
	while (cin >> n) {
		move(n, 1, 3, 2);
		cout << "\nDone!\n\ninput the number of the disk: ";
	}
}

