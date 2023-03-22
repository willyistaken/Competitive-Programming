#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct edge{
	int from;
	int to;
	int c;
};
vector<pair<int,int>> rt;
vector<pair<int,int>> lt;
int n;
bool cmp(const edge &a,const edge &b){
	int disa = abs(a.from-a.to);
	int disb = abs(b.from-b.to);
	disa = min(disa,n-disa);
	disb= min(disb,n-disb);
	return disa<disb;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	cin>>n;
	rt.resize(n);
	lt.resize(n);
	vector<edge> es(n-3);
	string s;cin>>s;
	for(int i=0;i<n;i++){
		rt[i] =  {(i+1)%n,s[i]-'0'};
		lt[(i+1)%n] = {i,s[i]-'0'};
	}
	for(int i=0;i<n-3;i++){
		cin>>es[i].from>>es[i].to>>es[i].c;
		es[i].from--;
		es[i].to--;
	}
	sort(es.begin(),es.end(),cmp);
	bool par = 1;
	for(int i=0;i<n-3;i++){
		int a = es[i].from;
		int b = es[i].to;
		int c = es[i].c;
		if(rt[b].first==lt[a].first){
			swap(a,b);
		}
		if(rt[a].first==lt[b].first){
			if(c==rt[a].second || rt[a].second==lt[b].second || lt[b].second==c) par=0;	
			int k = rt[a].first;
			rt[lt[k].first] = {rt[k].first,c};
			lt[rt[k].first] = {lt[k].first,c};
			lt[k] = {k,0};
			rt[k] = {k,0};
		}else{
			cout<<"neispravna triangulacija\n";
			return 0;
		}
	}
	if(par){
		cout<<"tocno\n";
	}else{
		cout<<"neispravno bojenje\n";
	}
	return 0;
}
