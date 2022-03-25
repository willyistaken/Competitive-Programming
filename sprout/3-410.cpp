#include <bits/stdc++.h>
using namespace std;

int asked[1505];
void initialize(int n){
    for(int i=0;i<n;i++){
        asked[i]=0;
    }
}
int hasEdge(int a, int b){
    int m = max(a,b);
    ++asked[m];
      if(asked[m]==m){
          return 1;
      }else{
          return 0;
      }
}