// bitmask를 더욱 구현하고
// 원상복구 방식을 memcpy로 대체

#include <iostream>
#include <memory.h>
using namespace std;

#define INF 987654321

int N, numberOfPress;
unsigned int bitBoard[18], originBoard[18]; // 열 index는 bit로 구분

inline void toggleLampBit(int i, int j)
{
    bitBoard[i] ^= (1 << j); // bitmask
}

void pressLamp(int i, int j)
{
    toggleLampBit(i, j);
    if (i-1 >= 0) toggleLampBit(i-1, j);
    if (i+1 <  N) toggleLampBit(i+1, j);
    if (j-1 >= 0) toggleLampBit(i, j-1);
    if (j+1 <  N) toggleLampBit(i, j+1);
}

// 0 행은 누른 상태로 호출된다.
void offLampBit(int row)
{
    if (row == N)// 모든 램프(마지막 줄)이 모두 꺼졌는지 확인
    {
        if (bitBoard[N-1] != 0) numberOfPress = INF; // bitmask
        return;
    }

    // 이전 줄에서 켜저있는 램프를 위치를 복사
    unsigned int prevLampOnBit = bitBoard[row-1];

    for (int col = 0; col < N; ++col)
    {
        if (prevLampOnBit & (1 << col)) pressLamp(row, col);
    }
    numberOfPress += __builtin_popcount(prevLampOnBit);

    // 다음 줄 확인
    offLampBit(row + 1);

}

int main()
{
    cin >> N;
    for (int i = 0; i < N * N; ++i){
        unsigned int tmp;
        cin >> tmp;
        originBoard[i / N] |= (tmp << (i % N)); // bitmask
    }
    
    int minNumberOfPress = INF;

    // 첫 줄인 경우, 한 행에서 모든 전구를 누를 수 있는 조합을 생성한다.
    for (int subset = (1 << N) - 1; subset >= 0; --subset)
    {
        memcpy(bitBoard, originBoard, sizeof(bitBoard));
        numberOfPress = 0;
        for (int col = 0; col < N; ++col)
        {
            if (subset & (1 << col)) {
                pressLamp(0, col); // 만들어진 조합에 따라서 전구를 누른다.
            }
        }
        numberOfPress += __builtin_popcount(subset); // bitmask

        offLampBit(1);

        minNumberOfPress
            = min(minNumberOfPress, numberOfPress);

    }
    printf("%d", (minNumberOfPress == INF) ? -1 : minNumberOfPress);
}

// #include<bits/stdc++.h>
// int n, y[20], x[20], mi = 325, cnt;
// int main(){
// 	std::cin >> n;
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j < n; j++) {
// 			int tmp;
// 			std::cin >> tmp;
// 			x[i] *= 2;
// 			x[i] += tmp;
// 		}
// 	}
// 	for (x[0] = 0; x[0] < (1 << n); x[0]++) {
// 		cnt = 0;
// 		for (int i = 0; i <= n; i++)
// 			y[i] = x[i];
// 		for (int i = 0; i < n; i++)for(int j = n - 1; ~j; j--)
// 				if (y[i] & (1 << j)) {
// 					y[i] ^= (1 << j);
// 					y[i + 1] ^= ((7 << j) >> 1);
// 					y[i + 2] ^= (1 << j);
// 					cnt++;
//                 }
// 		bool f=1;
// 		for (int i = 1; i <= n; i++)
// 			if (y[i] & ((1 << n) - 1))
// 				f=0;
// 		if (f)
// 			mi = std::min(mi,cnt);
// 	}
// 	std::cout << ((mi - 325) ? (mi) : (-1));
// }



// 32ms
// #include <iostream>
// #include <algorithm>
// #include <cstring>

// using namespace std;
// using ll = long long;

// //#ifdef GCC
// #define POPCNT(x) __builtin_popcount(x)
// //#endif

// //#ifndef GCC
// //#include <intrin.h>
// //#define POPCNT(x) __popcnt(x)
// //#endif

// int initMap[20];
// int map[20];
// int main()
// {
// 	int N;
// 	int temp, cur, next;
// 	unsigned int minCount = -1;
// 	unsigned int curCount;
// 	ios_base::sync_with_stdio(false);
// 	cin >> N;
// 	for (int i = 1; i <= N; i++) {
// 		cur = 0;
// 		for (int j = 1; j <= N; j++) {
// 			cin >> temp;
// 			cur = (cur << 1) | temp;
// 		}
// 		initMap[i] = cur;
// 	}
// 	int until = (0x1 << N) - 1;
// 	for (int start = 0; start <= until; start++) {
// 		memcpy(map, initMap, sizeof(map));
// 		cur = (start << 1) ^ start ^ (start >> 1);
// 		next = start;
// 		curCount = POPCNT(next);
// 		map[1] ^= cur;
// 		map[2] ^= next;
// 		for (int i = 2; i <= N; i++) {
// 			next = map[i - 1] & until;
// 			cur = (next << 1) ^ next ^ (next >> 1);
// 			map[i] ^= cur;
// 			map[i + 1] ^= next;
// 			curCount += POPCNT(next);
// 		}
// 		if ((map[N] & until) != 0) continue;
// 		minCount = std::min(minCount, curCount);
// 	}
// 	cout << (int)minCount;
// 	return 0;
// }