#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void change(int ind,ll* bit){
    ind+=1;
    while(ind<=n+1){
        bit[ind]+=1;
        ind+=(ind & -ind);
    }
}
ll query(int ind,ll* bit){
    ind+=1;
    ll sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind -= (ind & -ind);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n && n){
        int arr[n];
        for(int i=0;i<n;i++){
            char c;cin>>c;
            int a;cin>>a;
            a=(c=='w') ? -a:a;
            arr[i]=a;
        }
        ll now=max(arr[0],0);
        ll maxn=now;
        for(int i=1;i<n;i++){
            now=max(0LL,now+arr[i]);
            maxn=max(maxn,now);
        }
        pair<ll,int> sum[n+1]={{0,0}};
        for(int i=1;i<=n;i++){
            sum[i]={sum[i-1].first+arr[i-1],i};
        }
        sort(sum,sum+n+1);
        ll bit[n+2]={0};
        ll ans=0;
        for(int i=0;i<=n;i++){
            ans+=query(sum[i].second,bit);
            change(sum[i].second,bit);
        }
        cout<<ans<<" "<<maxn<<endl;
    }


    return 0;
}

//not finish