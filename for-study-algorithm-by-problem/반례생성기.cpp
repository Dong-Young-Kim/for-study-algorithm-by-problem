#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int trgtChnl, N;
bool brokenButten[10] = {0};

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

int Broken_button[10] = { 0 };
string ch_Parsing;
int ch, tmp;

bool check_Broken(int tmp_ch) {
	string st_ch = to_string(tmp_ch);
	for (int i = 0; i < st_ch.size(); i++) {
		if (Broken_button[st_ch[i] - 48] == 1) return 1;
	}
	return 0;
}

int only_upDown_cnt() {
	return abs(ch - 100);
}

bool check_noMove() {
	if (ch == 100) return 1;
	return 0;
}

bool check_all_Broken() {
	for (int i = 0; i < 10; i++) {
		if (Broken_button[i] == 0) return 0;
	}
	return 1;
}

int find_best_ch() {
	int cur = 100;
	if (!check_Broken(ch)) return ch; //�ν����� ���� �ٷ� ���� ���
	int tmp_ch_up = ch;
	int tmp_ch_down = ch;
	int ret;
	while (1) {
		if (tmp_ch_down == 0) ret = tmp_ch_down++;
		tmp_ch_up++;
		tmp_ch_down--;
		if (tmp_ch_down == 100) { ret = tmp_ch_down; break; }
		if (tmp_ch_up == 100) { ret = tmp_ch_up; break; }
		if (check_Broken(tmp_ch_down) && check_Broken(tmp_ch_up)) continue;
		if (check_Broken(tmp_ch_down)) ret = tmp_ch_up;
		else  ret = tmp_ch_down;
		break;
	}
	return ret;
}

int rightCode() {
	// cin >> ch >> tmp;

    ch = trgtChnl;
    tmp = N;
    
	ch_Parsing = to_string(ch);
	// for (int i = 0; i < tmp; i++) {
	// 	int br;
	// 	cin >> br;
	// 	Broken_button[br] = 1;
	// }

    for (int i = 0; i<10;i++) Broken_button[i] = brokenButten[i];



	if (check_all_Broken()) { return only_upDown_cnt(); }
	// if (check_all_Broken()) { cout << only_upDown_cnt() << endl; return 0; }
	if (check_noMove()) { return 0; }
	// if (check_noMove()) { cout << "0" << endl; return 0; }
	int best_ch = find_best_ch();
	int ret = min((int)(abs(best_ch - ch) + to_string(best_ch).size()), only_upDown_cnt());
	// cout << ret << endl;
    return ret;
	//cout << find_best_ch() << endl;


}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////


string trgtChnlStr;
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
int wrongCode()
{
    // cin >> trgtChnl >> N;
    trgtChnlStr = to_string(trgtChnl);

    // for (int i = 0; i < N; ++i) 
    // {
    //     int broken;
    //     cin >> broken;
    //     brokenButten[broken] = true;
    // }

    int totalBtnPress = 0;
    if (abs(trgtChnl - 100) <= trgtChnlStr.length())
    {
        totalBtnPress = abs(trgtChnl - 100);
    } 
    else
    {
        totalBtnPress = min(findNumMove(), abs(trgtChnl - 100));
    }
    // cout << totalBtnPress << "\n";
    return totalBtnPress;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

void makeTC()
{
    memset(brokenButten, 0, sizeof(brokenButten));
    N = 0;
    trgtChnl = rand() % 1000;
    for (int i = 0; i<10; i++)
    {
        bool btn = rand() % 2;
        if (btn)
        {
            brokenButten[i] = true;
            ++N;
        }
    }
}

int main()
{
    int T = 0;
    while(1)
    {
        makeTC();

        int right, wrong;
        right = rightCode();
        wrong = wrongCode();
        if (right != wrong) 
        {
            cout << "trgtChnl = " << trgtChnl << endl;
            cout << "N = " << N << endl;
            for (int i = 0; i<10;i++)
            {
                if (brokenButten[i] == 1) cout << i << " ";
            }
            cout << endl;
            cout << "right Ans = " << right << endl;
            cout << "worng Ans = " << wrong << endl;
            cout << "======================" << endl;
            break;
        }
        T++;
        if(T%1000 == 0) cout << "T = " << T << endl;
    }
}