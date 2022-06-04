#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000005;
map<int,int> sum;
map<int,int> number;
int power(int k,int p){
    int n=1;
    for(int i=0;i<p;i++){
       n*=k; 
    }
    return n;
}
pair<int,int> f(int k){
    if(sum.count(k)) return {sum[k],number[k]};
    if(k==1) return {1,1};
    if(k==2) return {3,2};
    if(k==3) return {4,2};
    for(int j=2;j<=(int)sqrt(k);j++){
            if(k%j==0){
                int now=k;
                int a=1;
                while(now%j==0){
                    a+=1;
                    now/=j;
                }
                pair<int,int> temp = f(now);
                sum.insert({k,temp.first*((pow(j,a)-1)/(j-1))});
                number.insert({k,temp.second*(a)});
                return {sum[k],number[k]};
            }
        }
    sum.insert({k,k+1});
    number.insert({k,2});
    return {k+1,2};
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int k;cin>>k;
        pair<int,int> temp = f(k);
        cout<<1LL*temp.first*temp.second<<endl;
    }





    return 0;
}