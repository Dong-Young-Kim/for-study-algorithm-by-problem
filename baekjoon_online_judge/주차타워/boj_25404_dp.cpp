// convert cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int INF = std::numeric_limits<int>::max();
int N;
map<pair<int,int>, int> cache_m;

vector<vector<int>> cidx;

int circleDist(int a, int b) {
    return min(abs(a - b), N - abs(a - b));
}

int dp(int c, int e) {
    auto cache_res = cache_m.find(make_pair(c, e));
    if(cache_res != cache_m.end()) return cache_res->second;
    
    int min_val = INF;
    for (int i = 0; i < cidx[c].size(); i++) {
        int c1 = cidx[c][i];
        int c2 = cidx[c][(i - 1 + cidx[c].size()) % cidx[c].size()]; // cidx[c][i-1]
        int path = c1 <= c2 ? c2 - c1 : N - (c1 - c2);
        if (c == 0) {
            min_val = min(min_val, circleDist(0, c1) + path + circleDist(c2, e));
            min_val = min(min_val, circleDist(0, c2) + path + circleDist(c1, e));
        }
        else {
            min_val = min(min_val, dp(c - 1, c1) + path + circleDist(c2, e));
            min_val = min(min_val, dp(c - 1, c2) + path + circleDist(c1, e));
        }
    }
    return cache_m[make_pair(c, e)] = min_val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    cidx.resize(sorted_arr.size());
    for(int i = 0; i < N; i++)
    {
        int a = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin();
        cidx[a].push_back(i);
    } 
    int min_val = INF;
    for (int i = 0; i < cidx.back().size(); i++) {
        min_val = min(min_val, dp(cidx.size() - 1, cidx.back()[i]));
    }
    cout << min_val << endl;

    return 0;
}
