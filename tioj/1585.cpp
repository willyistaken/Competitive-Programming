#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool comp(const string &a,const string &b){
    for(int i=0;i<min(a.size(),b.size());i++){
        if(a[i]!=b[i]) return ((abs(a[i]-'n')==abs(b[i]-'n'))) ? (a[i]>b[i]) : (abs(a[i]-'n')>abs(b[i]-'n'));
    }
    return a.size()<b.size();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //for(int i=0;i<26;i++) cout<<char('a'+i)<<" : "<<abs(('a'+i - 'n'))<<endl;
    int n;cin>>n;
    string arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
    return 0;
}
