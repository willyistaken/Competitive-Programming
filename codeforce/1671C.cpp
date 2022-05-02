#include <bits/stdc++.h>
using namespace std;
int myupperbound(vector<long long> &sum,int day,int x,int n){
    int r=n+1;
    int l=0;
    while(r-l>1){
        int mid=l+((r-l)/2);
        if(sum[mid]+(1LL*mid*day) > (long long)x){
            r=mid;
        }else{
            l=mid;
        }
    }
    return l;
}
int main(){
    int t;cin>>t;
    while(t--){
      int n;cin>>n;
    int x;cin>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    vector<long long> sum(n+1,0);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i-1];
    }
    int packday= myupperbound(sum,0,x,n);
    int day=1;
    long long ans=0;
    while(packday){
        ans+=packday;
        packday = myupperbound(sum,day,x,n);
        day++;
    }
    cout<<ans<<endl;  
    }
    
}