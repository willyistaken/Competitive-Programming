#include<bits/stdc++.h>
#include "lib1926.h"
using namespace std;
typedef long long ll;

pair<ll,ll> mn(pair<ll,ll> a,pair<ll,ll> b){
	if(Oshietekudasai(a.first,a.second,b.first,b.second)) return a;
	else return b;
}
bool smaller(pair<ll,ll> a,pair<ll,ll> b){
	return(Oshietekudasai(a.first,a.second,b.first,b.second)); 
}

long long n,m;
void find(ll l,ll r){
		if(l>r) return ;
		ll mid = l + ((r-l)/2);
		pair<ll,ll> low = {0,mid};
		for(int i=1;i<n;i++){
			low = mn(low,{i,mid});	
		}
		if(mid==m-1 || mid==0){
			if(mid==m-1){
				if(smaller(low,{low.first,low.second-1})) Report(low.first,low.second);
				else find(mid,r);	
			}else{
				if(smaller(low,{low.first,low.second+1})) Report(low.first,low.second);
				else find(l,mid);
			}
		}else{
			if(smaller(low,{low.first,low.second+1}) && smaller(low,{low.first,low.second-1})) Report(low.first,low.second);
			else{
				if(smaller({low.first,low.second+1},{low.first,low.second-1})){
					find(mid,r);
				}else{
					find(l,mid);
				}
			}
		}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	Init(&n,&m);
	find(0,m);
	return 0;
}
