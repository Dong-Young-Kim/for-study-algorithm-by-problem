#include <iostream>
using namespace std;

int A[1000], C[1000];

int main() {
	int n;
	cin >> n;
	fill_n(C, 1000, 1); // 어떤 원소를 최소로 갖는 최소 LIS 길이는 1
	for (int i = 0; i < n; i++) cin >> A[i];
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) { // 지금까지 만든 LIS 뒤에 A[i]를 붙일 수 있다면
				C[i] = max(C[j] + 1, C[i]);
			}
		}
		sum = max(sum, C[i]);
	}

	cout << sum << "\n";
	return 0;
}
