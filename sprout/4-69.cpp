#include <bits/stdc++.h>
using namespace std;
bool canbeat(vector<pair<int,int> > &myhorse,vector<int> &hishorse,int k,int time,int n){
    if(time==-1) return 0;
    int temparr[n];
    for(int i=0;i<n;i++){
        temparr[i] = myhorse[i].first + (myhorse[i].second*time);
    }    
    sort(temparr,temparr+n);
    int count=0;
    int index=0;
    for(int i=0;i<n;i++){
        if(index>=n) break;
        if(temparr[i]>hishorse[index]){
            count++;
            index++;
        }
    }
    return (count>=k);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
    vector<pair<int,int> > myhorse(n);
    vector<int> hishorse(n);
    for(int i=0;i<n;i++){
        int ta,tb;
        cin>>ta>>tb;
        myhorse[i].first = ta;
        myhorse[i].second = tb;
    }
    for(int i=0;i<n;i++){
        cin>>hishorse[i];
    }
    sort(hishorse.begin(),hishorse.end());
    int l=-1;int r=1e9;
    int mid;
    while(r-l>1){
        mid = (r+l)/2;
        if (canbeat(myhorse,hishorse,k,mid,n)) {
           // cout<<l<<' '<<r<<" 1\n";
            r=mid;
        } else {
            l=mid;
           // cout<<l<<' '<<r<<" 0\n";
        }
    }
    if(r<1e9){
        cout<<r<<endl;
    }else{
        cout<<-1<<endl;
        }
    }   
}