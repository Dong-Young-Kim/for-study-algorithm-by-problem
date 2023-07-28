#include <iostream>

using namespace std;

int N, D, P;
bool route[50][50];
int deg[50];

double cache[101][50]; // [지난 날][마을] 에의 존재 확률

double calcNode(const int &i, const int &j)
// cache[i][j]의 값을 계산한다
{
    double sum = 0;
    for (int k = 0; k < N; ++k)
    {
        if (route[j][k] == 1)
        {
            sum += cache[i-1][k] / (double)deg[k];
        }
    }
    return sum;
}

int search()
// cache를 전부 순회하면서 값을 채운다
{
    cache[P][0] = 1; // day = 0일때 박사의 위치

    for (int i = 0; i < D; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            calcNode(i, j);
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
        cin >> N >> D >> P;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> route[i][j];
        
        int search();
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