#include<iostream>
using namespace std;

int main()
{
    int H, W, T, X, Y;
    cin >> H >> T;
    W = H;
    while(T--)
    {
        cin >> X >> Y;
        if (X >= H ||  Y >= W) continue;;
        X * W >= Y * H ? H = X : W = Y;
    }
    cout << H * W << endl;
}


