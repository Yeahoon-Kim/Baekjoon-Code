#include <iostream>

using namespace std;

bool groupWordChecker(string&);

int main(void) {
	int number, count = 0;
	string inputString;
	

	cin >> number;

	for (; number; number--) {
		cin >> inputString;

		if (groupWordChecker(inputString)) count++;
	}

	cout << count;
}

bool groupWordChecker(string& inputString) {
	bool alphabet[26] = {false};
	char beforeChar = -1;
	int i;

	for (i = 0; i < inputString.length(); i++) {
		if (inputString[i] == beforeChar) continue;
		else 
		{
			if (alphabet[inputString[i] - 'a']) {
				return false;
			}

			alphabet[inputString[i] - 'a'] = true;
			beforeChar = inputString[i];
		}
	}

	return true;
}