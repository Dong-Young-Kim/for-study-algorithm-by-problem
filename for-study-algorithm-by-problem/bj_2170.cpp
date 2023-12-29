// 선 긋기

#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int l;
    cin >> l;
    vector<pair<int, int> > v;
    while(l--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());

    int length = 0;
    int start = v[0].first, end = v[0].second;

    for(pair<int, int> p : v)
    {
        // 기존 선분에 포함되는 경우
        if(p.first <= end)
        {
            end = max(end, p.second);
        }
        else
        {
            length += end - start;
            start = p.first;
            end = p.second;
        }
    }
    length += end - start; // 마지막 구간 반영
    cout << length << "\n";    
}

/*

스위핑 기법을 사용하여 문제를 해결한다

1. pair 형태로 모든 선분을 저장한다. (first: 시작점, second: 끝점)
2. pair를 first를 기준으로 오름차순 정렬한다.

3. 모든 선분을 순회하며 아래 과정을 반복한다.
    3-1. 기존 선분에 포함되는 경우
        3-1-1. end를 max(end, p.second)로 갱신하여 하나의 선분으로 합친다.
    3-2. 기존 선분에 포함되지 않는 경우
        3-2-1. length에 end - start를 더한다. 
            (이전까지 구한 선분이 완성되었으므로 length에 더한다)
        3-2-2. 새로운 선분으로 start와 end를 갱신한다.
            (새로운 선분을 구하기 위해 start와 end를 갱신한다)

4. length에 end - start를 더한다. (마지막 선분의 길이를 더한다)

*/

/*
sort 함수는 algorithm 헤더에 정의되어 있다.
*/