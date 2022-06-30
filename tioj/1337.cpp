#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
vector<vector<int> > line;
vector<int> cover;

bool check(int p){
	vector<int> tempcover = cover;
	int now = 0;
	priority_queue<int> pq;
	int needstone=0;
	for(int i=0;i<n;i++){
		for(auto r : line[i]) pq.push(r);
		now+=tempcover[i];
		if(now>p){
			for(int g=0;g<now-p;g++){
				needstone++;
				tempcover[pq.top()]++;
				pq.pop();
				now--;
			}
		}
		if(needstone>k) return false;
	}

	return true;

}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	set<int> ccs;
	vector<pair<int,int> > stuff;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		stuff.push_back({a,b});
		ccs.insert(a);
		ccs.insert(b);
	}
	unordered_map<int,int> mp;
	for(auto i : ccs) mp.insert({i,mp.size()});
	n = mp.size();
	line.resize(n);	
	cover.resize(n);
	fill(cover.begin(),cover.end(),0);
	for(auto i : stuff){
		line[mp[i.first]].push_back(mp[i.second]);
		cover[mp[i.first]]+=1;
		cover[mp[i.second]]-=1;
	}
	int r=n;int l=-1;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid)){
			r = mid;
		}else{
			l=mid;
		}
	}
	cout<<r<<"\n";
	return 0;
}
