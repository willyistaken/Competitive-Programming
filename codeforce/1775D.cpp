#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> side[600005];
int pre[6000005];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n+1];
	vector<int> prime,minp(300005,0);	
	for(int i=2;i<300005;i++){
		if(!minp[i]){
			minp[i] = i;
			prime.push_back(i);
			for(int j = 2*i;j<300005;j+=i){
				if(!minp[j]) minp[j] =i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		int g = arr[i];
		while(g!=1){
			int p = minp[g];
			side[n+p].push_back(i);
			side[i].push_back(n+p);
			while(g%p==0) g/=p;
		}
	}
	int s,e;cin>>s>>e;	
	queue<int> q;
	pre[s] = -1;
	q.push(s);
	while(q.size()){
		int t = q.front();
		q.pop();
		if(e==t){
			stack<int> ans;
			while(pre[e]>0){
				if(e<=n) ans.push(e);
				e = pre[e];
			}
			cout<<ans.size()+1<<"\n"<<s;
			while(ans.size()){
				cout<<" "<<ans.top();
				ans.pop();
			}
			cout<<"\n";
			return 0;
		}
		for(auto i : side[t]){
			if(!pre[i]){
				pre[i] = t;
				q.push(i);
			}
		}
	}
	cout<<"-1"<<"\n";
	return 0;
}

