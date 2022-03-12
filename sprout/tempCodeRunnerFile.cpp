#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
    pair<int,int> arr[n+1];
    fill(arr,arr+n+1,make_pair(1,-1));
    for(int i=0;i<m;i++){
       /* for(int w=1;w<=n;w++){
            cout<<arr[w].first<<",\n"[w==n];
        }*/
        int to,from;cin>>to>>from;
        arr[from].second=to;
        int cur=to;
        while(arr[cur].second!=-1){
            arr[cur].first+=arr[from].first;
            cur = arr[cur].second;
        }
        arr[cur].first+=arr[from].first;

    }

    int q;cin>>q;
    for(int j=0;j<q;j++){
        int a;cin>>a;
        cout<<arr[a].first<<endl;
    }
    }
    
}