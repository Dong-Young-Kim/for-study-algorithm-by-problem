// 감정이입

#include<iostream>
using namespace std;
int binaryToDecimal(string B)
{
    int result = 0;
    for(int i = 0; i < B.length(); i++)
    {
        result = result * 2 + (B[i] - '0');
    }
    return result;
}
string decimalToBinary(long long D)
{
    string result = "";
    while(D > 0)
    {
        result = (char)(D % 2 + '0') + result;
        D /= 2;
    }
    return result;
}
int main()
{
    string B1, B2;
    cin >> B1 >> B2;

    int D1 = binaryToDecimal(B1);
    int D2 = binaryToDecimal(B2);

    long long result = (long long)D1 * (long long)D2;

    cout << decimalToBinary(result) << endl;
}
