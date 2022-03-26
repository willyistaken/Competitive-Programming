#include <bits/stdc++.h>
using namespace std;

int arr[1000];
long long sum[1001];

pair<int,int> save[1000][1000];

pair<int,int> solve(int l,int r){
    if(save[l][r].first!=0){
        return save[l][r];
    }
    if(r-l==1){
        save[l][r]=make_pair(max(arr[l],arr[r]),min(arr[l],arr[r]));
        return save[l][r];
    }
    int fi = max(solve(l+1,r).second+arr[l],solve(l,r-1).second+arr[r]);
    save[l][r]= make_pair(fi, sum[r+1]-sum[l]-fi);
    return  save[l][r];
}


int main(){
    int n;cin>>n;
    sum[0]=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum[i+1]=sum[i]+arr[i];
    }
    auto ans = solve(0,n-1);
    cout<<ans.first<<" "<<ans.second<<endl;
}