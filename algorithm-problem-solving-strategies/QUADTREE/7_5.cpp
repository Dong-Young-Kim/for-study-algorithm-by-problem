// 압축 해제 알고리즘

#include<iostream>
#include<string>

using namespace std;

#define MAX_SIZE 16

char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(std::string::iterator& it, int x, int y, int size)
{

    char cur_str = *it;
    it++; // 현재 위치를 저장하고 다음 연산을 위해 iterator를 한칸 이동

    if(cur_str == 'b' || cur_str == 'w')
    {
        for (int dx = 0; dx < size; dx++)
            for (int dy = 0; dy < size; dy++)
                decompressed[x+dx][y+dy] = cur_str;
    }
    else
    {
        int halfSize = size / 2;
        decompress(it, x, y, halfSize);
        decompress(it, x + halfSize, y, halfSize);
        decompress(it, x, y + halfSize, halfSize);
        decompress(it, x + halfSize, y + halfSize, halfSize);
    }
}

int main () 
{
    string compressed ("xxwwwbxwxwbbbwwxxxwwbbbwwwwbb");
    // string compressed ("xxbwwbbbw");
    // string compressed ("xwbbw");

    string::iterator it = compressed.begin();
    decompress (it, 0, 0, MAX_SIZE);
        for (int dx = 0; dx < MAX_SIZE; dx++) {
            for (int dy = 0; dy < MAX_SIZE; dy++) {
                printf("%c", decompressed[dx][dy] == 'b' ? '.' : '#');
            }
            printf("\n");
        }

}