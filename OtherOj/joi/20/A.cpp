#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

map<ll,int> s;
void add(ll num){
	s[num]++;
}
void remove(ll num){
	s[num]--;
	if(s[num]==0) s.erase(num);
}

ll getmax(){
	return s.rbegin()->first;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	ll a[n+1]={0};
	for(int i=0;i<n+1;i++){
		cin>>a[i];
	}
	ll b[n];
	for(int i=0;i<n;i++) cin>>b[i];
	sort(b,b+n);
	int order[n+1];
	for(int i=0;i<=n;i++) order[i]=i;
	sort(order,order+n+1,[&](const int x,const int y){return a[x]<a[y];});
	ll c[n+1]={0};
	for(int i=n;i>=1;i--){
		add(max(a[order[i]]-b[i-1],0LL));
	}
	c[order[0]] = getmax();
	for(int k=1;k<=n;k++){
		remove(max(a[order[k]]-b[k-1],0LL));
		add(max(a[order[k-1]]-b[k-1],0LL));
		c[order[k]]=getmax();
	}
	for(int i=0;i<=n;i++) cout<<c[i]<<" ";
	cout<<"\n";
	return 0;
}
