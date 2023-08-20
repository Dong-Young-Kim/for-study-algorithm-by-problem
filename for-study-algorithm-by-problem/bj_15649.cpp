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

//nPm�� ���ϴ� ����

//vector ������� ����� �迭�� ǥ�õ� ��
//dfs���� int m => ������ �� �̾ƾ� �� �� 

//cout���� ����ϸ� �ð� �ʰ��� �߻��� �� �ִ�.
//printf�� ����Ͽ� �ð� �ʰ� ���� �ذ�