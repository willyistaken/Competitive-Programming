#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct doll{
    int w=0;
    int h=0;
};
int rn ;
int const MOD = 1e9+9;
pair<int,int> query(int x,pair<int,int>* fenwick){
    int sum=0;
    int number=0;
    while(x){
        sum+=fenwick[x].second;
        sum = (sum>MOD) ? sum-MOD:sum;
        number+=fenwick[x].first;
        x-=(x&-x);
    }
    return {number,sum};
}

void add(int x,int val,pair<int,int>* fenwick){
    while(x<=rn){
        fenwick[x].second+=val;
        fenwick[x].second = (fenwick[x].second>MOD) ? fenwick[x].second-MOD:fenwick[x].second;
        fenwick[x].first+=1;
        x+=(x&-x); 
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    doll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i].w>>arr[i].h;
    unordered_map<int,int> mp;
    sort(arr,arr+n,[](const doll &a,const doll &b){return a.h<b.h;});
    for(int i=0;i<n;i++){
        if(!mp.count(arr[i].h)){
            mp.insert({arr[i].h,mp.size()});
        }
    }
    rn = mp.size();
    pair<int,int> fenwick[rn+1]={{0,0}};
    sort(arr,arr+n,[](const doll &a,const doll &b){return (a.w<b.w || (a.w==b.w&&a.h<b.h));});
    ll ans=0;
    for(int i=0;i<n;i++){
        pair<int,int> temp = query(mp[arr[i].h]+1,fenwick);
        ans+= (1LL*temp.first*((1LL*arr[i].h*arr[i].w)%MOD))%MOD;
        ans = (ans>MOD) ? ans-MOD : ans;
        ans-=temp.second;
        if(ans<0) ans+=MOD;
        add(mp[arr[i].h]+1,(1LL*arr[i].w*arr[i].h)%MOD,fenwick);
    }

    cout<<ans<<endl; 






    return 0;
}