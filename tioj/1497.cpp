#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    getline(cin,s);
    if((s.find_first_not_of(s[0]) == string::npos)){
        for(int i=s.size()-1;i>=0;i--){
            cout<<i<<endl;
        }
        return 0;
    }
    int arr[s.size()];
    for(int i=0;i<s.size();i++) arr[i]=i;
    sort(arr,arr+s.size(),[&](int &a,int&b){
        int maxn = max(a,b);
        for(int i=0;i<s.size()-maxn;i++){
            if(s[a+i]!=s[b+i]){
                return s[a+i]<s[b+i];
            }
        }
        return a>b;
    });
    for(int i=0;i<s.size();i++) cout<<arr[i]<<endl;





    return 0;
}