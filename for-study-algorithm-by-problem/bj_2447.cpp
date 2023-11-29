#include<iostream>
#include<vector>
using namespace std;
void draw(vector<vector<string> >& b, int N, int r, int c)
{
    if(N == 1)
    {
        b[r][c] = "*";
    }
    else
    {
        int nextN = N / 3;
        draw(b, nextN, r, c);
        draw(b, nextN, r, c + nextN);
        draw(b, nextN, r, c + nextN * 2);

        draw(b, nextN, r + nextN, c);
        // blank
        draw(b, nextN, r + nextN, c + nextN * 2);
        
        draw(b, nextN, r + nextN * 2, c);
        draw(b, nextN, r + nextN * 2, c + nextN);
        draw(b, nextN, r + nextN * 2, c + nextN * 2);
    }
}
int main()
{
    int N;
    cin >> N;

    vector<vector<string> > board(N, vector<string>(N, " "));

    draw(board, N, 0, 0);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}

// 단순히 string 자료형을 전달하는 식으로는 해결이 불가능
// 문제의 원인은 공백,
// 공백 때문에 출력 순서가 바뀌어야 한다.
// 출력 형식을 한번에 만드려고 하면 문제를 풀 수 업을 것
// 배열에 출력 내용을 저장해 한 번에 출력하는 방식으로 구현해보자

// 1차원의 string 에 \n까지 포함하여 한번에 저장하여
// 재귀를 통해 return 받는다면 해결이 불가능 할 것

// 2차원의 배열을 만들고 한번에 출력한다는 생각을 할 수 있다면 바로 해결할 수 있다.
