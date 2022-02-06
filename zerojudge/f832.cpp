#include <bits/stdc++.h>
using namespace std;
int w[100005];
int c[100005];

bool possible(long long vaule,int n,int m){
    int noww=0;
    int nowc=0;
    long long ans=0;
    while(ans<vaule&&noww<n&&nowc<m&&ans<vaule){
        if(w[noww]<=c[nowc]){
            ans+=w[noww];
            ++noww;
            ++nowc;
        }else{
            ++noww;
        }
    }
    return ans>=vaule;
}

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
     for(int i=0;i<m;i++){
        cin>>c[i];
    }
    sort(w,w+n,greater<int>());
    sort(c,c+m,greater<int>());
    long long r=1e9*n; long long l=0;
    long long ans=0;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(possible(mid,n,m)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
}

//binary search