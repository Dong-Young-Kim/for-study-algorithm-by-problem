#include <iostream>
#include <vector>
#include <string>

using namespace std;

void deleteLeadingZeros(vector<int> &a)
{
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

    vector<int> result;

    int carry = 0;
    for (int i = 0; i < max(alen, blen); ++i)
    {
        int ai = i < alen ? a[i] : 0;
        int bi = i < blen ? b[i] : 0;
        int si = ai + bi + carry;

        result.push_back(si % 10);
        carry = si / 10;
    }
    if (carry)
        result.push_back(carry);
    return result;
}

vector<int> tensComplement(vector<int> &a)
{
    int alen = a.size();
    vector<int> result;

    // 9's complement
    for (int i = 0; i < alen; i++) a[i] = 9 - a[i];

    // add 1 (10's complement)
    int carry = 1;
    for (int i = 0; i < alen; ++i)
    {
        int si = a[i] + carry;
        result.push_back(si % 10);
        carry = si / 10;
    }

    return result;
}

// two positive integers subtractor (a - b)
vector<int> subtractor(vector<int> &a, vector<int> &b)
{
    // make b's length same as a's
    for (int i = b.size(); i < a.size(); ++i)
    {
        b.push_back(0);
    }

    // b, 10's complement
    b = tensComplement(b);

    vector<int> result;
    // add
    result = adder(a, b);

    if(result.size() > max(a.size(), b.size()))
    {
        // result positive
        result.pop_back();
    }
    else
    {
        // result negative
        result = tensComplement(result);
        // result.end()[-1] = -result.end()[-1];
        result.back() = -result.back();
    }

    return result;
}

int main()
{

    vector<int> a, b;

    cout << "input two positive integers" << endl;

    // raw data input
    string sa, sb;
    cin >> sa >> sb;

    // convert string to vector<int>
    for (int i = sa.length() - 1; i >= 0; --i)
    {
        a.push_back(sa[i] - '0');
    }

    for (int i = sb.length() - 1; i >= 0; --i)
    {
        b.push_back(sb[i] - '0');
    }

    // delete leading zeros
    deleteLeadingZeros(a);
    deleteLeadingZeros(b);


    // cout << "input A = ";
    // for (int i = a.size() - 1; i >= 0; --i)
    //   cout << a[i];
    // cout << endl;

    // cout << "input B = ";
    // for (int i = b.size() - 1; i >= 0; --i)
    //   cout << b[i];
    // cout << endl;

    // vector<int> c = adder(a, b);
    vector<int> c = subtractor(a, b);

    cout << "result = ";
    for (int i = c.size() - 1; i >= 0; --i)
        cout << c[i];
    cout << endl;
}
