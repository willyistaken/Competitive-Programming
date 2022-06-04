#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[26]={0};
        for(int i=0;i<2*n+1;i++){
             string s;cin>>s;
             for(auto i : s ){
                 arr[i-'a']+=1;
             }
        }
        for(int i=0;i<26;i++){
            if(arr[i]%2){
                cout<<(char)('a'+i)<<endl;
                break;
            }
        }



    }







    return 0;
}