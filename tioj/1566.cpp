#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int n,m; unsigned int k;
void modify(int ind,unsigned v,vector<pair<unsigned int,unsigned int> > &segtree){
    ind+=n;
    segtree[ind]={v,v};
    while(ind>0){
        ind>>=1;
        segtree[ind].first = max(segtree[ind*2].first,segtree[2*ind+1].first);
        segtree[ind].second = min(segtree[ind*2].second,segtree[2*ind+1].second);
    }
}
pair<unsigned int,unsigned int> query(int rl,int rr,vector<pair<unsigned,unsigned> > &segtree){
    unsigned maxn=0;
    unsigned minn=INT_MAX;
    int l=rl+n;
    int r=rr+n;
    if(r-l==1) return segtree[l];
    while(l<r){
        if(l%2){
            maxn=max(maxn,segtree[l].first);
            minn=min(minn,segtree[l].second);
            l++;
        }
        if(r%2){
            r--;
            maxn=max(maxn,segtree[r].first);
            minn=min(minn,segtree[r].second);
        }
        l>>=1;r>>=1;
    }
    return {maxn,minn};
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    vector<pair<unsigned int,unsigned int> > segtree(2*n,{0,0});
    for(int i=0;i<n;i++){
        unsigned int temp;cin>>temp;
        modify(i,temp,segtree);
    }
    int ans=0;
    vector<pair<unsigned int,unsigned int> > ansq;
    for(int rb=2,lb=rb-m;lb<=n-2;lb++,rb++){
        pair<unsigned int,unsigned int> temp=query(max(lb,0),min(rb,n),segtree);
        //cout<<temp.first<<temp.second<<endl;
        if(temp.first-temp.second==k && min(rb,n)-max(lb,0)-1>=1){
            ans++;
            ansq.push_back({max(lb,0)+1,min(rb,n)});
        } 
    }
    cout<<ans<<endl;
    sort(ansq.begin(),ansq.end());
    for(auto i : ansq){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}

//note to self: this is another stupid way tioj uses to trick you, int only has range(-2^31,"2^31-1"), the question says that 1<=k<=2^31 which is one more than (int limit). which can be fixed by setting int to unsigned, but it still take me a long time to debug :(
//tl;dr: int<=2^31-1, not 2^31 be careful;