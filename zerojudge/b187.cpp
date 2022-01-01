#include <bits/stdc++.h>
using namespace std;
int dpresult[101][101]={{0}};
vector<int> vol;
vector<int> profit;
void reset(){
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            dpresult[i][j]=0;
        }
    }
}
int dp(int v,int m){
    
    if(v<0){
        return -1000;
    }
    if(v*m==0){
        return 0;
    }
    if(m<0){
        cout<<"hello this is wrong af"<<endl;
        return 0;
    }
    if(dpresult[v][m]!=0){
        return dpresult[v][m];}
    dpresult[v][m]=max(dp(v-vol[m],m-1)+profit[m],dp(v,m-1));
    return dpresult[v][m];
}
int main(){
    int n;
    while(cin>>n){
        reset();
        vol.clear();profit.clear();
        vol.push_back(0);profit.push_back(0);
        for(int i=0;i<n;i++){
             int a,b;cin>>a>>b;
         vol.push_back(a);profit.push_back(b);
        }
        cout<<dp(100,n)<<endl;
    }
    
}