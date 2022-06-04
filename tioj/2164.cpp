#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cor{
    int x;
    int y;
    int z;
};
inline ll dis(cor &a,cor &b){
    return 1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y) + 1LL*(a.z-b.z)*(a.z-b.z);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    cor arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y>>arr[i].z;
    }
    vector<vector<ll> > side(n,vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            side[i][j]=dis(arr[i],arr[j]);
        }
    }

    ll ans=0;
    vector<bool> vis(n,0);
    vis[0]=1;
    vector<ll> p(n,1e15);
    for(int i=0;i<n;i++){
        p[i]=min(p[i],side[0][i]);
    }
    for(int i=1;i<n;i++){
        ll minn = LONG_LONG_MAX;
        int to=-1;
        for(int j=0;j<n;j++){
            if(!vis[j]){
                to = (minn>p[j]) ? j:to;
                minn=min(p[j],minn);

            }
        }
        ans+=minn;
        vis[to]=1;
        for(int k=0;k<n;k++){
            p[k]=min(p[k],side[to][k]);
        }
    }
    
    cout<<ans<<endl;



    return 0;
}