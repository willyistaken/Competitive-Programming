#pragma GCC optimize("Ofast")
#include <cstdio>
#include <vector>
#include <utility>
#include <string>
using namespace std;
#define ll long long;
inline pair<int,char> mymax(pair<int,char> &a,pair<int,char> &b,pair<int,char> &c){
    if(a>b){
        if(b>=c){
         return {a.first,2};
        }else {
            if(c>a) return {c.first,4};
            return {a.first,2};
        }
    }else{
        if(a>=c){
            return {b.first,3};
        }else{
            if(c>b) return {c.first,4};
            return {b.first,3};
        }
    }
}
int dx[4]={-1,-1,0,-1};
int dy[4]={-1,0,-1,-1};
int main(){
    int t;scanf("%d",&t);
    while(t--){
    int n,m;
    scanf("%d %d",&n,&m);
    char ans1[n];char ans2[m];
    scanf("%s",ans1);
    scanf("%s",ans2);
    pair<int,char> dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]={0,0};
            }else{
                if(ans1[i-1]==ans2[j-1]){
                    dp[i][j]={dp[i-1][j-1].first+1,1};
                }else{
                    dp[i][j] = mymax(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
                }
            }
        }
    }
    int x=n;int y=m;
    vector<char> realans;
    while(dp[x][y].first){
        if(dp[x][y].second==(char)1) realans.push_back(ans1[x-1]);
            int chari = dp[x][y].second;
            x+=dx[chari-1];
            y+=dy[chari-1];
    }
    if(realans.empty()){
        puts("*");
    }else{
    for(auto i=realans.rbegin();i!=realans.rend();i++){
            printf("%c",*i);
        }
        printf("\n");
    } 
  
    }
    








    return 0;
}