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



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int h,w;cin>>h>>w;
	vector<pair<int,int> > ah;
	vector<pair<int,int> > bh;
	for(int i=1;i<=h;i++){
		int a;cin>>a;
		while(ah.size()>=2){
			int g = ah.size();
			if(1LL*(ah[g-1].first-ah[g-2].first)*(a-ah[g-1].second)<=1LL*(i-ah[g-1].first)*(ah[g-1].second-ah[g-2].second)) ah.pop_back();
			else break;
		}
		ah.push_back({i,a})	;
	}
	for(int i=1;i<=w;i++){
		int a;cin>>a;
		while(bh.size()>=2){
			int g = bh.size();
			if(1LL*(bh[g-1].first-bh[g-2].first)*(a-bh[g-1].second)<=1LL*(i-bh[g-1].first)*(bh[g-1].second-bh[g-2].second)) bh.pop_back();
			else break;
		}
		bh.push_back({i,a})	;
	}
	
	int x=0;int y=0;
	ll ans = 0;
	while(ah[x].first!=h && bh[y].first!=w){
		if(1LL*(ah[x+1].second-ah[x].second)*(bh[y+1].first-bh[y].first)<1LL*(bh[y+1].second-bh[y].second)*(ah[x+1].first-ah[x].first)){ans+=(1LL*bh[y].second*(ah[x+1].first-ah[x].first));x++;}
		else{ans+=(1LL*ah[x].second*(bh[y+1].first-bh[y].first));y++;}
	}
	if(ah[x].first!=h){
		ans+=1LL*bh[y].second*(h-ah[x].first);
	}
	if(bh[y].first!=w){
		ans+=1LL*ah[x].second*(w-bh[y].first);
	}
	cout<<ans<<"\n";
	return 0;
}
