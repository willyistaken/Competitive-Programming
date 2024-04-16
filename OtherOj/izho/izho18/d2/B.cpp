#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 5e5;
int P[N];
int cnt[N];
int query(int a){
	if(P[a]==a) return a;
	P[a] = query(P[a]);
	return P[a];
}
void solve(){
	int n,m;cin>>n>>m;
	swap(n,m);
	/*
	if(n==1 && m==1){
		cout<<0<<"\n";
		return;
	}
	*/
	int i=0;
	for(;i<N;i++){
		P[i]=i;
		cnt[i]=0;
		if(i-m>=0){
			if(query(i)==query(i-m)){
				break;	
			}
			P[query(i)]=query(i-m);
			cnt[i]++;
		}
		if(i-n>=0){
			if(query(i)==query(i-n)){
				break;	
			}
			P[query(i)]=query(i-n);
			cnt[i-n]++;
		}
	}
	vector<int> ord;
	queue<int> q;
	for(int j=0;j<i;j++){
		if(cnt[j]==0) q.push(j);
	}
	while(q.size())	{
		int cur = q.front();
		q.pop();
		ord.push_back(cur);
		if(cur-n>=0){
			cnt[cur-n]--;
			if(cnt[cur-n]==0) q.push(cur-n);
		}
		if(cur+m<i){
			cnt[cur+m]--;
			if(cnt[cur+m]==0) q.push(cur+m);
		}
	}
	vector<int> ans(i);
	for(int j=0;j<i;j++) ans[ord[j]]=i-j;
	cout<<i-1<<"\n";
	for(int j=1;j<i;j++) cout<<ans[j]-ans[j-1]<<" ";
	cout<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
