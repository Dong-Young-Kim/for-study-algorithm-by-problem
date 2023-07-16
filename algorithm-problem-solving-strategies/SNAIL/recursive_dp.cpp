#include <iostream>

using namespace std;

int M, N;
double cache[1001][2001];

double climb(int remainDays, int toClimb)
{
    if (toClimb <= 0) return 1.;
    if (remainDays == 0) return 0.; //다 오르지 못했는데 남을 일수가 0

    double & ret = cache[remainDays][toClimb];
    if (ret != -1.) return ret;

    return ret = 
          0.75 * (climb(remainDays - 1, toClimb - 2)) 
        + 0.25 * (climb(remainDays - 1, toClimb - 1));
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        
        fill_n(&cache[0][0], 1000 * 2001, -1.);

        cin >> N >> M;
        
        printf("%.10f\n",climb(M,N));
    }
}