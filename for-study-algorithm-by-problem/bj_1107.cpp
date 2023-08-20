# include <iostream>
# include <string>

using namespace std;

int trgtChnl, N;
string trgtChnlStr;
bool brokenButten[10] = {0}; // 고장난 버튼을 해당 index에 기록 (시간 복잡도 감소)

// 원하는 채널 버튼을 누를 수 있는가
bool canNumMove(int channel)
{
    string chnlString = to_string(channel);
    for (char num : chnlString)
    {
        if (brokenButten[num - 48] == 1) return false;
    }
    return true;
}

// 숫자 + (+-) 버튼을 눌러야 하는 경우 이 함수를 호출한다.
// 총 몇 번 눌러야 하는지를 반환한다.
int findNumMove()
{
    if (canNumMove(trgtChnl)) // 숫자만 눌러서 한 번에 이동할 수 있다면
    {
        return trgtChnlStr.length();
    }

    int midChUp = trgtChnl;
    int midChDn = trgtChnl;

    int targetMid;
    while(true)
    {
        ++midChUp;
        if (midChDn != 0) --midChDn;

        if (midChUp == 100) return abs(trgtChnl - midChUp);
        if (midChDn == 100) return abs(trgtChnl - midChUp);

        if (canNumMove(midChDn)) {targetMid = midChDn; break;}
        if (canNumMove(midChUp)) {targetMid = midChUp; break;}
    }
    return to_string(targetMid).length() + abs(trgtChnl - targetMid);
}

int main()
{
    cin >> trgtChnl >> N;
    trgtChnlStr = to_string(trgtChnl);

    for (int i = 0; i < N; ++i) 
    {
        int broken;
        cin >> broken;
        brokenButten[broken] = true;
    }

    int totalBtnPress = 0;
    if (abs(trgtChnl - 100) <= trgtChnlStr.length())
    {
        totalBtnPress = abs(trgtChnl - 100);
    } 
    else
    {
        totalBtnPress = min(findNumMove(), abs(trgtChnl - 100));
    }
    cout << totalBtnPress << "\n";
}

/*

이동하는 방법

1. +- 버튼만 눌러서 이동하기 // 목표채널 - 100 = 버튼횟수
2. 숫자 버튼만 눌러서 이동하기 // 채널의 자릿수 = 버튼횟수
3. 둘다 눌러서 이동하기 // 채널의 자릿수 + (이동한 채널 - 100)
4. 이동을 하지 않아도 원래부터 채널이 맞음

// 한 칸만 이동한다면 버튼을 누르는 것 보다 직접 이동하는것이 빠를수도 있다.
// 모든 버튼이 고장났다면 +- 버튼만 눌러서 이동해야 한다.

풀이법
우선 +-만 누르는 것이 숫자만 눌러서 이동하는 것 보다 빠른지 확인한다.
(이떄 4. 의 케이스도 한번에 확인할 수 있음)



*/

// Dn 과 Up이 동시에 만족되는 경우가 있음
// 이 경우 두개를 모두 시도해 본 후 min 값을 반환해야
/*
1555
8
0 1 3 4 5 6 7 9

670
*/

/*
6711
2
1 2

23
*/

/*
끝까지 해결 못했던 반례

106
4
0 3 7 9

6

오답 = 8

*/