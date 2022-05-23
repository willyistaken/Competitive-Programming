#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int np2(int n){
	n--;
	n|=n>>1;
	n|=n>>2;
	n|=n>>4;
	n|=n>>8;
	n|=n>>16;
	n++;
	return n;
}
void modify(int ind,ll value,vector<pair<ll,ll> > &segtree){
	ind+=np2(n);
	segtree[ind]=make_pair(value,value);
	while(ind>1){
			ind/=2;
			segtree[ind].first=max(segtree[2*ind].first,segtree[(2*ind)+1].first);
			segtree[ind].second=min(segtree[2*ind].second,segtree[(2*ind)+1].second);
			
	}

}

pair<ll,ll> query(int rl,int rr,vector<pair<ll,ll> > &segtree){
	ll maxn=LONG_LONG_MIN;ll minn=LONG_LONG_MAX;
	rl+=np2(n);rr+=np2(n);
	int l=rl;int r=rr;
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
	cin>>n;
	int q;cin>>q;
	vector<pair<ll,ll> > segtree(2*np2(n),make_pair(LONG_LONG_MIN,LONG_LONG_MAX));
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		modify(i,temp,segtree);
	}
	while(q--){
		int l,r;cin>>l>>r;
		if(n==0 || r==l){
			cout<<0<<endl;	
		}else{
		pair<ll,ll> temp=query(l-1,r,segtree);
		cout<<temp.first-temp.second<<endl;
		}

	}
	return 0;
}

//this code for some reason doesn't work:(
