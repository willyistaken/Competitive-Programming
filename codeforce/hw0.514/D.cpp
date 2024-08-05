#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int getlog(int a){
	for(int i=1;i<=10;i++){
		if(a<10){
			return i;
		}
		a/=10;
	}
	return 0;
}


vector<int> numbers[11];
const int K = 1005;
pair<int,int> w[K][K];
vector<int> lft[K];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		numbers[getlog(a)].push_back(a);
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			lft[i].push_back(j);
		}
	}
	int multiplier = 1;
	for(int l=1;l<=10;l++){
		multiplier=(10LL*multiplier)%k;
		vector<int> has(k,-1);
		for(auto i : numbers[l]){
			has[i%k]=i;
		}
		for(int i=0;i<k;i++){
			int base = (1LL*i*multiplier)%k;
			vector<int> temp;
			while(lft[i].size()){
				int need = (lft[i].back()-base+k)%k;
				if(has[need]!=-1){
					w[i][lft[i].back()] = {l,has[need]};
				}else{
					temp.push_back(lft[i].back());
				}
				lft[i].pop_back();
			}
			lft[i].swap(temp);
		}
	}


	vector<pair<int,int> > dis(k,{1e9,-1});
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(int i=0;i<k;i++){
		if(w[0][i].first!=0){
			dis[i]={w[0][i].first,0};
			pq.push({dis[i].first,i});
		}
	}
	while(pq.size()){
		pair<int,int> cur = pq.top();
		pq.pop();
		if(cur.first!=dis[cur.second].first) continue;
		for(int i=0;i<k;i++){
			if(w[cur.second][i].first==0) continue;
			int W = w[cur.second][i].first;
			if(dis[i].first>dis[cur.second].first+W){
				dis[i] = {dis[cur.second].first+W,cur.second};
				pq.push({dis[i].first,i});
			}
		}
	}

	if(dis[0].first>=5e8){
		cout<<"NO"<<"\n";
		return 0;
	}
	cout<<"YES\n";
	stack<int> ans;
	int cur = 0;
	do{
		ans.push(w[dis[cur].second][cur].second);
		cur = dis[cur].second;
	}while(cur!=0);

	while(ans.size()){
		cout<<ans.top();
		ans.pop();
	}
	cout<<"\n";
	return 0;
}
