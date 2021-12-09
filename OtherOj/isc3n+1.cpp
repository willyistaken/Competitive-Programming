#include <iostream>
using namespace std;

int main(){
    int q;cin>>q;
    int n=1000001;
    long long c = 1000000007;
    
    int d[100];
    d[1]=0;
    for(int i=2;i<=n;i++){
        int m=1;
        if(i%2!=0) m=-1;
        d[i]=(i*d[i-1]+m)%c;
        
    }
    for(int j=0;j<q;j++){
        int a;cin>>a;
        cout<<d[a]<<endl;
    }
}