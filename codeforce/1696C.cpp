#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct number{
    ll N;
    int v;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<number> arrn(n);
        for(int i=0;i<n;i++){
            int many=1;
            int a;cin>>a;
            while(a%m==0){
                many*=m;
                a/=m;
            }
            arrn[i]={many,a};
        }
        vector<number> tarrn;
        for(int i=0;i<n;){
           int v=arrn[i].v;
           ll N = 0;
           while(arrn[i].v==v && i<n){
               N+=arrn[i].N;
               i++;
           }
           tarrn.push_back({N,v}); 
        }
        int k;cin>>k;
        vector<number> arrk(k);
        for(int i=0;i<k;i++){
            int many=1;
            int b;cin>>b;
            while(b%m==0){
                many*=m;
                b/=m;
            }
            arrk[i]={many,b};
        }
        vector<number> tarrk;
        for(int i=0;i<k;){
           int v=arrk[i].v;
           ll N = 0;
           while(arrk[i].v==v && i<k){
               N+=arrk[i].N;
               i++;
           }
           tarrk.push_back({N,v}); 
        }
        if(tarrk.size()!=tarrn.size()){
            cout<<"No\n";
            continue;
        }else{
            bool pass=1;
            for(int i=0;i<tarrk.size();i++){
                if(tarrk[i].v!=tarrn[i].v || tarrk[i].N != tarrn[i].N){
                    cout<<"No\n";
                    pass=0;
                    break;
                }
            }
            if(pass){
                cout<<"Yes\n";
            }
        }
    }
    







    return 0;
}