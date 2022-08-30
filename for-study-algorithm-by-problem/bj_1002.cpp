

#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b,c,d,e,f,T;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d>>e>>f;
        float dist = sqrt((a-c)*(a-c) + (b-d)*(b-d));
        if(dist==0 && e==f) cout<<-1<<endl; //first if
        else if((e+f==dist) || (abs(e-f)==dist)) cout<<1<<endl;
        else if((dist<e+f) && (abs(e-f)<dist)) cout<<2<<endl;
        else cout<<0<<endl;
    }
}

//선후관계 중요
//어떤 if를 먼저 쓰냐에 따라서 결과가 달라질 수 있음