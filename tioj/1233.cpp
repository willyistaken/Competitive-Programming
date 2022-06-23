#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
int a[11] = {0,1,2,4,6,10,12,14,16,18,20};
void dfs(int x,int y,vector<vector<bool> > &arr){
    if(x>=n || x<0 || y>=m || y<0) return ;
    if(!arr[x][y])  return ;
    arr[x][y]=0;
    for(int i=0;i<8;i++){
        dfs(x+dx[i],y+dy[i],arr);
    }
    return ;
}
int main(){
    while(cin>>n>>m){
        vector<vector<bool> > arr(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<m;j++){
                arr[i][j] = s[j]=='1';
            }
        } 
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]){
                    ans+=1;
                    dfs(i,j,arr);
                }
            }
        }
        if(ans>a[10]){
            cout<<10<<endl;
        }else{
            cout<<lower_bound(a,a+11,ans)-a<<"\n";
        }
        
    }



    return 0;
}