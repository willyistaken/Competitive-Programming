#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void move(int n,int from,int to,int* i){
    if(n==1){
        (*i)+=1;
        printf("#%d : move the dish from #%d to #%d\n",*i,from,to);
        return;
    }
    move(n-1,from,(6/from)/to,i);
    move(1,from,to,i);
    move(n-1,(6/from)/to,to,i);
}
int main(){
    int n;
    scanf("%d",&n);
    int i=0;
    move(n,1,3,&i);
    return 0;
}