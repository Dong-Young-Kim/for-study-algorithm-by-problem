// 정육면체 전개도

/*
아이디어
1. 정육면체의 전개도는 11가지 이 경우를 모두 구현하고, 이동&반전시켜가며 동일한지 찾기
2. 가상의 주사위를 구현하고 이를 굴려본다
    1) 주사위를 모든 면에 굴리고, 주사위가 중복 없이 모두 채워졌는지 확인한다. -> 불가능
    2) 백트래킹을 사옹하여 d=6까지만 주사위를 굴려본다. -> 뎁스를 제한하면 불가능
    3) 주사위를 굴리고, 이동시키는 함수를 구현한다. 
3. 마주보는 두 면이 세 쌍인지 확인한다.
*/

// dfs 를 통한 구현
// boj_2642를 먼저 구현한 후 구현하였다. 전개도가 1로 표시된 것에만 차이가 존재한다. 

#include <stdio.h>

// 0: top, 1: bottom, 2: front, 3: back, 4: left, 5: right
char cube[6];
char board[6][6];

int delta_pos[4][2] = {
    {-1, 0},    // N
    {1, 0},     // S
    {0, -1},    // W
    {0, 1}      // E
};

int opposite_dir[4] = {1, 0, 3, 2};

inline bool checkCube()
{
    for (int i = 0; i < 6; i++) if(cube[i] != 1) return false;
    return true;
}

inline bool outOfRange(int x, int y)
{
    return x < 0 || x >= 6 || y < 0 || y >= 6;
}

void moveCube(char cube[], int direction)
{
    int tmp;
    switch(direction)
    {
    case 0: // N
        tmp = cube[0];
        cube[0] = cube[2];
        cube[2] = cube[1];
        cube[1] = cube[3];
        cube[3] = tmp;
        break;
    case 1: // S
        tmp = cube[0];
        cube[0] = cube[3];
        cube[3] = cube[1];
        cube[1] = cube[2];
        cube[2] = tmp;
        break;
    case 2: // W
        tmp = cube[0];
        cube[0] = cube[5];
        cube[5] = cube[1];
        cube[1] = cube[4];
        cube[4] = tmp;
        break;
    case 3: // E
        tmp = cube[0];
        cube[0] = cube[4];
        cube[4] = cube[1];
        cube[1] = cube[5];
        cube[5] = tmp;
        break;
    }
}

void dfs(int x, int y)
{
    for (int dir = 0; dir < 4; ++dir) // N, S, W, E
    {
        int nx =  x + delta_pos[dir][0];
        int ny =  y + delta_pos[dir][1];

        if(outOfRange(nx, ny) || board[nx][ny] == 0) // or 조건으로 범위 초과시 뒷부분 실행 안하도록
            continue;

        moveCube(cube, dir);

        if(cube[1] == 0) // bottom face first visit
        {
            cube[1] = board[nx][ny];
            dfs(nx, ny);
        }

        moveCube(cube, opposite_dir[dir]);
    }
}

int main()
{
    int T = 3;
    while(T--)
    {
        for(int i = 0; i < 6; i++) cube[i] = 0; 
        int x = 0, y = 0;
        for(int i = 0; i < 36; i++) scanf("%hhd", &board[i / 6][i % 6]);
        for(int i = 0; i < 36; i++)
        {
            if(board[i / 6][i % 6] == 1)
            {
                x = i / 6;
                y = i % 6;
                break;
            }
        }
        cube[1] = board[x][y];
        dfs(x, y);
        checkCube() ? printf("yes\n") : printf("no\n");
    }
}
