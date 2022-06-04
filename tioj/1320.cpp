#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int right[n];
    int left[n];
    stack<int> mono;
    left[0]=0; mono.push(0);
    for(int i=1;i<n;i++){
        while(!mono.empty()){
            if(arr[mono.top()]>arr[i]){
                break;
            }
            mono.pop();
        }
        left[i]=(mono.empty()) ? 0:mono.top()+1;
        mono.push(i);
    }
    while(!mono.empty()) mono.pop();
    right[n-1]=n-1;mono.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!mono.empty()){
            if(arr[mono.top()]>arr[i]){
                break;
            }
            mono.pop();
        }
        right[i] = (mono.empty()) ? n-1:mono.top()-1;
        mono.push(i);
    }
    vector<pair<int,int> > bs;
    for(int i=0;i<n;i++){
        bs.push_back({right[i]-left[i]+1,arr[i]});
    }
    sort(bs.begin(),bs.end());

    int q;cin>>q;
    int ans[n];
    ans[n-1]=bs[n-1].second;
    int minn=ans[n-1];
    for(int i=n-2;i>=0;i--){
        minn=min(minn,bs[i].second);
        ans[i]=minn;
    }
    for(;q;q--){
        int d;cin>>d;
        int it = lower_bound(bs.begin(),bs.end(),make_pair(d,0))-bs.begin();
        cout<<ans[it]<<"\n";
    } 


    return 0;
}