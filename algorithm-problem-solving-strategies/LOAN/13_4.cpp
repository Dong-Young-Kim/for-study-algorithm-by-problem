#include <iostream>
using namespace std;

#define LOAN 250000 // 전세금(N)
#define RATE 5.5 // 연이율(P%)
#define DURA 23 // 기간(M)

double balance(double amount, int duration, double rates, double monthlyPayment)
// 한달에 'monthlyPayment' 만큼 값았을 때 남는 대출 잔금을 반환
// 이 함수의 결과 값이 0이 되는 'monthlyPayment'값을 찾아야
{
    for (int i = 0; i < duration; ++i){
        // amount += amount * rates / 12 / 100;
        amount *= (1 + rates / 12 / 100); // 한 달후에 월 이자(P/12) 만큼 대출금이 불어남
        amount -= monthlyPayment; // 대출금을 월 상환액 만큼 상환함
    }
    return amount;
}

double payment(double amount, int duration, double rates)
{
    double lo = 0;
    double hi = amount * (1 + rates / 12 / 100);

    for (int i = 0; i < 100; ++i)
    {
        double mid = (hi + lo) / 2;
        if (balance(amount, duration, rates, mid) <= 0) hi = mid;
        else lo = mid;
    }
    return (hi + lo) / 2;
}

int main()
{
    int T , dura;
    double loan, rate;
	cin >> T;
	while (T--) {
        cin >> loan >> dura >> rate;
        printf("%f\n", payment(loan, dura, rate));
    }
    return 0;
}