#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[500010];
int k;
const int mod = 1e9+7;

int mp(int n){
 
     n = ((n >> 16) ^ n) * 0x45d9f3b;
    n = ((n >> 16) ^ n) * 0x45d9f3b;
    n = (n >> 16) ^ n;// from stack overflow(a uniform hash function for int32);
    return n;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,Q;
    cin>>N>>k>>Q;
    int sum[N+1]={0};
    for(int i=1;i<=N;i++){
        int a;cin>>a;
        num[a]+=1;
        if(num[a]%k){
            sum[i]=(sum[i-1]+(mp(a)%mod))%mod;
        }else{
            sum[i]=(sum[i-1]+((1LL*(1-k)*mp(a))%mod))%mod;
        }
        //cout<<sum[i]-sum[i-1]<<"| |";
    } 
    for(int i=0;i<Q;i++){
        int l,r;cin>>l>>r;
        cout<<((sum[r]-sum[l-1])%mod==0);//note to self:remember this;
    }
    cout<<endl;
    return 0;
}

/*
10 2 10
1 2 3 2 4 4 3 1 3 1
1 8
1 10
5 6
1 4
5 10
2 7
1 7
8 9
7 9
3 7
*/