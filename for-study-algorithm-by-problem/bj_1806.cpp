# include <iostream>

using namespace std;

const int MAXSIZE = 1000001;
int N, S, A[MAXSIZE];

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> A[i];

    int sum = 0, s = 0, e = 0, minLength = MAXSIZE;

    while(e <= N)
    {
        if (sum >= S) 
        {
            minLength = min(minLength, (e - s));
            sum -= A[s++];
        }
        else sum += A[e++];
    }
    printf("%d\n", minLength == MAXSIZE ? 0 : minLength);
}