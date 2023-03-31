#include <iostream>
using namespace std;

//int main() { 
//	int T, a, b, r;
//	cin >> T;
//	while (T--) {
//		r = 1;
//		cin >> a >> b;
//		while (b--) {r = (r * a) % 10;} // overflow ����
//		if (r == 0) r = 10; //0�� 10�� ��ǻ��!!
//		cout << r << endl;
//	}
//}

int main() { //�ֱ⼺ �̿�
	int T, a, b, r;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		a = a % 10; //scale ����
		b = b % 4; //scale ����
		if (b == 0) b = 4; //4�� ����� ���
		r = 1; //�Ź� ����� �ʱ�ȭ

		if (a == 0) { //0�ΰ�� Ư�� case
			cout << 10 << endl;
			continue;
		}

		while (b--) r *= a; //���� ����

		cout << r % 10 << endl;
	}
}




/*

overflow�� �ذ��ϴ� ����


������ �ڸ��� ���ϱ�

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
��� �ִ� 4�� �ֱ�� �ݺ�

10�ΰ�� 10�� ��ǻ��!!


*/