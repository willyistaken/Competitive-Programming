#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
bool can(vector<pair<int,int> > &arr){
	sort(arr.begin(),arr.end());
	priority_queue<int,vector<int>,greater<int> > pq;
	int head=0;
	for(int i=1;i<=n;i++){
		while(head<n && arr[head].first<=i){
			pq.push(arr[head].second);
			head++;
		}
		if(pq.empty()) return 0;
		if(pq.top()<i) return 0;
		pq.pop();
	}
	return 1;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n){
		vector<pair<int,int> > hoz(n);
		vector<pair<int,int> > ver(n);
		for(int i=0;i<n;i++){
			int a,b,c,d;cin>>a>>b>>c>>d;
			hoz[i].first = a;
			hoz[i].second = b;
			ver[i].first = c;
			ver[i].second = d;
		}
		if(can(hoz) && can(ver)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}
