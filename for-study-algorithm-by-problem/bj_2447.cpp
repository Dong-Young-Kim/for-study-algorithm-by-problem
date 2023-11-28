#include<iostream>
#include<cmath>
using namespace std;
int inputN;
string draw(int N)
{
    if(N == 0)
    {
        return "*";
    }
    else
    {
        string result = "";
        for(int i = 0; i < 3; ++i) result += draw(N - 1);
        // if(inputN == N) result += "\n";

        result += draw(N - 1);
        result += " ";
        result += draw(N - 1);
        // if(inputN == N) result += "\n";
        

        for(int i = 0; i < 3; ++i) result += draw(N - 1);
        // if(inputN == N) result += "\n";
      
        return result;
    }
}
int main()
{
    cin >> inputN;

    string s =  draw(inputN);
    for(int i = 0; i < s.length(); ++i)
    {

        cout << s[i];
        if ((i+1) % (int)(pow(3,inputN)) == 0) cout << endl;
    }

}

// 출력 형식을 한번에 만드려고 하면 문제를 풀 수 업을 것
// 배열에 출력 내용을 저장해 한 번에 출력하는 방식으로 구현해보자

