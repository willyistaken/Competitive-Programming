#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD  =1e9+7;
const int p  =31;
struct BIT{
	vector<int> arr;
	int _n;
	void init(int s){
		arr.resize(s+1,0);
		_n = s;
	}
	void modify(int ind,int v){
		while(ind<=_n){
			arr[ind]+=v;
			arr[ind]%=MOD;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ans%=MOD;
			ind-=(ind & -ind);
		}
		if(ans<0) ans+=MOD;
		return ans;
	}
	void m(int ind,int v){
		int prev = (query(ind)-query(ind-1))%MOD;
		if(prev<0) prev+=MOD;
		modify(ind,-prev);		
		modify(ind,v);
	}
};
int n,q;
int rev(int i){
	return n+1-i;
}
int po[200005];

int inv(int v){
	int k = MOD-2;
	ll r = 1;
	while(k){
		if(k&1) r = (r*v)%MOD;
		v = (1LL*v*v)%MOD;
		k>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;			
	string s;cin>>s;
	BIT fbit,bbit;	
	fbit.init(n);
	bbit.init(n);
	po[0]=1;
	for(int i=1;i<=n+3;i++){
		po[i] = (1LL*po[i-1]*p)%MOD;
	}
	for(int i=1;i<=n;i++){
		fbit.m(i,(1LL*po[i]*(s[i-1]-'a'))%MOD);
		bbit.m(rev(i),(1LL*po[rev(i)]*(s[i-1]-'a'))%MOD);
	}
	while(q--){
		int t;cin>>t;
		if(t==2){
			int a,b;cin>>a>>b;	
			int fo = fbit.query(b)-fbit.query(a-1);
			int bo = bbit.query(rev(a))-bbit.query(rev(b)-1);
			if(fo<0)fo+=MOD;
			if(bo<0)bo+=MOD;
			//div
			fo = (1LL*fo*inv(po[a]))%MOD;			
			bo = (1LL*bo*inv(po[rev(b)]))%MOD;


			if(fo==bo) cout<<"YES\n";
			else cout<<"NO\n";
		}else{
			int a;cin>>a;
			char x;cin>>x;
			fbit.m(a,(1LL*po[a]*(x-'a'))%MOD);
			bbit.m(rev(a),(1LL*po[rev(a)]*(x-'a'))%MOD);
		}
	}

	return 0;
}
