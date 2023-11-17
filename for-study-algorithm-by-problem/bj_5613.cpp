// 계산기 프로그램

// 괄호와 연산자 순서에 상관 없이 쌀집 계산기 처럼 구현함
// / 연산은 소수점을 사용하지 않고 버림 연산 함

#include <iostream>
using namespace std;
int main()
{
    int result;
    cin >> result;

    while (true)
    {
        char optr;
        int opnd;

        cin >> optr;
        if (optr == '=') break;

        cin >> opnd;
        switch (optr)
        {
        case '+':
            result += opnd;
            break;
        case '-':
            result -= opnd;
            break;
        case '*':
            result *= opnd;
            break;
        case '/':
            result /= opnd;
            break;
        }
    }
    cout << result;
}
