//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e6+5;
int lowprime[MAXN];
void init(){
    for(int i=2;i<MAXN;i++){
        if(!lowprime[i]){
            lowprime[i]=i;
            for(int j=2;j*i<MAXN;j++){
                if(!lowprime[i*j]) lowprime[i*j]=i;
            }
        }
    }
}

bool hasenough(int k,ll p,int h){
    int ans=0;
    ll a = p;
    while(p<=k){
        ans+=k/p;
        p*=a;
    }
    return ans>=h;
}

bool works(int k,vector<pair<int,int> > &primepair){
    for(auto pr : primepair){
        if(!hasenough(k,pr.first,pr.second)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int q;cin>>q;
    while(q--){
        int n;cin>>n;
        if(n<=1){
            cout<<0<<"\n";
            continue;
        }
        vector<pair<int,int> > primepair;
        int num = n;
        while(num>1){
            int p = lowprime[num];
            int time=0;
            while(num%p==0){
                time++;
                num/=p;
            }
            primepair.push_back({p,time});
        }
        int l=0;int r=n;
        while(r-l>1){
            int mid = (l+r)/2;
            if(works(mid,primepair)) r=mid;
            else l = mid;
        }
        cout<<r<<"\n";
    }
    return 0;
}