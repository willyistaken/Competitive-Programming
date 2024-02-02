#pragma GCC optimize("Ofast")
#pragma GCC optimization (unroll-loops)
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



const int N = 1e6+5;

int sum[N];
int sum2[N];

bool ok(int d){
	ll left = 0;	
	for(int i=1;i<N;i++){
		if(sum[i]+sum2[i]>d){
			if(sum[i]>d) return 0;
			left-=sum2[i]+sum[i]-d;
			if(left<0) return 0;
		}else{
			left+=d-sum[i]-sum2[i];
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)	{
		int a,b;cin>>a>>b;
		sum[a]++;
		sum[b+1]--;
	}
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int w,d;cin>>w>>d;
		sum2[d-w+1]++;
		sum2[d+1]--;
	}
	for(int i=1;i<N;i++){
		sum[i]+=sum[i-1];
		sum2[i]+=sum2[i-1];
	}
	int l = 0;
	int r = n+m;
	while(r-l>1){
		int mid = (r+l)/2;
		if(ok(mid)) r = mid;
		else l = mid;
	}
	cout<<r<<"\n";
	return 0;
}
