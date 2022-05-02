#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long; 
int k,n;int teams[50][11][3];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>n;
   for(int i=0;i<n;i++){
       int s;cin>>s;
       for(int m=0;m<3;m++){      
            for(int j=0;j<2*k+1;j++){
                cin>>teams[s-1][j][m];
             }
       }
   }

   for (int i = n-1; i >= 0; i--) {
    int wincount=0;  
    for(int g=0;g<n;g++){
      int index=2*k;
      int count=0;
      if(g==i) continue;
      for(int j=2*k;j>=0;j--){
          if(teams[i][j][0]>teams[g][index][0] || (teams[i][j][0]==teams[g][index][0] && i<g)){
              count++;
              index--;
          }
      }
      if(count<k+1){
          wincount=1;
          break;
      } 
    }
    if(!wincount){
        cout<<i+1<<" ";
        break;
    }
   }

   for (int i = n-1; i >= 0; i--) {
    int wincount=0;  
    for(int g=0;g<n;g++){
      int index=2*k;
      int count=0;
      if(g==i) continue;
      for(int j=2*k;j>=0;j--){
          if(teams[i][j][1]>teams[g][index][2] || (teams[i][j][1]==teams[g][index][2] && i<g)){
              count++;
              index--;
          }
      }
      if(count<k+1){
          wincount=1;
          break;
      } 
    }
    if(!wincount){
        cout<<i+1<<"\n";
        break;
    }
   }

   


    





    return 0;
}