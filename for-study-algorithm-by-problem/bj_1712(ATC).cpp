#include<iostream>
using namespace std;

int A, B, C;

int wrongCode() { // 틀린원인 = 오버플로우
	int cost, price, totalCost, totalIncome = 0, i = 0;
	// cin >> totalCost >> cost >> price;
    totalCost = A; cost = B; price = C;
	if (cost >= price) return -1;
	// if (cost >= price) cout << "-1";
	else {
		while (totalCost >= totalIncome) {
			totalCost += cost;
			totalIncome += price;
			i++;
		}
		// cout << i;
        return i;
	}
}

int rightCode() {
	int totalCost, cost, price;
    totalCost = A; cost = B; price = C;
	// cin >> totalCost >> cost >> price;
	if (cost >= price) return -1;
	// if (cost >= price) cout << "-1";
	else return totalCost / (price - cost) + 1;
	// else cout << totalCost / (price - cost) + 1;
}

void makeTC()
{
    A = rand() % 987654321;
    B = rand() % 987654321;
    C = rand() % 987654321;
}

int main()
{
    int T = 0;

    cout << "start\n";

    while(1)
    {
        makeTC();

        int right, wrong;
        right = rightCode();
        wrong = wrongCode();
        if (right != wrong) 
        {
            printf("%d %d %d \n", A, B, C);

            cout << "right Ans = " << right << endl;
            cout << "worng Ans = " << wrong << endl;
            cout << "======================" << endl;
            break;
        }
        T++;
        if(T%10000 == 0) cout << "T = " << T << endl;
    }
}

/*
start
101027544 470196557 471123602 
right Ans = 109
worng Ans = 41


101027544 
470196557 
471123602 

*/
