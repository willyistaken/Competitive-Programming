#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MOD = 1e9+7;
const int p = 31;
int n,q;
string s;
struct bit{
	vector<int> arr;
	void init(){
		arr.resize(n+1,0);	
	}

	void add(int ind,int v){
		v%=MOD;
		while(ind<=n){
			arr[ind]=(arr[ind]+v)%MOD;
			ind+=(ind & -ind);
		}
	}

	int query(int r){
		ll ans=0;
		while(r){
			ans = (ans+arr[r])%MOD;
			r -= (r & -r);
		}
		return (int)ans;
	}
	void change(int i,int v){
		int vi = (query(i)-query(i-1))%MOD;
		if(vi<0) vi+=MOD;
		add(i,-vi);
		add(i,v);
	}
};


int inv(int a){
	int p = MOD-2;
	ll r=1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	cin>>s;
	bit forw;
	bit bakw;
	forw.init();bakw.init();
	int poa[n+1]={0};
	int po = 1;	
	poa[0]=po;
	for(int i=n-1;i>=0;i--){
		forw.add(i+1,(1LL*(s[i]-'a')*po)%MOD);
		bakw.add(n-i,(1LL*(s[n-i-1]-'a')*po)%MOD);
		po = (1LL*po*p)%MOD;
		poa[n-i] = po;
	}
	while(q--){
		int type;cin>>type;
		if(type==1){
			int l,r;cin>>l>>r;
			int length = (r-l+1);
			if((length)%3) cout<<0<<"\n";
			else{
				int chunk = length/3;
				int first = (forw.query(l+chunk-1)-forw.query(l-1))%MOD;
				if(first<0) first+=MOD;
				first = (1LL*first*inv(poa[n-l-chunk+1]))%MOD;
				int second = (bakw.query(l+(2*chunk)-1)-bakw.query(l+chunk-1))%MOD;
				if(second<0) second+=MOD;
				second = (1LL*second*inv(poa[l+chunk-1]))%MOD;
				int third = (forw.query(r)-forw.query(l+(2*chunk)-1))%MOD;
				if(third<0) third+=MOD;
				third = (1LL*third*inv(poa[n-r]))%MOD;
				/*cout<<l<<" "<<l+chunk-1<<":"<<first<<"\n";	
				cout<<l+chunk<<" "<<l+(2*chunk)-1<<":"<<second<<"\n";	
				cout<<l+(2*chunk)<<" "<<r<<":"<<third<<"\n";*/
				cout<<(first==second && second==third)<<"\n";
			}
		}else{
			int i,j;cin>>i>>j;	
			forw.change(i,(1LL*(s[j-1]-'a')*poa[n-i])%MOD);
			forw.change(j,(1LL*(s[i-1]-'a')*poa[n-j])%MOD);
			bakw.change(i,(1LL*(s[j-1]-'a')*poa[i-1])%MOD);
			bakw.change(j,(1LL*(s[i-1]-'a')*poa[j-1])%MOD);
			swap(s[i-1],s[j-1]);
		}
	}

	return 0;
}
