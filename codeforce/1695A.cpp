#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int arr[n][m];
        int maxn = -10000000;
        pair<int,int> loc ={0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
                loc = (maxn<arr[i][j]) ? make_pair(i,j):loc;
                maxn = max(maxn,arr[i][j]);
            }
        }
        int x = max(n-loc.first,loc.first+1);
        int y = max(m-loc.second,loc.second+1);
        cout<<x*y<<endl;

    }







    return 0;
}