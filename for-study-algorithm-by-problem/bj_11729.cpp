//하노이탑 이동 경로 문제
#include <stdio.h>
#include <math.h>
void hanoiMove(int n, short from, short to){
    if(n==1) printf("%d %d\n", from, to);
    else{
        hanoiMove(n-1, from, 6-from-to);
        hanoiMove(1, from, to);
        hanoiMove(n-1, 6-from-to, to);
    }
}
int main(){
    int num;
    scanf("%d",&num);
    printf("%d\n", (int)pow(2,num)-1);
    hanoiMove(num,1,3);
}

/*
하노이탑 문제는 재귀를 통해서 해결할 수 있다
가장 아래를 제외한 위쪽의 나머지 원판들을 먼저 옮겨놓고
아래 원판을 의도한 위치로 옮긴 후에
다시 나머지 원판들을 옮겨 놓으면 된다
여기서 옮기는 행위는 from과 to 위치를 출력함으로써 구현했다
*/

/*최소 이동 횟수 출력 문제
1 << num 은 2^num 을 표현한 방식이다.
만약 해당 문제에서 pow(2,num)을 사용하였다면, double형을 활용하는 pow의 특성상 입력 최대값인 20이 입력되면 오차범위가 커져 틀렸습니다. 라는 메세지가 출력된다.
따라서 (int)pow(2,num); 을 활용하던가, 아니면 (1<<num) 같이 시프트 연산을 활용한 표현을 사용해야 한다.
*/
