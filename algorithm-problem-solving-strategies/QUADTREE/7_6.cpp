// 압축 미해제 상하반전 알고리즘

#include<iostream>
#include<string>

using namespace std;

string reverse(string::iterator & it)
{
    char cur_str = *it;
    it++;

    if(cur_str == 'b' || cur_str == 'w')
    {
        return string(1,cur_str);
    }
    else{
        string topLeft  = reverse(it);
        string topRight = reverse(it);
        string botLeft  = reverse(it);
        string botRight = reverse(it);

        return "x" + botLeft + botRight + topLeft + topRight;
    }
}

int main()
{
    int T;
    cin >> T;
    string compressedOriginal;
    while(T--)
    {
        cin >> compressedOriginal;
        string::iterator it = compressedOriginal.begin();
        cout << reverse(it) << endl;
    }
}