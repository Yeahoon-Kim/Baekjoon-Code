#include <iostream>
#include <stack>

#pragma warning(disable:4996)

using namespace std;

int main(void) {
	int instructorNum, inputNum;
	string instructor;
	stack<int> S;

	cin >> instructorNum;

	while (instructorNum) {
		cin >> instructor;

		if (instructor == "push") {
			cin >> inputNum;
			S.push(inputNum);
		}
		else if (instructor == "pop") {
			if (S.size()) {
				cout << S.top() << endl;
				S.pop();
			}
			else {
				cout << "-1" << endl;
			}
			
		}
		else if (instructor == "top") {
			if (S.size()) {
				cout << S.top() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (instructor == "size") {
			cout << S.size() << endl;
		}
		else if (instructor == "empty") {
			cout << (S.empty() ? "1" : "0") << endl;
		}

		instructorNum--;
	}

	return 0;
}