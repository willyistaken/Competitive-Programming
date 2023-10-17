#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> Y;
vector<int> Z;
vector<int> X;

vector<int>	ordery;
vector<int> rg;
struct seg{
	vector<int> arr;
	int n;
	void init(int S){
		n = S;
		arr.resize(2*S);
	}
	void chmax(int l,int r,int v){
		l+=n;r+=n;	
		while(l<r){
			if(l&1){arr[l] = max(arr[l],v);l++;}
			if(r&1){r--;arr[r] = max(arr[r],v);}
			l>>=1;r>>=1;
		}
	}
	int get(int ind){
		ind+=n;
		int ans = 0;
		while(ind){
			ans = max(ans,arr[ind]);
			ind>>=1;
		}
		return ans;
	}
} sgt;
int P = -1;
map<int,int> posP;
int n;
void add(int ind){
	int k = ordery[ind];
	sgt.chmax(rg[k],n,Z[ind]);
	if(posP.size()==0){
		if(k>P){
			if(sgt.get(k)>Z[ind]) P=k;
			else posP[Y[ind]]=ind;
		}
		return;
	}
	auto it = posP.upper_bound(Y[ind]);
	if(it==posP.end() || Z[it->second]>=Z[ind]){
		int g = it->second;
		--it;
		while(posP.begin()->second!=g){
			if(Z[it->second]>=Z[ind]) posP.erase(it--);
			else break;
		}
		posP[Y[ind]]=ind;
		if(sgt.get(k)>Z[ind]){
			P = k;
			while(posP.size() && ordery[posP.begin()->second]<=P){
				posP.erase(posP.begin());
			}
		}
	}else{
		int g = it->second;
		while(posP.size() && posP.begin()->second!=g){posP.erase(posP.begin());}
		while(posP.size() && sgt.get(ordery[posP.begin()->second])>Z[posP.begin()->second]){
			P=ordery[posP.begin()->second];
			posP.erase(posP.begin());
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	
	X.resize(n);
	Y.resize(n);
	Z.resize(n);
	vector<int> w(n);
	sgt.init(n);
	for(int i=0;i<n;i++) cin>>X[i]>>Y[i]>>Z[i];
	vector<int> order(n);
	vector<int> oty(n);
	ordery.resize(n);
	for(int i=0;i<n;i++) order[i]=i;
	sort(order.begin(),order.end(),[&](const int a,const int b){return (Y[a]==Y[b])?(Z[a]>Z[b]):(Y[a]<Y[b]);});
	for(int i=0;i<n;i++){
		oty[i]=order[i];
		ordery[order[i]]=i;
	}
	rg.resize(n,0);
	int head = 0;
	for(int i=0;i<n;i++){
		while(head<n && Y[order[head]]<=Y[order[i]]) head++;
		rg[i]=head;
	}
	sort(order.begin(),order.end(),[&](const int a,const int b){return (X[a]==X[b])?(Y[a]>Y[b]):(X[a]<X[b]);});
	int prevx = -1;
	queue<int> tobeadd;	
	int ans = -1;
	for(auto i : order){
		if(X[i]!=prevx){
			while(tobeadd.size()){
				add(tobeadd.front());
				tobeadd.pop();
			}
		}
		if(P>=0 && Y[oty[P]]>Y[i] && sgt.get(P)>Z[i]){
			ans = max(ans,X[i]+Y[oty[P]]+sgt.get(P));	
		}
		prevx = X[i];
		tobeadd.push(i);
	}
	cout<<ans<<"\n";
	return 0;
}
