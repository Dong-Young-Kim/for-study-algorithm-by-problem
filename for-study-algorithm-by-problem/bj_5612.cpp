// 터널의 입구와 출구

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int cars = m, maxCars = m;

    for (int i = 0; i < n; ++i)
    {
        int in, out;
        cin >> in >> out;
        cars += (in - out);
        if (cars < 0)
        {
            maxCars = 0;
            break;
        }
        maxCars = max(maxCars, cars);
    }
    cout << maxCars;
}