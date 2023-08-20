#include <iostream>

using namespace std;

int n, board[100][100];
int cache[100][100]; // 각 위치별로 도착 가능한지 여부를 저장하는 캐시

bool jump(int x, int y)
{
    // 1. 기저 사례 처리
    if (x == n-1 && y == n-1) return true;
    if (x >= n || y >= n) return false;

    // 2. 캐시 확인
    int & ret = cache[x][y];
    if (ret != -1) return ret;

    // 3. 계산
    bool right = jump(x, y + board[x][y]);
    bool down = jump(x + board[x][y], y);
    ret = right || down;

    return ret;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(cache, -1, sizeof(cache));
        cin >> n;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> board[i][j];
        
        cout << (jump(0,0) ? "YES" : "NO") << endl;
    }
}