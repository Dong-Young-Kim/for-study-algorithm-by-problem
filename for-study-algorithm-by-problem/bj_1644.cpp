// 소수의 연속합
#include <iostream>
#include <memory.h>
#include <math.h>
#include <vector>
using namespace std;

const int MAX_N = 4000001;

unsigned char sieve[(MAX_N + 7) / 8];
vector<int> primes;

inline bool isPrime(int k)
{
    return sieve[k >> 3] & (1 << (k & 7)); // bitmask
}

inline void setComposite(int k)
{
    sieve[k >> 3] &= ~(1 << (k & 7)); // bitmask
}

void eratosthenes()
{
    memset(sieve, 255, sizeof(sieve));
    setComposite(0);
    setComposite(1);

    int sqrtn = int(sqrt(MAX_N));

    for (int i = 2; i <= sqrtn; ++i)
    {
        if(isPrime(i))
        {
            for(int j = i * i; j <= MAX_N; j += i)
            {
                setComposite(j);
            }
        }
    }
}

int main()
{
    eratosthenes();
    for (int i = 0; i < MAX_N; ++i)
    {
        if(isPrime(i)) primes.push_back(i);
    }

    int N, num = 0, sum = 0;
    cin >> N; 

    vector<int>::iterator s = primes.begin();
    vector<int>::iterator e = primes.begin();
    while(*s <= N && e <= primes.end())
    {
        if (sum == N) ++num;
        if (sum >= N) sum -= *(s++);
        else sum += *(e++);
    }

    printf("%d", num);
}

// 에라토스테네스의 체를 통해서 범위 내 모든 소수를 구한다
// 소수의 배열인 primes를 생성한다.

// 투 포인터 알고리즘을 이용해 
// 모든 소수 조합으로 생성할 수 있는 조합의 수를 구한다.

