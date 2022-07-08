#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 999575;
ll s[MAXN];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	s[1]=1;
	s[2]=3;
	s[3]=5;
	for(int i=4;i<MAXN;i++){
		int l = 1;int r=i;
		while(r-l>1){
			int mid = (l+r)/2;
			if(s[mid]>=i){
				r=mid;
			}else{
				l=mid;			
			}
		}
		s[i]=s[i-1]+r;
	}
	ll n;
	while(cin>>n && n){
		if(n<MAXN){
			cout<<s[n]-s[n-1]<<"\n";
			continue;
		}
		ll l = 1;ll r=MAXN;
		while(r-l>1){
			ll mid = l+((r-l)/2);
			if(s[mid]>=n){
				r=mid;
			}else{
				l=mid;
			}
		}
		cout<<r<<"\n";
	}
	return 0;
}
