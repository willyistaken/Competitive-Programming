#include <bits/stdc++.h>
using namespace std;
int k;
int arr[15];

void dfs(int n, vector<int> path, int size) {
    if (size >= 6) {
        cout<<path[0];
        for(int i=1;i<6;i++){
            cout<<" "<<path[i];
        }
        cout<<endl;
    } else{
       for(int i=n+1;i<k;i++){
           path[size]=arr[i];
           vector<int> temp = path;
           dfs(i,temp,size+1);
       }
    }
}

int main() {
    int t;cin>>t;
    while(t--){
       cin>>k;

    for(int i=0;i<k;i++){
        cin>>arr[i];
    } 
    vector<int> h(6,0);
    dfs(-1,h,0);  
    }
   
}