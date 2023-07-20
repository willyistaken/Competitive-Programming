#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int long long

vector<int> arr;
int n,m,q;

void take(int l,int r,int v){
	l+=n;
	r+=n;
	while(r>l){
		if(l&1){arr[l] = min(arr[l],v);l++;}
		if(r&1){--r;arr[r] = min(arr[r],v);}
		l>>=1;
		r>>=1;
	}
}
struct bit{
	vector<int> arr;			
	void init(int s){
		arr.resize(s+1,0);
	}
	void add(int ind,int v){
		ind++;
		while(ind<arr.size()){
			arr[ind]+=v;
			ind+=(ind&-ind);
		}
	}
	int query(int ind){
		ind++;
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind&-ind);
		}
		return ans;
	}
};


signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;	
	arr.resize(2*n);
	for(int i=0;i<2*n;i++) arr[i] = 1e9;
	string s;cin>>s;	
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		l--;
		take(l,r,i);
	}
	int group[n];
	for(int i=0;i<n;i++){
		int loc = i+n;
		int k = 1e9;
		while(loc){
			k = min(k,arr[loc]);
			loc>>=1;
		}
		group[i]= k;
	}
	int order[n];
	for(int i=0;i<n;i++) order[i]=i;
	sort(order,order+n,[&](const int &a,const int &b){return (group[a]==group[b])?(a<b):(group[a]<group[b]);});
	int allsize= n-1;
	while(allsize>=0 && group[order[allsize]]>1e7){
		allsize--;
	}
	int mp[n];
	for(int i=0;i<n;i++) mp[order[i]]=i;
	bit b;
	b.init(n);
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			b.add(mp[i],1);
		}
	}
	for(int i=0;i<q;i++){
		int g;cin>>g;	
		g--;
		if(s[g]=='1'){
			b.add(mp[g],-1);
			s[g]='0';
		}else{
			b.add(mp[g],1);
			s[g]='1';
		}
		int cnt = b.query(n-1);
		if(cnt<allsize+1){
			cout<<cnt-b.query(cnt-1)<<"\n";
		}else{
			cout<<allsize+1-b.query(allsize)<<"\n";
		}
	}
	return 0;
}
