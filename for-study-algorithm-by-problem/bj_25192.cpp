#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
int main() {
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


//for문내 rcrdUser를 초기화하지 않아서 크기가 다른 문제
//정확하게 비교되지 못함


//시간초과 문제
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