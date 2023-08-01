#include <iostream>
#include <string>

using namespace std;

template<typename DTYPE>
string convertBinary(DTYPE num, int digit)
{
    string res;
    while (--digit >= 0)
    {
        res += to_string((num >> digit) & 1);
        if (digit % 4 == 0) res += ' ';
    }
    return res;
}

int main()
{
    int a = 754;
    int b = 470;
    int c;

    // // XOR
    // c = a ^ b; // XOR 연산 값을 C에 저장

    // cout << "      "<< convertBinary(a, 12) << " = " << a << '\n';
    // cout << "XOR   "<< convertBinary(b, 12) << " = " << b << '\n';
    // cout << "─────────────────────────────\n";
    // cout << "      "<< convertBinary(c, 12) << " = " << c << '\n';

    // // NOT
    // c = ~a; // NOT 연산 값을 C에 저장

    // cout << "NOT   "<< convertBinary(a, 32) << " = " << a << '\n';
    // cout << "─────────────────────────────\n";
    // cout << "      "<< convertBinary(c, 32) << " = " << c << '\n';

    
    // bit shift
    c = a << 2;
    cout << "<< 2  "<< convertBinary(a, 12) << " = " << a << '\n';
    cout << "─────────────────────────────\n";
    cout << "      "<< convertBinary(c, 12) << " = " << c << '\n';

    c = a >> 2;
    cout << ">> 2  "<< convertBinary(a, 12) << " = " << a << '\n';
    cout << "─────────────────────────────\n";
    cout << "      "<< convertBinary(c, 12) << " = " << c << '\n';

    cout << endl;

    return 0;
}