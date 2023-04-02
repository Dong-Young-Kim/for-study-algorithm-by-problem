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
	for (int i = 0; i < n; i++) { //�� �࿡ ��� ���� Ž��
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


//index Ȯ�� ����
//k-> ���� Ž���ϰ� �ִ� �� ��ȣ
//i -> ���� Ȯ���а� �ִ� �� ��ȣ
//j-> ������ �Ǵ� �������� Ȯ���ϰ� �ִ� ���� �� ��ȣ
//board[j] -> ������ �Ǵ� �������� Ȯ���ϰ� �ִ� ���� �� ��ȣ


//��ͷ� �ϳ��� �� ���� ���� ���� Ȯ���ϴ� ����
//promise �Ǵ��� ���� �࿡ ���� ���� �ڸ��� ���� ���� ����Ǵ��� Ȯ��


//�Ʒ��� �ǰ� �ð��� ª�� �ɷȴµ� ���� �Ѱ���
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