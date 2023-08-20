#include <iostream>
#include <vector>
using namespace std;

bool checkIn(vector<int>& res, int i) {
	for (int& j : res) {
		if (i == j) return 1;
	}
	return 0;
}

void dfs(vector<int>& res, int m, int n) {
	if (m == 0) {
		for (int &k : res) {
			printf("%d ", k);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		if (checkIn(res, i)) continue;
		
		res.push_back(i);
		dfs(res, m - 1, n);
		res.pop_back();
	}
}

int main() {
	int m, n;
	cin >> n >> m;
	vector<int> res;
	dfs(res, m, n);
}

//nPm을 구하는 문제

//vector 현재까지 출력할 배열에 표시된 수
//dfs에서 int m => 앞으로 더 뽑아야 할 수 

//cout으로 출력하면 시간 초과가 발생할 수 있다.
//printf로 출력하여 시간 초과 문제 해결