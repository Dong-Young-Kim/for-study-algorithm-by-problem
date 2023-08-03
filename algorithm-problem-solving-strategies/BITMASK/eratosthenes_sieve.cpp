// 비트 마스크를 이용한 에라토스테네스의 체
#include <stdio.h>
#include <memory.h>
#include <math.h>

const int MAX_N = 100000;


int n = 100000;

// MAX_N개의 소수를 판별할 수 있는 배열을 정의한다.
unsigned char sieve[(MAX_N + 7) / 8];

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

    int sqrtn = int(sqrt(n));

    for (int i = 2; i <= sqrtn; i++)
    {
        if(isPrime(i))
        {
            // i의 배수를 소수가 아니라고 표시
            for(int j = i * i; j <= n; j += i)
            {
                setComposite(j);
            }
        }
    }
}

int main()
{
    eratosthenes();

    for (int i = 0; i < n; i++)
    {
        if(isPrime(i)) printf("%d ", i);
        if(i % 100 == 0) printf("\n");
    }
    printf("\n");
}