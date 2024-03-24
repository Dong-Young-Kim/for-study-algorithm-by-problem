// boj_18870 : 좌표 압축

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> sorted_v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        sorted_v[i] = v[i];
    }

    // 1. sort
    sort(sorted_v.begin(), sorted_v.end());

    // 2. unique
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());
    
    // 3. map
    // map<int, int> m;
    // for (int i = 0; i < sorted_v.size(); i++)
    // {
    //     m[sorted_v[i]] = i;
    // }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << m[v[i]] << ' ';
    // }

    // 3. binary search
    for (int i = 0; i < N; i++)
    {
        cout << lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin() << ' ';
    }

    return 0;
}
// */
//