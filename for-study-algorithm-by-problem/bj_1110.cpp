#include<iostream>
using namespace std;
int main() {
	int count = 0, input, init;
	cin >> init;
	input = init;
	while (1) {
		if (input < 10) {
			input = 10 * input + input;
		}
		else {
			int a = (input / 10) % 10;
			int b = input % 10;
			input = 10 * b + (a + b) % 10;
		}
		++count;
		if (input == init) break;
	}
	cout << count;
	return 0;
}