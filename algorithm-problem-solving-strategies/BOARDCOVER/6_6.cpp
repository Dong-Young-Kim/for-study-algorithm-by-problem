#include <iostream>
#include <vector>

using namespace std;

const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}}, // ㄱ 의 좌우반전 형태
    {{0, 0}, {0, 1}, {1, 1}}, // ㄱ 형태
    {{0, 0}, {1, 0}, {1, 1}}, // ㄴ 형태
    {{0, 0}, {0, 1}, {1, -1}} // ㄴ 의 좌우반전 형태
};
// 4 : 4가지 type의 블럭을 놓는 경우의 수
// 3 : 블럭이 차지하는 칸 수
// 2 : 각각 x, y
// ex) 아래 칸 -> x : +1, y : +-0

bool set(vector< vector<int> > & board, int x, int y, int type, int coverFlag) 
{
    bool canCover = 1;
    int blockX, blockY;
    for (int i = 0; i < 3; ++i)
    {
        // 한 블럭이 놓여져야할 칸의 위치를 구한다.
        blockX = x + coverType[type][i][0];
        blockY = y + coverType[type][i][1];

        // board를 벗어나는지를 확인한다.
        if (blockX < 0 || blockY < 0 || blockX >= board.size() || blockY >= board[0].size()) 
        {
            canCover = 0;
        } 
        // board 내부로 판단됨. 블럭을 놓고(제거하고) 블럭이 놓여 있었는지 확인한다.
        else
        {
            if(board[blockX][blockY] > 0) canCover = 0; // 먼저 놓여있는 블럭이 있는지 확인
            board[blockX][blockY] += coverFlag; // 블럭을 놓거나 제거
        }
    }
    return coverFlag;
}

int cover(vector< vector<int> > & board)
{
    // 1. board에서 채워지지 않은 칸 찾기
    bool isFilled = 1;
    int x, y;
    for (x = 0; x < board.size(); ++x) {
        for (y = 0; y < board[0].size(); ++y) {
            if (board[x][y] == 0) // 빈칸 발견
            {
                isFilled = 0;
                break;
            }
        }
        if (isFilled == 0) break;
    }

    // 모든 칸이 채워졌다면 1을 반환하고 종료
    // 하나의 경우가 완성됨 (기저사례)
    if(isFilled == 1) return 1; 

    // 2. 시도할 수 있는 각각의 case를 시도하고 가능한 경우 재귀 호출
    int ret = 0;
    for (int type = 0; type < 4; ++type)
    {
        // 블럭을 덮을 수 있는 경우 
        if (set(board, x, y, type, 1)) ret += cover(board);
        set(board, x, y, type, -1);
    }
    return ret;
}

int main()
{
    int T, H, W;

    cin >> T;

    while(T--){

        cin >> H >> W;
        vector< vector<int> > board(H, vector<int>(W)); //격자는 2차원 vector 에 저장

        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                char temp;
                cin >> temp;
                board[x][y] = (temp == '#' ? 1 : 0);
            }
        }
                
        cover(board);
    }
}