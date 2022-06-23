#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
struct bit{
    vector<ll> arr;
    void add(int ind,ll v){
        while(ind<=n){
            arr[ind]+=v;
            ind+=(ind & -ind);
        }
    }

    ll query(int ind){
        ll sum=0;
        while(ind){
            sum+=arr[ind];
            ind-=(ind & -ind);
        }
        return sum;
    }
} BIT;

struct seg{
    vector<ll> arr;
    void built(int r){
        if(r>n) return ;
        built(2*r);
        built(2*r+1);
        arr[r] = __gcd(arr[2*r],arr[2*r+1]);
    }
    void add(int ind,ll v){
        if(ind>=n) return ; 
        ind+=n;
        arr[ind]+=v;
        ind>>=1;
        while(ind){
            arr[ind] = __gcd(arr[2*ind],arr[2*ind+1]);
            ind>>=1;
        }
    }
  
    ll query(int l,int r){
        l+=n;r+=n;
        ll result=0;
        while(l<r){
            if(l%2) result = __gcd(result,arr[l++]);
            if(r%2) result = __gcd(result,arr[--r]);
            l>>=1;r>>=1;
        }
        return abs(result);
    }
} SEG;


void init(ll n){
    BIT.arr.resize(n+1);
    fill(BIT.arr.begin(),BIT.arr.end(),0);
    SEG.arr.resize(2*n);
    fill(SEG.arr.begin(),SEG.arr.end(),0);
    ll now=0;
    for(ll i=0;i<n;i++){
        ll k;cin>>k;
        BIT.add(i+1,k-now);
        SEG.arr[i+n]=k-now;
        now=k;
    }
    SEG.built(1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin>>n>>q;
    init(n);  
    while(q--){
        int type;cin>>type;
        if(type==1){
            ll l,r,v;cin>>l>>r>>v;
            BIT.add(l,v);
            BIT.add(r+1,-v);
            SEG.add(l-1,v);
            SEG.add(r,-v);
        }else{
            ll l,r;cin>>l>>r;
            cout<<__gcd(BIT.query(r),SEG.query(l,r))<<endl;
        }
    }






    return 0;
}

// good

