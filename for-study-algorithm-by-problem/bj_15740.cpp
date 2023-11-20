// A + B
// 문제
// 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 A와 B (-1010000 ≤ A, B ≤ 1010000)가 주어진다.

// 출력
// 첫째 줄에 A+B를 출력한다.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void deleteLeadingZeros(vector<int> &a)
{
    if (a.size() == 1) return;
    for (int i = a.size() - 1; i >= 1; --i)
    {
        if (a[i] != 0)
            break;
        a.pop_back();
    }
}

// two positive integers adder
vector<int> adder(vector<int> &a, vector<int> &b)
{
    int alen = a.size();
    int blen = b.size();

    vector<int> res;

    int carry = 0;
    for (int i = 0; i < max(alen, blen); ++i)
    {
        int ai = i < alen ? a[i] : 0;
        int bi = i < blen ? b[i] : 0;
        int si = ai + bi + carry;

        res.push_back(si % 10);
        carry = si / 10;
    }
    if (carry)
        res.push_back(carry);
    return res;
}

vector<int> tensComplement(vector<int> &a)
{
    int alen = a.size();
    vector<int> res;

    // 9's complement
    for (int i = 0; i < alen; i++) a[i] = 9 - a[i];

    // add 1 (10's complement)
    int carry = 1;
    for (int i = 0; i < alen; ++i)
    {
        int si = a[i] + carry;
        res.push_back(si % 10);
        carry = si / 10;
    }

    return res;
}

// two positive integers subtractor (a - b)
vector<int> subtractor(vector<int> &a, vector<int> &b)
{
    // exception b == 0
    if (b.size() == 1 && b[0] == 0) return a;

    // make b's length same as a's
    for (int i = b.size(); i < a.size(); ++i)
    {
        b.push_back(0);
    }

    // b, 10's complement
    b = tensComplement(b);

    vector<int> res;
    // add
    res = adder(a, b);

    if(res.size() > max(a.size(), b.size()))
    {
        // result positive
        res.pop_back();
        deleteLeadingZeros(res);
    }
    else
    {
        // result negative
        res = tensComplement(res);
        deleteLeadingZeros(res); // delete leading zero before add '-'
        res.back() = -res.back();
    }

    return res;
}

int main()
{
    vector<int> a, b;
    string sa, sb;
    cin >> sa >> sb;

    int c = 0;
    if (sa.front() == '-')
    {
        sa.erase(sa.begin());
        c += 2;
    }
    if (sb.front() == '-')
    {
        sb.erase(sb.begin());
        c += 1;
    }

    for (int i = sa.length() - 1; i >= 0; --i) a.push_back(sa[i] - '0');
    for (int i = sb.length() - 1; i >= 0; --i) b.push_back(sb[i] - '0');


    // delete leading zeros
    deleteLeadingZeros(a);
    deleteLeadingZeros(b);

    vector<int> res;
    switch(c)
    {
    case(0):
        res = adder(a, b); 
        break;
    case(1):
        res = subtractor(a, b); 
        break;
    case(2):
        res = subtractor(b, a); 
        break;
    case(3):
        res = adder(a, b);
        res.back() = -res.back();
        break;
    }

    for (int i = res.size() - 1; i >= 0; --i)
        cout << res[i];
    cout << endl;
}

// A + B
// 0. 둘다 양수 adder(a,b)
// 1. 양수 음수 subtractor(양수, -음수)
// 2. 음수 양수 
// 3. 둘다 음수 -adder(-a,-b)

// a가 음수이면 case += 2
// b가 음수이면 case += 1

// 뺼셈 연산 개념이 들어가므로 뺄셈을 구현하고, 케이스를 나눠 해결
// 부호가 동일한 경우는 덧셈으로, 부호가 다른 경우는 뺼셈으로 처리
// 뺼셈 연산은 뺴는 숫자를 10의 보수를 취한 후 두 수를 더하는 방식으로 구현함
