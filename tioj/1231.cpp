#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct stuff{
	int v;
	int t;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	stuff arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].v>>arr[i].t;	
	}
	int T;cin>>T;
	priority_queue<int,vector<int>,greater<int> > pq;
	sort(arr,arr+n,[](const stuff &a,const stuff &b){return a.t<b.t;});
	int nowt=0;
	for(int i=0;i<n;i++){
		if(nowt>=min(arr[i].t,T)){
			pq.push(arr[i].v);	
			pq.pop();
		}else{
			pq.push(arr[i].v);
			nowt++;
		}
	}
	int h = pq.size();
	ll sum=0;
	while(!pq.empty()){
		sum+=pq.top();
		pq.pop();
	}
	cout<<sum-T+h<<"\n";
	return 0;
}
