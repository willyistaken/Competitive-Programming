#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,MOD;

int inv(int a){
	if(a<0) a+=MOD;
	int p = MOD-2;
	int r = 1;
	while(p){
		if(p&1)	 r = (1LL*r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>MOD;
	map<int,int> f;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n;i++){
		if(f.count(a[i]) && f[a[i]]!=b[i]){
			cout<<"impossible\n";
			return 0;
		}
		f[a[i]]=b[i];
	}
	int aa,ab,ac;
	if(f.size()==1){
		aa = 0;
		ab = 0;
		ac = b[0];
	}else if(f.size()==2){
		aa=0;
		vector<int> st;
		for(auto i : f){
			st.push_back(i.first);
		}
		int k = st[0]-st[1];
		ab = (1LL*inv(k)*(f[st[0]]-f[st[1]]))%MOD;
		if(ab<0) ab+=MOD;
		ac = f[st[0]]-(1LL*ab*st[0])%MOD;
		if(ac<0) ac+=MOD;
	}else{
		vector<int> st;	
		for(auto i : f){
			st.push_back(i.first);
			if(st.size()==3) break;
		}
		int b1b2 = (1LL*inv(st[0]-st[1])*(f[st[0]]-f[st[1]]))%MOD;
		int a1a2 = (1LL*inv(st[0]-st[1])*((1LL*st[0]*st[0])%MOD-(1LL*st[1]*st[1])%MOD))%MOD;
		int b2b3 = (1LL*inv(st[1]-st[2])*(f[st[1]]-f[st[2]]))%MOD;
		int a2a3 = (1LL*inv(st[1]-st[2])*((1LL*st[1]*st[1])%MOD-(1LL*st[2]*st[2])%MOD))%MOD;
		if(a1a2==a2a3){
			cout<<"impossible\n";
			return 0;
		}
		aa = (1LL*inv(a1a2-a2a3)*(b1b2-b2b3))%MOD;
		if(aa<0) aa+=MOD;
		ab = (b1b2-(1LL*aa*a1a2)%MOD)%MOD;
		if(ab<0) ab+=MOD;
		ac = f[st[0]]-(1LL*aa*((1LL*st[0]*st[0])%MOD))%MOD;
		ac = ac-(1LL*ab*st[0])%MOD;
		if(ac<0) ac+=MOD;
	}
	for(auto i : f){
		int x = i.first;
		int y = i.second;
		if((((1LL*aa*((1LL*x*x)%MOD))+((1LL*ab*x)%MOD))%MOD+ac)%MOD!=y){
			cout<<"impossible\n";
			return 0;
		}
	}
	cout<<aa<<" "<<ab<<" "<<ac<<"\n";
	return 0;
}
