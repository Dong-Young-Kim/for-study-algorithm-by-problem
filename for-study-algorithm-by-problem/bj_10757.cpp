// 큰 수 A + B

// 큰 수 덧셈 연산 구현
// (0 < A,B < 10^10000)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void deleteLeadingZeros(vector<char> &a)
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
vector<char> adder(vector<char> &a, vector<char> &b)
{
    int alen = a.size();
    int blen = b.size();

    vector<char> result;

    char carry = 0;
    for (int i = 0; i < max(alen, blen); ++i)
    {
        char ai = i < alen ? a[i] : 0;
        char bi = i < blen ? b[i] : 0;
        char si = ai + bi + carry;

        result.push_back(si % 10);
        carry = si / 10;
    }
    if (carry)
        result.push_back(carry);
    return result;
}

int main(){

    vector<char> a, b;

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

    vector<char> c = adder(a, b);

    for (int i = c.size() - 1; i >= 0; --i)
        cout << (int)c[i];
    cout << endl;

}


// 숏코딩
// int main()
// {
// 	string a, b, c="";
// 	cin >> a >> b;
// 	int i=a.length();
// 	int j=b.length();
	
// 	int x=0, y=0, z=0;
// 	while(i>0 || j>0){
// 		x=0;
// 		if(i>0) x=a[--i]-'0';
// 		y=0;
// 		if(j>0) y=b[--j]-'0';
// 		c=(char)((x+y+z)%10+'0')+c;
// 		z=(x+y+z)/10;
// 	}
// 	if(z>0)
// 		c=(char)(z+'0')+c;
// 	cout << c;
// 	return 0;
// }
