#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
vector<pair<int,int> > a;
vector<int> b;
const int N = 15005;
vector<bitset<N> > req;
vector<int> pa(N);
vector<bitset<N>> dp[N];
int n;
int m;
void printb(bitset<N> &k){
	cout<<"printing: ";
	for(int i=0;i<=pa[n];i++){
		cout<<k[i];
	}
	cout<<"\n";
}


void cons(pair<int,int> cur,int val,vector<int> &result){
		int i = cur.first;
		int j = cur.second;
		//cout<<i<<" "<<j<<" "<<val<<endl;
		if(dp[i][j-1][val-b[i]]){
			result.push_back(i);
			if(j-1) cons({i,j-1},val-b[i],result);
		}else {
			cons({i-1,j},val,result);
		}
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	a.resize(n+1);
	for(int i=1;i<=n;i++){ cin>>a[i].first;a[i].second=i;}
	cin>>m;
	b.resize(m+1);
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(b.begin()+1,b.end(),greater<int>());
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++) pa[i] = pa[i-1]+a[i].first;
	int head =1;
	int cur=0;
	bitset<N> reqnow;
	req.push_back(reqnow);
	for(int i=1;i<=N;i++){
		while(head<=n && a[head].first<=i){
			head++;
		}
		while(cur<N && cur<=pa[head-1]+(i*(n-head+1))){
			reqnow[cur]=1;
			cur++;
		}
		req.push_back(reqnow);
	}
	for(int i=1;i<=m;i++){
		int J = min(pa[n],(pa[n]/b[i])+2);
		bitset<N> s;
		dp[i].push_back(s);
		dp[i][0][0]=1;
		for(int j=1;j<=J;j++){
			s.reset();
			s|=((dp[i][j-1])<<b[i]);
			if(dp[i-1].size()>j) s|=dp[i-1][j];
			s&=req[j];
			dp[i].push_back(s);
		}
	}
	pair<int,int> works;
	for(int j=1;j<=pa[n];j++){
		if(works.first) break;
		for(int i=m;i>=1;i--){
			if(works.first) break;
			if(j>=dp[i].size()) break;
			if(dp[i][j][pa[n]]){
				works = {i,j};	
				break;
			}
		}
	}
	if(!works.first){
		cout<<-1<<"\n";
		return 0;
	}
	cout<<works.second<<"\n";
	vector<int> result;
	cons(works,pa[n],result);
	for(int i=0;i<result.size();i++){
		result[i] = b[result[i]];
	}
	sort(result.begin(),result.end(),greater<int>());
	priority_queue<pair<int,int> > pq;
	for(int i=1;i<=n;i++) pq.push(a[i]);
	for(auto g : result){
		vector<int> ans;	
		vector<pair<int,int> > goback;
		for(int a=0;a<g;a++){
			pair<int,int> temp = pq.top();
			pq.pop();
			ans.push_back(temp.second);
			temp.first--;
			if(temp.first) goback.push_back(temp);
		}

		cout<<g<<" ";
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<"\n";
		for(auto temp :  goback) pq.push(temp);
	}
	return 0;
}
