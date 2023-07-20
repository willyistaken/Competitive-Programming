#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=0;i<n;i++){
		int b;cin>>b;
		pq.push(b);
	}
	int cnt = 0;	
	for(int i=0;i<n;i++){
		int c = pq.top();
		pq.pop();
		if(c<a[i]){
			cnt++;
		}
		pq.push(a[i]);
		pq.pop();
	}
	cout<<cnt<<"\n";
	return 0;
}
