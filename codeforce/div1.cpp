#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  bool exist array[n]={0};
  queue<int> line;
  int max=0;
  for(int i=0;i<n;i++){
      int k;cin>>k;
      if(k>max) max=k;
      line.push(k);
  }
  while(!line.empty() && max<=n){
     int m =  line.front()
     line.pop();
     if(m<=n&&m>0){
         if(!exist[m-1]){
             exist[m-1]=1;
         }else{
            line.push(m/2);
         }
     }else{
         line.push(m/2);
     }
  }

}