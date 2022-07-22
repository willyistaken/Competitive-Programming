#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN =1e6+5;
vector<int> prime;
int x[MAXN];
pair<int,int> segtree[2*MAXN];
void init(){
	segtree[MAXN] = {0,0};
	segtree[MAXN+1] = {0,1};
	segtree[MAXN+2] = {1,2};
	x[1]=0;
	prime.push_back(2);
	x[2]=2;
	for(int i=2;i<MAXN;i++){
		if(!x[i]){
			x[i]=i;
			segtree[MAXN+i] = {1,i};
			prime.push_back(i);
		}
		for(int k=0;k<prime.size();k++){
			if(prime[k]<=x[i] && prime[k]*i<MAXN){
				x[prime[k]*i] = prime[k];
				if(x[i]==prime[k]){
					segtree[MAXN+(prime[k]*i)] = {segtree[MAXN+i].first,prime[k]*i};	
				}else{
					segtree[MAXN+(prime[k]*i)] = {segtree[MAXN+i].first+1,prime[k]*i};	
				}
			}else{
				break;
			}
		}
	}
}
pair<int,int> comp(pair<int,int> a,pair<int,int> b){
	if(a.first!=b.first) return max(a,b);
	return min(a,b);
}
pair<int,int> query(int l,int r){
	r++;
	l+=MAXN;r+=MAXN;
	pair<int,int> result={0,0};
	while(l<r){
		if(l%2)	 result = comp(result,segtree[l++]);
		if(r%2)	 result = comp(result,segtree[--r]);
		l>>=1;r>>=1;
	}
	return result;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	for(int i=MAXN-1;i>=1;i--){
		segtree[i] = comp(segtree[2*i],segtree[2*i+1]);
	}
	int l,r;
	while(cin>>l>>r){
		pair<int,int> temp = query(l,r);
		cout<<temp.second<<" "<<temp.first<<"\n";	
	}
	return 0;
}
