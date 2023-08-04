#include <iostream>
using namespace std;

#define ON 1
#define OFF 0

int N;
bool board[18][18];

void toggleLamp(int i, int j)
{
    bool& lamp = board[i][j];
    if(lamp == ON) lamp = OFF;
    else lamp = ON; 
}

void pressLamp(int i, int j)
{
    toggleLamp(i, j);
    if (i-1 > 0) toggleLamp(i-1, j);
    if (i+1 < N) toggleLamp(i+1, j);
    if (j-1 > 0) toggleLamp(i, j-1);
    if (j+1 < N) toggleLamp(i, j+1);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int num_method = 0;

    // for 문 순서 잘못됨
    // for (int row = 0; row < N; ++row)
    // {   
    //     // 한 행에서 모든 전구를 누를 수 있는 조합을 생성한다.
    //     for (int subset = (1 << N) - 1; subset > 0; --subset)
    //     {
    //         // 만들어진 조합에 따라서 전구를 누른다.
    //         for (int col = 0; col < N; ++col)
    //             if(subset & (1 << col)) pressLamp(row, col);

    //         if (row != 0){
    //             // 윗줄에 모든 전구가 꺼졌는지 확인
    //         }
    //         if (row == N)
    //         {
    //             // 마지막 줄에 전구가 모두 꺼졌는지 확인
    //             // 모든 전구가 꺼졌으면 method += 1
    //         }
    //         //...
    //     }
    // }


}

/*
기본적으로 완전 탐색 원리에 따라서 모든 경우의 수를 탐색한다.

n*n의 모든 전구를 눌러보는 조합을 모두 생성하여 문제를 해결할 수도 있으나 
2^(n*n)의 경우의 수가 필요하여 매우 비효율적이다



각 줄 별로 조합을 따져보는 방법을 이용한다.

윗줄부터 아랫줄로 전구를 누르도록 가정하자

이떄 윗 줄의 전구가 남았을 떄, 윗줄에서 켜진 전구를 끄고 다음줄로 넘어가야 모든 전구를 끌 수 있다.
윗줄의 전구를 끄려면 윗 줄에서 켜진 바로 아래 전구를 '무조건' 눌러야 한다.
이 원리를 이용하면 다음 줄에 눌러야 할 전구의 경우의 수가 한가지로 고정되어
총 경우의 수가 대폭 감소한다.
(첫 줄을 완전 탐색을 통해 경우의 수를 생성하면 다음 줄부터는 누르는 방법이 한 가지로 정해지는 셈)

*/