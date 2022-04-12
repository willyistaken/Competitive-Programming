#include <bits/stdc++.h>
using namespace std;

/* vector<vector<int> > grid;
int GetVal(int p,int q){
    return grid[p-1][q-1];
}
void Report(int a){
    cout<<a<<endl;
} */
void mysolve(int t,int d,int l,int r){
    if(d-t==1){
        int maxv = INT_MIN;
        for(int i=l;i<=r;i++){
            maxv = max(maxv,GetVal(t,i));
        }
        Report(maxv);  
        maxv = INT_MIN;
        for(int i=l;i<=r;i++){
            maxv = max(maxv,GetVal(d,i));
        }
        Report(maxv);
        
    }else if(d==t){
        int maxv = INT_MIN;
        for(int i=l;i<=r;i++){
            maxv = max(maxv,GetVal(d,i));
        }
        Report(maxv);
    } else{
    int mid = (t+d)/2;
    int maxind=0;int maxv=INT_MIN;
    for(int i= l;i<=r;i++){
        int querry = GetVal(mid,i);
        if(querry>maxv){
            maxind=i;
            maxv=querry;
        } 
    }
    mysolve(t,mid-1,l,maxind-1);
    Report(maxv);
    mysolve(mid+1,d,maxind+1,r);
    }
}
void solve(int n,int m){
    mysolve(1,n,1,m);
}
/* int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        vector<int> te;
        for(int j=0;j<m;j++){
            int x;cin>>x;
            te.push_back(x);
        }
        grid.push_back(te);
    }
    solve(n,m);
} */