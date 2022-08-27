#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
#include <unistd.h>
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}

struct query{
	int l;
	int r;
	int t;
	int a;
};
const int MOD = 1000000007;
int n;
vector<int> arr;
vector<int> d;
int cnt[40005];
int l0,r0;
int ans;

void add(int v){
	ans+=(1LL*d[v]*(2*cnt[v]+1))%MOD;
	ans%=MOD;
	cnt[v]++;
}

void remove(int v){
	ans-=(1LL*d[v]*(2*cnt[v]-1))%MOD;
	ans%=MOD;
	if(ans<0) ans+=MOD;
	cnt[v]--;
}

void go(int l,int r){
	while(r0<r) add(arr[++r0]);
	while(l0>l) add(arr[--l0]);
	while(r0>r) remove(arr[r0--]);
	while(l0<l) remove(arr[l0++]);
}


int main(){
	int Q;
	n=R();Q=R();
	arr.resize(n);
	for(int i=0;i<n;i++) arr[i]=R();
	d = arr;
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int i=0;i<n;i++){
		arr[i] = lower_bound(d.begin(),d.end(),arr[i])-d.begin();
	}
	ans = d[arr[0]];
	cnt[arr[0]]=1;
	query qarr[Q];
	for(int i=0;i<Q;i++) {
		qarr[i].l=R();qarr[i].r=R();
		qarr[i].t = i;
		qarr[i].r--;
	}
	int B = (n/sqrt(Q))+1;
	sort(qarr,qarr+Q,[&](const query &a,const query &b){return ((a.l/B)==(b.l/B))?(a.r<b.r):(a.l<b.l);});
	for(int i=0;i<Q;i++){
		go(qarr[i].l,qarr[i].r);
		qarr[i].a = ans;
	}
	sort(qarr,qarr+Q,[](const query &a,const query &b){return a.t<b.t;});
	for(int i=0;i<Q;i++){
		printf("%d\n",qarr[i].a);
	}




	return 0;
}
