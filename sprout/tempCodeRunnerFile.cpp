#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    stack<pair<int,int>> mono;

    int left[n];
    left[0]=0;
    mono.push(pair<int,int>(0,arr[0]));
    for(int i=1;i<n;i++){
      while(!mono.empty() && mono.top().second>=arr[i]){
          mono.pop();
      }
      if(mono.empty()){
          left[i]=0;
      }else{
          left[i]=mono.top().first+1;
      }
      mono.push(pair<int,int>(i,arr[i]));
    }
    stack<pair<int,int>> mono2;
    int right[n];
    right[n-1]=n-1;
    mono2.push(pair<int,int>(n-1,arr[n-1]));
    for(int i=n-2;i>=0;i--){
        while(!mono2.empty() && mono2.top().second>=arr[i]){
            mono2.pop();
        }
        if(mono2.empty()){
            right[i]=n-1;
        }else{
            right[i]=mono2.top().first-1;
        }
        mono2.push(pair<int,int>(i,arr[i]));
    }
    int ans=0;
    //cout<<"\n";
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]*(right[i]-left[i]+1));
        //cout<<left[i]<<","<<right[i]<<" ";
    }
    cout<<ans;
}






