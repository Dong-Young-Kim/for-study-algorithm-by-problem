#include <iostream>
int n;
int cnt = 0;
int board[15];
bool check(int k, int i) {
	for (int j = 0; j < k; j++) 
		if ((i == board[j]) || (k - j == abs(board[j] - i))) 
			return 0;
	return 1;
}
void nq(int k) {
	if (k == n) {
		cnt++;
		return;
	}
	//std::cout << "k = " << k << "      ";
	//for (int i = 0; i < n; i++){
	//	std::cout << board[i] << ' ';
	//}
	//std::cout << '\n';
	for (int i = 0; i < n; i++) { //한 행에 모든 열을 탐색
		if (check(k, i)) {
			board[k] = i;
			nq(k + 1);
		}
	}
}
int main() {
	std::cin >> n;
	nq(0);
	std::cout << cnt << '\n';
}


//index 확인 주의
//k-> 현재 탐색하고 있는 행 번호
//i -> 현재 확인학고 있는 열 번호
//j-> 유망성 판단 과정에서 확인하고 있는 이전 행 번호
//board[j] -> 유망성 판단 과정에서 확인하고 있는 이전 열 번호


//재귀로 하나씩 들어갈 수록 다음 행을 확인하는 절차
//promise 판단은 현재 행에 퀸이 놓인 자리가 기존 퀸과 모순되는지 확인


//아래건 되게 시간이 짧게 걸렸는데 어케 한거지
/*/
#include <iostream>

using namespace std;

int N;
int ans = 0;

int isUsedX[15] = {};
int isUsedLeft[29] = {};
int isUsedRight[29] = {};

void isUsed(int x, int y, bool mode)
{
	isUsedX[x] = mode;
	isUsedLeft[x + y - 1] = mode;
	isUsedRight[y - x + N] = mode;
}

void NQueen(int y)
{
	if (y == N)
	{
		ans++;
	}
	for (int x = 0; x < N; x++)
	{
		if (!(isUsedX[x] || isUsedLeft[x + y - 1] || isUsedRight[y - x + N]))
		{
			isUsed(x, y, true);
			NQueen(y + 1);
			isUsed(x, y, false);
		}
	}
}

int main()
{
	cin >> N;
	NQueen(0);
	cout << ans;
}
//*/