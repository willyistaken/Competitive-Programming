#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	priority_queue<ll,vector<ll>,greater<ll> > pq;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		pq.push(k);
	}
	long long sum=0;
	while(pq.size()!=1){
		long long ne=0;
		ne+=pq.top();
		pq.pop();
		ne+=pq.top();
		pq.pop();
		sum+=ne;
		pq.push(ne);
	}

	cout<<sum<<"\n";

	return 0;
}
