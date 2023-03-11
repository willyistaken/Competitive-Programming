#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct point{
	bool type;
	int x;
	int w;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<point> s;
	vector<int> d;
	for(int i=0;i<n;i++){
		int l,r,w;cin>>l>>r>>w;
		s.push_back({0,l,w});
		s.push_back({1,r+1,w});
		d.push_back(l);
		d.push_back(r+1);
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	for(int g = 0;g<s.size();g++){
		s[g].x = lower_bound(d.begin(),d.end(),s[g].x)-d.begin();
	}
	sort(s.begin(),s.end(),[](const point &a,const point &b){return (a.x==b.x)?(a.type<b.type):(a.x<b.x);});
	int k = d.size();	
	int p = 0;
	ll havetodo = 0;
	ll maxn = 0;
	ll ans = 0;
	for(int i=0;i<k;i++){
		while(p<s.size() && s[p].x==i && s[p].type==0){
			havetodo+=s[p].w;
			p++;
		}
		ll goout = 0;	
		while(p<s.size() && s[p].x==i && s[p].type==1){
			havetodo-=s[p].w;
			goout+=s[p].w;
			p++;
		}
		maxn = max(0LL,maxn+goout);
		ans = max(ans,havetodo+maxn);
	}
	cout<<ans<<"\n";
	return 0;
}
