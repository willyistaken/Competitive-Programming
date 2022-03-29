#include <bits/stdc++.h>
using namespace std;
bool canbeat(vector<pair<int,int> > &myhorse,vector<int> &hishorse,int k,int time,int n){
    if(time==-1) return 0;
    long long temparr[n] = {0};
    for(int i=0;i<n;i++){
        temparr[i] = (long long)myhorse[i].first + (long long)((myhorse[i].second)*(long long) time);
    }    
    sort(temparr,temparr+n);
    int count=0;
    int index=0;
    for(int i=0;i<n;i++){
        if(temparr[i]>hishorse[index]){
            count++;
            index++;
        }
    }
    return (count>=k);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n,k;cin>>n>>k;
    vector<pair<int,int> > myhorse(n,make_pair(0,0));
    vector<int> hishorse(n,0);
    for(int i=0; i<n; i++){
        int ta,tb;
        cin>>ta>>tb;
        myhorse[i].first = ta;
        myhorse[i].second = tb;
    }
    for(int i=0; i<n; i++){
        cin>>hishorse[i];
    }
    sort(hishorse.begin(),hishorse.end());
    int l=-1;int r=1e9;
    int mid;
    while(r-l>1){
        mid = (r+l)/2;
        if (canbeat(myhorse,hishorse,k,mid,n)) {
            r=mid;
        } else {
            l=mid;
        }
    }
    if(r<1e9){
        cout<<r<<endl;
    }else{
        cout<<-1<<endl;
        }
    }   
}