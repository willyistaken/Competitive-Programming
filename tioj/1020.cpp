#include <bits/stdc++.h>
using namespace std;
int n;
int ans=0;
vector<int> biggest;
void dfs(vector<int> arr,int i){
    vector<int> og =arr;
    for(int k=0;k<=i-2;k++){
        if(arr[k]+arr[k+1]<=i && i%(arr[k]+arr[k+1])==0){
            if(i==n){
                ans++;
                arr.insert(arr.begin()+k+1,i);
                for(int m=0;m<n+1;m++){
                    if(arr[m]>biggest[m]){
                        for(int h=0;h<n+1;h++){
                            biggest[h]=arr[h];
                        }
                        break;
                    }
                    if(arr[m]<biggest[m]) break;
                }
                arr=og;
            }else{
              arr.insert(arr.begin()+k+1,i);
                dfs(arr,i+1); 
                arr=og;
            }
                
        }
    }
}

int main(){
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        cout<<0<<" "<<1<<endl;
        return 0;
    }
    biggest = vector<int>(n+1,0);
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    dfs(arr,2);
    cout<<ans<<endl;
    for(int i=0;i<n+1;i++){
        cout<<biggest[i]<<" \n"[i==n];
    }
    
}