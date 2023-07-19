#include <iostream>
using namespace std;

int dp[1001];
int arr[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dp[i];
	}
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[i] > dp[j]) {
				arr[i] = max(arr[j] + 1, arr[i]);
			}
		}
		sum = max(sum, arr[i]);
	}

	cout << ++sum;
	return 0;
}