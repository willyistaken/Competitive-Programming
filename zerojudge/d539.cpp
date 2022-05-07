#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
void modify(int ind,int value,vector<pair<int,int> > &segtree){
    ind+=n;
    segtree[ind]=make_pair(value,value);
    while(ind>1){
            ind/=2;
            segtree[ind].first=max(segtree[2*ind].first,segtree[(2*ind)+1].first);
            segtree[ind].second=min(segtree[2*ind].second,segtree[(2*ind)+1].second);

    }

}

pair<int,int> query(int l,int r,vector<pair<int,int> > &segtree){
    int maxn=INT_MIN;int minn=INT_MAX;
    l+=n;r+=n;
    if(r-l==1) return segtree[l];
    while(l<r){
        if(l%2){
            maxn = max(maxn,segtree[l].first);
            minn = min(minn,segtree[l].second);
            l++;
        }
        if(r%2){
            --r;
            maxn=max(maxn,segtree[r].first);
            minn=min(minn,segtree[r].second);

        }
        l/=2;r/=2;
    }
    return make_pair(maxn,minn);

}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    vector<pair<int,int> > segtree(2*n,make_pair(INT_MIN,INT_MAX));
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        modify(i,temp,segtree);
    }
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
		if(l>r) swap(l,r);
        if(n==0 ){
            cout<<0<<endl;
        }else{
        pair<int,int> temp=query(l-1,r,segtree);
        cout<<temp.first<<endl;
        }

    }
    return 0;
}
