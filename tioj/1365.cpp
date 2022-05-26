#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+125;
int query(int x,int* fenwick){
    int ans=0;
    while(x<=N){
        ans+=fenwick[x];
        x+=(x&-x);
    }
    return ans;
}
void add(int x,int* fenwick){
    while(x){
        fenwick[x]+=1;
        x-=(x&-x);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
    pair<int,int> arr[n];
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    int fenwick[N]={0};
    sort(arr,arr+n);
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=query(arr[i].second+1,fenwick);
        add(arr[i].second,fenwick);
    }
    cout<<ans<<endl; 
    }

    return 0;
}