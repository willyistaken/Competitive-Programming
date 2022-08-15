#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query{
	int l;
	int r;
	int t;
	int ans;
};

const int MAXN = 1e5+5;

int cnt[MAXN];
int cntcnt[MAXN];

vector<int> arr;
int n,Q;

int l0,r0;
int ans;

void add(int x){
	cntcnt[cnt[x]]--;
	cnt[x]++;
	cntcnt[cnt[x]]++;
	if(cntcnt[cnt[x]]==1) ans = max(ans,cnt[x]);
}

void sub(int x){
	if(cntcnt[cnt[x]]==1 && ans==cnt[x]) ans = cnt[x]-1;
	cntcnt[cnt[x]]--;
	cnt[x]--;
	cntcnt[cnt[x]]++;
}

void go(int l,int r){
	while(r0<r) {add(arr[++r0]);}
	while(l0>l) {add(arr[--l0]);}
	while(r0>r) {sub(arr[r0--]);}
	while(l0<l) {sub(arr[l0++]);}
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>Q;
	arr.resize(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	query a[Q];
	for(int i=0;i<Q;i++){
		cin>>a[i].l>>a[i].r;
		a[i].t=i;
	}
	int B = sqrt(n);
	sort(a,a+Q,[&](const query &a,const query &b){return (((a.l/B)==(b.l/B))?(a.r<b.r):(a.l<b.l));});
	for(int i=0;i<Q;i++){
		go(a[i].l,a[i].r);
//		cout<<a[i].l<<" "<<a[i].r<<":";
//		for(int i=1;i<10;i++) cout<<cnt[i]<<" ";
//		cout<<"\n";
		a[i].ans = ans;
	}
	sort(a,a+Q,[](const query &a,const query &b){return a.t<b.t;});	
	for(int i=0;i<Q;i++) cout<<a[i].ans<<"\n";

	return 0;
}