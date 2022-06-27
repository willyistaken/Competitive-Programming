#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> segtree;


void built(int r){
	if(r>=n) return;
	built(2*r);
	built(2*r+1);
	segtree[r] = min(segtree[2*r],segtree[2*r+1]);
}

int query(int l,int r){
	l+=n;r+=n;
	int minn=INT_MAX;
	while(l<r){
		if(l%2) minn = min(minn,segtree[l++]);
		if(r%2) minn = min(minn,segtree[--r]);
		l>>=1;r>>=1;
	}
	return minn;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	segtree.resize(2*n);
	for(int i=0;i<n;i++){
		int a;cin>>a;
		a++;
		segtree[i+n]=a;
	}
	built(1);
	for(int i=0;i<n;i++){
		int l,r;cin>>l>>r;
		l-=1;
		cout<<query(l,r)<<"\n";
	}
	return 0;
}




