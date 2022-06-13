#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int N[100010];
ll sum[100010];
ll lmax(int ql,int qr);
ll rmax(int ql,int qr);
ll segsum(int ql,int qr);
map<pair<int,int>,ll> qmap;
map<pair<int,int>,ll> lmaxmap;
map<pair<int,int>,ll> rmaxmap;
ll query(int ql,int qr){
	if(qr-ql==1) return N[ql];
	if(qmap.count(make_pair(ql,qr))) return qmap[make_pair(ql,qr)];
	ll maxn = max(query(ql,(ql+qr)/2),query((ql+qr)/2,qr));
	maxn = max(maxn,lmax((ql+qr)/2,qr)+rmax(ql,(ql+qr)/2));
	qmap.insert({{ql,qr},maxn});
	return maxn;
}

ll lmax(int ql,int qr){
	if(qr-ql==1) return N[ql];	
	if(lmaxmap.count(make_pair(ql,qr))) return lmaxmap[make_pair(ql,qr)];
	ll k = max(lmax(ql,(ql+qr)/2),segsum(ql,(ql+qr)/2)+lmax((ql+qr)/2,qr))	;	
	lmaxmap.insert({{ql,qr},k});
	return k;
}
ll rmax(int ql,int qr){
	if(qr-ql==1) return N[ql];	
	if(rmaxmap.count(make_pair(ql,qr))) return rmaxmap[make_pair(ql,qr)];
	ll k = max(rmax((ql+qr)/2,qr),segsum((ql+qr)/2,qr)+rmax(ql,(ql+qr)/2))	;	
	rmaxmap.insert({{ql,qr},k});
	return k;
}
ll segsum(int ql,int qr){
	return sum[qr]-sum[ql];
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int q;cin>>q;
	for(int i=0;i<n;i++){
		cin>>N[i];
		sum[i+1]=sum[i]+N[i];
	}
	for(;q;q--){
		int ql,qr;cin>>ql>>qr;
		ql-=1;
		cout<<max(0LL,query(ql,qr))<<endl;
	}
	return 0;
}
