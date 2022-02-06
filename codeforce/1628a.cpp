#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
bitset<200005>ha;
struct pa{
    int locate;
    int vaule;
};
pa mex(int l,int r,int arr[]){
   ha.reset();
    int m=0;
    int ans=l;
    int last=0;
    for(int i=l;i<=r;i++){
       ha.set(arr[i]);
        if(ha[m]){
            while(ha[m]) m++;
        }
        if(m!=last) ans=i;
        last=m;
    }
    pa par;
    par.locate=ans;
    par.vaule=last;
    return par;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
       int n;cin>>n;
    int ans=0;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    queue<int> reans;
    pa l;
    l.locate=-1;
    l.vaule=0;
    while(l.locate<n-1 ){
        l=mex(l.locate+1,n-1,array);
        ans++;
        reans.push(l.vaule);
    }
    cout<<ans<<endl; 
    while(!reans.empty()){
        cout<<reans.front()<<" ";
        reans.pop();
    }
    cout<<"\n";
    }
    
}