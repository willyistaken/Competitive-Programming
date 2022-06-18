#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;int n,m;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;int q;cin>>q;
    vector<vector<pair<int,int> > > lr(n,vector<pair<int,int> > (m,{1,1}));
    vector<vector<int> > hozlen(n,vector<int>(m,0));
    vector<vector<int> > arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j-1>=0 && arr[i][j-1]==arr[i][j] )  lr[i][j].first=lr[i][j-1].first+1;
        }
        for(int j=m-1;j>=0;j--){
            if(j+1<m && arr[i][j+1]==arr[i][j] )  lr[i][j].second=lr[i][j+1].second+1;
            hozlen[i][j] = 2*min(lr[i][j].first,lr[i][j].second)-1;
        }
    }
    for(int i=0;i<q;i++){
        int x,y;cin>>x>>y;
        int ans=1;
        int nowmin = hozlen[x][y];
        for(int i=1;x+i<n&&x-i>=0;i++){
            if(arr[x+i][y]!=arr[x][y] || arr[x-i][y]!=arr[x][y]) break;
            nowmin = min(nowmin,hozlen[x+i][y]);
            nowmin = min(nowmin,hozlen[x+i][y]);
            ans = max(ans,min(2*i+1,nowmin));
        }
        cout<<ans<<endl;
    }




    return 0;
}