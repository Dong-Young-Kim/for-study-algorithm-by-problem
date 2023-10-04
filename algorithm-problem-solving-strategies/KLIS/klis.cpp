#include <iostream>
#include <vector>

using namespace std;

#define MAX 2000000001

int N;
int A[501], cacheLIS[501], cacheCnt[501];

int lis(int crnt)
{
    // 1. 기저사례
    // if (crnt == N) return 0; (없어도 된다)

    // 2. 캐시확인
    int & ret = cacheLIS[crnt + 1]; // -1 index로 인해서 한 칸씩 밀어서 cache를 사용
    if (ret != -1) return ret;

    int maxLength = 0;
    for (int next = crnt+1; next < N; ++next)
    {
        // crnt가 -1 이면 error가 발생하므로 crnt == -1이면 가상의 최소값인 -1로 값을 대치한다.
        if (A[next] > (crnt == -1 ? -1 : A[crnt])) maxLength = max(maxLength, lis(next));
    }
    return ret = (maxLength + 1); // 자신의 길이를 포함하여 리턴 : +1 한 값
}

int count(int crnt)
{
    // 1. 기저사례
    if (lis(crnt) == 1) return 1;

    // 2. 캐시확인
    int & ret = cacheCnt[crnt + 1]; // -1 index로 인해서 한 칸씩 밀어서 cache를 사용
    if (ret != -1) return ret;

    // 3. 계산
    ret = 0;
    for (int next = crnt+1; next < N; ++next)
    {
        // A[crnt] -> A[next]로 이어지지면서 LIS를 만족하는 경우
        if (A[next] > (crnt == -1 ? -1 : A[crnt])
            && lis(crnt) == lis(next) + 1) 
        {
            ret += count(next);
            // TODO: ret이 int의 범위를 넘어가는 경우가 있다.
            // if (ret >= MAX) ret = MAX;
        }
    }
    return ret;
}

// 이 함수는 LIS의 index를 사전 순서대로 정렬했을때 k 번쨰를 찾는다ㅠㅠ
void calcKthIndexOrder(int crnt, int skip, vector<int> & kthLIS)
{
    for (int next = crnt+1; next < N; ++next)
    {
        if (A[next] > (crnt == -1 ? -1 : A[crnt])
            && lis(crnt) == lis(next) + 1)
        {
            if (skip < count(next))
            {
                kthLIS.push_back(A[next]);
                calcKthIndexOrder(next, skip, kthLIS);
                break;
            }
            skip -= count(next);
        }
    }
}

void calcKth(int crnt, int skip, vector<int> & kthLIS)
{
    vector<pair<int, int>> nextNumbers; // <A[next], next>
    for (int next = crnt+1; next < N; ++next)
    {
        if (A[next] > (crnt == -1 ? -1 : A[crnt])
            && lis(crnt) == lis(next) + 1)
        {
            // 다음에 올 수 있는 수를 모두 추가한다.
            nextNumbers.push_back(make_pair(A[next], next));
        }
    }

    // 추가한 수를 정렬한다.
    sort(nextNumbers.begin(), nextNumbers.end());

    // skip을 줄여가면서 조건에 맞는 A[next]를 찾는다.
    for (pair<int, int> nextNumber : nextNumbers)
    {
        if (skip < count(nextNumber.second))
        {
            kthLIS.push_back(nextNumber.first);
            calcKth(nextNumber.second, skip, kthLIS);
            break;
        }
        skip -= count(nextNumber.second);
    }
}

int main()
{
    memset(cacheLIS, -1, sizeof(cacheLIS));
    memset(cacheCnt, -1, sizeof(cacheCnt));

    int skip;
    cin >> N >> skip;
    skip -= 1; 

    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> kthLIS; // k 번쨰 LIS를 저장할 vector
    calcKth(-1, skip, kthLIS);

    
    cout << lis(-1) - 1 << "\n";
    for (int i = 0; i < kthLIS.size(); ++i)
    {
        cout << kthLIS[i] << " ";
    }
    cout << "\n";

    return 0;
}