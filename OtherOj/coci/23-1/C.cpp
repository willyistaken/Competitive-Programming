#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void reduce(int n,int r,vector<int> &a,vector<int> &b){
	deque<int> dq;	
	for(int i=0;i<n;i++){
		while(dq.size() && a[dq.back()]<a[i]){
			dq.pop_back();
		}
		while(dq.size() && dq.front()<=(i-r)){
			dq.pop_front();
		}
		dq.push_back(i);
		if(i>=r-1){
			b.push_back(a[dq.front()]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<vector<int> > arr(m,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){ 
			cin>>arr[j][i];
		}
	}
	int r,s;cin>>r>>s;	
	vector<vector<int> > arr2(n-r+1);
	for(int i=0;i<m;i++){
		vector<int> k;	
		reduce(n,r,arr[i],k);
		for(int j=0;j<n-r+1;j++){
			arr2[j].push_back(k[j]);
		}
	}
	for(int i=0;i<n-r+1;i++){
		vector<int> k;
		reduce(m,s,arr2[i],k);
		for(auto v : k) cout<<v<<" ";
		cout<<"\n";
	}
	
	return 0;
}
