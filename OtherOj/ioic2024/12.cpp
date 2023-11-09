#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds




signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<int> sqp[m];
	int r[n];
	int c[n];
	int w[n];
	for(int i=0;i<n;i++){
		int l;
		cin>>l>>r[i]>>c[i]>>w[i];
		l--;
		r[i]--;
		sqp[l].push_back(i);
	}
	auto comp = [&](const int a,const int b){
		return (w[a]==w[b])?(a>b):(w[a]<w[b]);
	};
	priority_queue<int,vector<int>,decltype(comp)> pq(comp);
	for(int i=0;i<m;i++){
		int b;cin>>b;
		for(auto v : sqp[i]) pq.push(v);
		ll ans = 0;
		while(pq.size() && b){
			int a = pq.top();
			pq.pop();
			if(r[a]<i)	continue;
			if(b>=c[a]){
				b-=c[a];
				ans+=1LL*w[a]*c[a];
			}else{
				ans+=b*w[a];
				c[a]-=b;
				b=0;	
				pq.push(a);
			}
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
	return 0;
}
