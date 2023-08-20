#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////

#define ON 1
#define OFF 0
#define INF 987654321

int N, numberOfPress;
bool board[18][18];
char temp[18][18];
int dx[5] = {0, -1, 1}, dy[5] = {0, 0, 0, -1, 1};
void toggleLamp(int i, int j)
{
    bool& lamp = board[i][j];
    if(lamp == ON) lamp = OFF;
    else lamp = ON; 
}

void pressLamp(int i, int j)
{
    toggleLamp(i, j);
    if (i-1 >= 0) toggleLamp(i-1, j);
    if (i+1 <  N) toggleLamp(i+1, j);
    if (j-1 >= 0) toggleLamp(i, j-1);
    if (j+1 <  N) toggleLamp(i, j+1);
}

// 0 행은 누른 상태로 호출된다.
void offLamp(int row)
{
    if (row == N)// 모든 램프(마지막 줄)이 모두 꺼졌는지 확인
    {
        for (int j = 0; j < N; ++j)
        {
            // 하나라도 켜저 있다면 INF(불가능)으로 설정
            if(board[N-1][j] == ON) numberOfPress = INF;
        }
        return;
    }


    bool prevLampOn[18] = {0};
    // 이전 줄에서 켜저있는 램프를 확인
    for (int col = 0; col < N; ++col)
    {
        if (board[row-1][col] == ON) prevLampOn[col] = ON;
    }

    // 윗줄에서 켜저있는 램프 아래 램프를 누름
    for (int col = 0; col < N; ++col)
    {
        if (prevLampOn[col] == ON) 
        {
            pressLamp(row, col);
            ++numberOfPress;
        }
    }

    // 다음 줄 확인
    offLamp(row + 1);

    // 누른 램프 원상복구
    for (int col = 0; col < N; ++col)
    {
        if (prevLampOn[col] == ON) pressLamp(row, col);
    }
}

int codeA()
{
    // cin >> N;
    // for (int i = 0; i < N; ++i)
    //     for (int j = 0; j < N; ++j)
    //         cin >> board[i][j];
    
    int minNumberOfPress = INF;

    // 첫 줄인 경우, 한 행에서 모든 전구를 누를 수 있는 조합을 생성한다.
    for (int subset = (1 << N) - 1; subset >= 0; --subset)
    {
        numberOfPress = 0;
        for (int col = 0; col < N; ++col)
        {
            if(subset & (1 << col)) {
                pressLamp(0, col); // 만들어진 조합에 따라서 전구를 누른다.
                ++numberOfPress;
            }
        }

        offLamp(1);

        // 누른 전구를 초기 상태로 원상복구 시킨다
        for (int col = 0; col < N; ++col)
        {
            if(subset & (1 << col)) pressLamp(0, col); 
        }

        minNumberOfPress
            = min(minNumberOfPress, numberOfPress);

    }
    return ((minNumberOfPress == INF) ? -1 : minNumberOfPress);
    // cout << ((minNumberOfPress == INF) ? -1 : minNumberOfPress) << '\n';
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////


void press(int x, int y){
    for (int i = 0; i < 5; i++){
        int nx = x + dx[i], ny = y + dy[i];
		
        if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            temp[nx][ny] = (temp[nx][ny] == 1 ? 0 : 1);
    }
}
int codeB(){
    // scanf("%d", &N);
    // for (int i = 0, val; i < N*N; i++)
    //     scanf(" %c", &board[i/N][i%N]);
		
    int cnt = N*N+1;
    for (int fRow = (1 << N)-1; fRow >= 0; fRow--){
        int temp_cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                temp[i][j] = board[i][j];

        for (int fCol = 0; fCol < N; fCol++)
            if (fRow & (1 << fCol)){
                press(0, fCol);
                temp_cnt++;
            }
		
        for (int nRow = 1; nRow < N; nRow++)
            for (int nCol = 0; nCol < N; nCol++)
                if (temp[nRow-1][nCol] == 1){
                    press(nRow, nCol);
					temp_cnt++;
                }
				
        int flag = 1;
        for (int nCol = 0; nCol < N; nCol++)
            if (temp[N-1][nCol] == 1){
                flag = 0;
                break;
            }
        if (flag) cnt = min(cnt, temp_cnt);
    }
    // printf("%d\n", cnt == N*N+1 ? -1 : cnt);
    return (cnt == N*N+1) ? -1 : cnt;
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

// #include<vector>
// #include<algorithm>
// #include<string>
// #include<cmath>

// vector<vector<int>> vboard;
// vector<vector<int>> tmp_board;
// int first_line = 0;
// int max_first = 0;
// // int N;
// int switch_cnt = 0;

// bool out_of_Range(int y, int x) {
// 	return (y < 0 || y >= N || x < 0 || x >= N);
// }

// bool check_all_off() {
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			if (vboard[i][j] == 1) return 0;
// 		}
// 	}
// 	return 1;
// }

// void toggle_bulb(int y, int x) {
// 	vboard[y][x] ^= (1 << 0);
// }

// void switch_bulb(int y, int x) {
// 	toggle_bulb(y, x);
// 	if (!out_of_Range(y + 1, x)) toggle_bulb(y + 1, x);
// 	if (!out_of_Range(y - 1, x)) toggle_bulb(y - 1, x);
// 	if (!out_of_Range(y, x + 1)) toggle_bulb(y, x + 1);
// 	if (!out_of_Range(y, x - 1)) toggle_bulb(y, x - 1);
// }

// // string itob(int num) {
// // 	if (num == 0) {
// // 		string tmp;
// // 		for (int i = 0; i < N; i++) {
// // 			tmp += "0";
// // 		}
// // 		return tmp;
// // 	}
// // 	string tmp;
// // 	while (num != 1) {
// // 		tmp += (num % 2) + 48;
// // 		num /= 2;
// // 	}
// // 	tmp += "1";//마지막 1을 더해줘야함
// // 	//reverse(tmp.begin(), tmp.end());
// // 	for (int i = 0; i < N - tmp.size(); i++) {
// // 		tmp += "0";
// // 	}
// // 	return tmp;
// // }

// void first_line_setting(int n) {
// 	int cnt = 0;
// 	while (n != 0) {
// 		if ((n & 1) == 1) {
// 			switch_bulb(0, N - cnt - 1);
// 			switch_cnt++;
// 		}
// 		n = n >> 1;
// 		cnt++;
// 	}

// }

// void other_line_setting() {
// 	for (int i = 1; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			if (vboard[i - 1][j] == 1) {
// 				switch_bulb(i, j);
// 				switch_cnt++;
// 			}
// 		}
// 	}
// }

// int codeC() {
// 	// cin >> N;
// 	vector<int> tmp(18);
// 	vboard.resize(18, tmp);
// 	for (int i = 0; i < N; i++) {
// 		for (int j = 0; j < N; j++) {
// 			bool temp;
// 			// cin >> temp;
// 			vboard[i][j] = board[i][j];
// 		}
// 	}
// 	tmp_board = vboard;
// 	int max_first = pow(2, N) - 1; //-1이 들어가야 2^N개 경우의 수가 나옴
// 	int ret = N * N + 1;
// 	for (int subset = max_first; subset > 0; subset = ((subset - 1) & max_first)) {
// 		switch_cnt = 0;
// 		first_line_setting(subset); //첫 라인 셋팅
// 		other_line_setting();
// 		if (!check_all_off()) {
// 			vboard = tmp_board;
// 			continue;
// 		}
// 		ret = min(ret, switch_cnt);
// 		vboard = tmp_board;
// 	}


// 	// if (ret == N * N + 1) cout << "-1" << endl;
// 	if (ret == N * N + 1) return -1;
// 	return ret;
// 	// else cout << ret << endl;
// 	return 0;
// }

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

unsigned int bitBoard[18]; // 열 index는 bit로 구분

inline void toggleLampBit(int i, int j)
{
    bitBoard[i] ^= (1 << j); // bitmask
}

void pressLampBit(int i, int j)
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
        if (prevLampOnBit & (1 << col)) pressLampBit(row, col);
    }
    numberOfPress += __builtin_popcount(prevLampOnBit);


    // 다음 줄 확인
    offLampBit(row + 1);

    // 누른 램프 원상복구
    for (int col = 0; col < N; ++col)
    {
        if (prevLampOnBit & (1 << col)) pressLampBit(row, col);
    }
}

int codeD()
{
    for (int i = 0; i < N; i++)
        bitBoard[i] = 0;
    // cin >> N;
    for (int i = 0; i < N * N; ++i){
        unsigned int tmp;
        // cin >> tmp;
        tmp = board[i / N][i % N];
        bitBoard[i / N] |= (tmp << (i % N)); // bitmask
    }
    
    int minNumberOfPress = INF;

    // for (int subset = (1 << N) - 1; subset > 0; --subset)
    // 이 부분 실수.. 하나도 누르지 않는 경우도 고려했어야

    // 첫 줄인 경우, 한 행에서 모든 전구를 누를 수 있는 조합을 생성한다.
    for (int subset = (1 << N) - 1; subset >= 0; --subset)
    {
        numberOfPress = 0;
        for (int col = 0; col < N; ++col)
        {
            if(subset & (1 << col)) {
                pressLampBit(0, col); // 만들어진 조합에 따라서 전구를 누른다.
            }
        }
        numberOfPress += __builtin_popcount(subset); // bitmask

        offLampBit(1);

        // 누른 전구를 초기 상태로 원상복구 시킨다
        for (int col = 0; col < N; ++col)
        {
            if(subset & (1 << col)) pressLampBit(0, col); 
        }

        minNumberOfPress
            = min(minNumberOfPress, numberOfPress);

    }
    // cout << ((minNumberOfPress == INF) ? -1 : minNumberOfPress) << '\n';
    return ((minNumberOfPress == INF) ? -1 : minNumberOfPress);

}




void makeTC()
{
    N = rand() % 10 + 2;
    // N = rand() % 17 + 2;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = rand() % 2;
    
}

int main()
{
    int T = 0;

    while(1)
    {
        cout << "T = " << T << endl;

        makeTC();
        
        printf("%d\n", N);
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j)
                cout << board[i][j] << " ";
            cout << "\n";
        }

        int right, wrong;
        right = codeA();
        wrong = codeD();
        if (right != wrong) 
        {
            // printf("%d %d %d \n", A, B, C);
            printf("%d\n", N);
            for (int i = 0; i < N; ++i){
                for (int j = 0; j < N; ++j)
                    cout << board[i][j] << " ";
                cout << "\n";
            }


            cout << "right Ans = " << right << endl;
            cout << "wrong Ans = " << wrong << endl;
            cout << "======================" << endl;
            break;
        }
        T++;
        // if(T%10000 == 0) cout << "T = " << T << endl;
    }
}

/*

2
0 0 
0 0 
right Ans = 0
worng Ans = -1

*/