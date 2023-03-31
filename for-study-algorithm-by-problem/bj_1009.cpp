#include <iostream>
using namespace std;

//int main() { 
//	int T, a, b, r;
//	cin >> T;
//	while (T--) {
//		r = 1;
//		cin >> a >> b;
//		while (b--) {r = (r * a) % 10;} // overflow 방지
//		if (r == 0) r = 10; //0은 10번 컴퓨터!!
//		cout << r << endl;
//	}
//}

int main() { //주기성 이용
	int T, a, b, r;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		a = a % 10; //scale 줄임
		b = b % 4; //scale 줄임
		if (b == 0) b = 4; //4의 배수인 경우
		r = 1; //매번 결과값 초기화

		if (a == 0) { //0인경우 특수 case
			cout << 10 << endl;
			continue;
		}

		while (b--) r *= a; //제곱 연산

		cout << r % 10 << endl;
	}
}




/*

overflow를 해결하는 문제


마지막 자릿수 구하기

1-> 1 1 1 1 1 ...
2-> 2 4 8 6 2 ...
3-> 3 9 7 1 3 ...
4-> 4 6 4 6 4 ...
5-> 5 5 5 5 5 ...
6-> 6 6 6 6 6 ...
7-> 7 9 3 1 7 ...
8-> 8 4 2 6 8 ...
9-> 9 1 9 1 9 ...
0-> 0 0 0 0 0 ...
모두 최대 4번 주기로 반복

10인경우 10번 컴퓨터!!


*/