#include<iostream>
#include<set>
//#include<vector>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T, gomgom = 0;
	set<string> usrRecord;
	cin >> T;
	string crntUser;
	while (T--) {		
		cin >> crntUser;
		if (crntUser == "ENTER") {
			gomgom += usrRecord.size();
			usrRecord.clear();
		}
		else {
			usrRecord.insert(crntUser);
		}
	}
	gomgom += usrRecord.size();
	cout << gomgom << endl;
}


//위 코드에서는 set 사용

//cin 시간 감소를 위해서 사용 100ms -> 64ms
//cin.tie(NULL);
//cout.tie(NULL);
//ios_base::sync_with_stdio(false);

//시간초과 문제 (매번 비교시 마다 n의 시간 소요)
//int main() {
//	int T, gomgom = 0;
//	vector<string> usrRecord;
//	cin >> T;
//	string crntUser;
//	while (T--) {
//		cin >> crntUser;
//		//scanf_s("%s", &crntUser, 21);
//		if (crntUser == "ENTER") usrRecord.clear();
//		else {
//			bool alreadyGomgom = 0;
//			for (string& rcrdUser : usrRecord) {
//				if (crntUser == rcrdUser) {
//					alreadyGomgom = 1;
//					break;
//				}
//			}
//			if (!alreadyGomgom) {
//				usrRecord.push_back(crntUser);
//				gomgom++;
//			}
//		}
//	}
//	cout << gomgom << endl;
//}

// for문내 rcrdUser를 초기화하지 않아서 크기가 다른 문제
// vector 내 저장된 string과 입력된 string이 실제로는 같음에도 다르다고 판단됨
// 크기 또한 다르다고 출력됨