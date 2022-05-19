#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
    ll loc[n+1];ll fish[n];
    ll maxn=0;
    ll minn=LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        cin>>loc[i+1]>>fish[i];
        maxn = max(maxn,fish[i]);
        minn = min(minn,fish[i]);
    }

    ll l=minn;ll r=maxn;
    loc[0]=loc[1];
    while(r-l>1){
        ll mid = l+((r-l)/2);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=fish[i]-mid;
            sum+=loc[i]-loc[i+1];
        }
        if(sum>=0){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<l<<endl;
    }




    return 0;
}

//think of it as borrowing and returning  negative and positive doesn't make a difference