#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct seg{
	int l;
	int r;
	int ind;
};

vector<seg> arr; 
vector<int> f[20];
int n;
int getcnt(int l,int r){
	int cur = l;	
	int cnt = 0;
	for(int p=19;p>=0;p--){
		if(f[p][cur]<=r){
			cnt+=(1<<p);
			cur = f[p][cur];
		}
	} 
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int K;cin>>n>>K;
	arr.resize(n+1);
	vector<int> d;
	for(int i=1;i<=n;i++){
		int a,b;cin>>a>>b;
		arr[i].l = a;
		arr[i].r = b;
		arr[i].ind = i;
		d.push_back(a);
		d.push_back(b);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	int D  = d.size();
	for(int i=0;i<20;i++) f[i].resize(D+1,0);
	vector<int> ord;	
	for(int i=1;i<=n;i++) ord.push_back(i);
	for(int i=1;i<=n;i++){
		arr[i].l = lower_bound(d.begin(),d.end(),arr[i].l)-d.begin()+1;
		arr[i].r = lower_bound(d.begin(),d.end(),arr[i].r)-d.begin()+1;
	}
	sort(ord.begin(),ord.end(),[&](const int &a,const int &b){return arr[a].l>arr[b].l;});
	{
	int head = 0;
	int minn = 1e9; 
	for(int i=D;i>=1;i--){
		while(head<n && arr[ord[head]].l>=i){
			 minn = min(minn,arr[ord[head]].r);
			 head++;
		}
		f[0][i] = minn;
	}
	}
	for(int p=1;p<20;p++){
		for(int i=1;i<=D;i++){
			if(f[p-1][i]>D) f[p][i]=1e9;
			else f[p][i] = f[p-1][f[p-1][i]];
		}
	}
	int allcnt = getcnt(1,D);
	map<int,int> aval;
	aval[1]=D;
	for(int i=1;i<=n;i++){
		if(K==0) break;
		int l = arr[i].l;
		int r = arr[i].r;
		if(aval.empty()) continue;
		auto it = aval.upper_bound(l);
		if(it==aval.begin()) continue;
		else --it;
		if(it->second<r) continue;
		int icnt = allcnt;
		icnt-=getcnt(it->first,it->second);
		icnt+=getcnt(it->first,l);
		icnt+=getcnt(r,it->second); 
		if(icnt+1>=K){
			cout<<i<<"\n";
			int L = it->first;
			int R = it->second;
			aval.erase(it);
			aval.insert({L,l});
			aval.insert({r,R});
			allcnt = icnt;
			K--;
		}
	}
	if(K){
		cout<<-1<<"\n";
	}
	return 0;
}
