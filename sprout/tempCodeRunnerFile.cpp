#include <bits/stdc++.h>
using namespace std;
bool canbeat(pair<int,int>* myhorse,int* hishorse,int k,int time,int n){
    if(time==-1) return 0;
    int temparr[n];
    for(int i=0;i<n;i++){
        temparr[i] = (*(myhorse+i)).first+(((*(myhorse+i)).second)*time);
    }    
    sort(temparr,temparr+n);
    int count=0;
    for(int i=0;i<n;i++){
       // if(count>=k) break;
        if(temparr[i]>*(hishorse+i) ){
            ++count;
        }
    }
    return (count>=k);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
    pair<int,int> myhorse[n];
    int hishorse[n];
    for(int i=0;i<n;i++){
        cin>>myhorse[i].first>>myhorse[i].second;
    }
    for(int i=0;i<n;i++){
        cin>>hishorse[i];
    }
    sort(hishorse,hishorse+n,less<int>());
    int l=-1;int r=1000000000;
    int mid ;
    while(r-l>1){
        mid = l+((r-l)/2);
        if (canbeat(myhorse,hishorse,k,mid,n)) {
            r=mid;
        } else {
            l=mid;
        }
    }
    if(canbeat(myhorse,hishorse,k,r,n)){
        cout<<r<<endl;
    }else{
        cout<<-1<<endl;
    }
    }
    
}