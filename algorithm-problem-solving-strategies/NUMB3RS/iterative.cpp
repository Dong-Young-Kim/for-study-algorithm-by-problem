#include <iostream>

using namespace std;

int N, D, P; // N; 마을 수, D : 자난 날, P: 교도소위치
bool route[50][50]; // 마을 간 연결 정보
int deg[50]; // 다른 마을로 연결되어 있는 길의 수

double cache[101][50]; // [지난 날][마을] 에의 존재 확률

void precalc()
// deg(마을 연결 정보) 사전 계산, 0일차 계산
{
    for (int village = 0; village < N * N; village++)
    {
        if(route[village / N][village % N]) ++deg[village / N];
    }

    cache[0][P] = 1; // 첫날 위치 표시
}

double calcNode(const int &day, const int &loc)
// cache[day][loc]의 값을 계산한다 O(N)
{
    double sum = 0;
    for (int k = 0; k < N; ++k)
    {
        if (route[loc][k]) // 현재 마을로 오는 길이 있다면
        {
            sum += cache[day-1][k] / (double)deg[k];
        }
    }

    return sum;
}

void search()
// cache를 전부 순회하면서 값을 채운다 O(ND)
{
    for (int day = 1; day <= D; ++day)
    {
        for (int loc = 0; loc < N; ++loc)
        {
            cache[day][loc] = calcNode(day, loc);
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(cache, 0, sizeof(cache));
        memset(deg, 0, sizeof(deg));
        cin >> N >> D >> P;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> route[i][j];
        
        precalc();
        search();

        int print_num;
        cin >> print_num;
        while (print_num--)
        {
            int index;
            cin >> index;
            printf("%f ", cache[D][index]);
        }
        printf("\n");
    }
}