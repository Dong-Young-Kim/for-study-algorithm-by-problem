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

// two positive integers
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

    vector<int> c = adder(a, b);

    cout << "result = ";
    for (int i = c.size() - 1; i >= 0; --i)
        cout << c[i];
    cout << endl;
}
