#include <bits/stdc++.h>
using namespace std;
bool notpossible(priority_queue<int> cap , vector<int> &ripe, int k){
    for(int i=k-1;i>=0;i--){
        if(ripe[i]>cap.top()){
            return 1;
        }

        int bc = cap.top();
        cap.pop();
        bc -= ripe[i];
        cap.push(bc);
    }
    return 0;
}
int main(){
    int t;cin>>t;
    while(t--){

    int n,m;cin>>n>>m;
    priority_queue<int> cap; 
    vector<int> ripe(m,0);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        cap.push(a);
    }
    for(int i=0;i<m;i++){
        cin>>ripe[i];
    }
    sort(ripe.begin(),ripe.end() );
    
    int r=m+1;int l=0;
    while(r-l>1){
        int mid = (r+l)/2;
        if(notpossible(cap,ripe,mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
     cout<<l<<endl;

}
}