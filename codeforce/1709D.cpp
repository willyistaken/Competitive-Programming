#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct segtree{
	vector<int> arr;
	void init(){
		arr.resize(2*m);
		for(int i=0;i<m;i++) cin>>arr[i+m];
		for(int i=m-1;i>=1;i--) arr[i] = max(arr[2*i],arr[2*i+1]);
	}
	int query(int l,int r){
		l+=m;r+=m;
		int re = 0;
		while(l<r){
			if(l%2) re = max(re,arr[l++]);	
			if(r%2) re = max(re,arr[--r]);	
			l>>=1;r>>=1;
		}
		return re;
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	segtree myseg;
	myseg.init();
	int q;cin>>q;
	while(q--){
		int xs,ys,xf,yf;cin>>xs>>ys>>xf>>yf;
		int k;cin>>k;
		if((abs(xf-xs))%k || (abs(yf-ys))%k){
			cout<<"NO\n";
			continue;
		}else{
				int minh = min(xf,xs);
				if(ys>yf) swap(ys,yf);
				ys--;
				int rangemax = myseg.query(ys,yf);
				int canreach = n-(n%k)+(minh%k);
				if(canreach>n) canreach-=k;
				if(canreach>rangemax){
					cout<<"YES\n";	
				}else{
					cout<<"NO\n";
				}
			}
		}

	return 0;
}
