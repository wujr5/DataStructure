#include<stack>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main() {
	string s;
	int t;
	cin >> t;
	getline(cin, s);
	
	while (t--) {
		getline(cin, s);
		stack<char> d;
		bool flag = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				d.push(s[i]);
			} 
			else if (s[i] == ')') {
				if (!d.empty() && d.top() == '(') {
					d.pop();
				}
				else if (d.empty() || !d.empty() && (d.top() == '[' || d.top() == '{')) {
					flag = true;
				}
			}
			else if (s[i] == ']') {
				if (!d.empty() && d.top() == '[') {
					d.pop();
				}
				else if (d.empty() || !d.empty() && (d.top() == '(' || d.top() == '{')) {
					flag = true;
				}
			}
			else if (s[i] == '}') {
				if (!d.empty() && d.top() == '{') {
					d.pop();
				}
				else if (d.empty() || !d.empty() && (d.top() == '[' || d.top() == '(')) {
					flag = true;
				}
			}
			
			if (flag) {
				break;
			}
		}
		
		if (flag) {
			cout << "False" << endl;
		}
		else if (d.empty()) {
			cout << "True" << endl;
		} else {
			cout << "False" << endl;
		}
		
	}
	
	system("pause");
}
