#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 2e5+5;
ll arr[N];
int h[N];
int l[N];
int r[N];
struct BIT{
	int s;
	void init(int _s){
		s = _s;
	}
	ll get(int ind){
		ll ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}
	void add(int ind ,ll v){
		while(ind<=s){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	void modify(int ind,ll v){
		ll a = get(ind)-get(ind-1);
		add(ind,-a);
		add(ind,v);
	}
} bit;


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	bit.init(n);
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		bit.modify(i,a);
	}
	stack<int> stk;
	for(int i=1;i<=n;i++){
		while(stk.size()){
			if(h[stk.top()]<=h[i]) stk.pop();
			else break;
		}
		if(stk.size()) l[i] = stk.top()+1;
		else l[i]=1;
		stk.push(i);
	}
	while(stk.size()) stk.pop();
	for(int i=n;i>=1;i--){
		while(stk.size()){
			if(h[stk.top()]<=h[i]) stk.pop();
			else break;
		}
		if(stk.size()) r[i] = stk.top()-1;
		else r[i]=n;
		stk.push(i);
	}
	while(q--){
		int t;cin>>t;
		if(t==1){
			int ind,v;cin>>ind>>v;
			bit.modify(ind,v);
		}else{
			int ind;cin>>ind;
			cout<<bit.get(r[ind])-bit.get(l[ind]-1)<<"\n";
		}
	}
	return 0;
}
