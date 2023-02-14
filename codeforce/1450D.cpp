#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;
int arr[300000];

bool check(int k){
	set<int> s;
	deque<int> dq;
	int i=0;
	for(;i<n;i++){
		while(dq.size()){
			if(dq.front()<=i-k) dq.pop_front();
			else break;
		}
		while(dq.size()){
			if(arr[dq.back()]>=arr[i]) dq.pop_back();
			else break;
		}
		dq.push_back(i);
		if(i>=k-1) {
			s.insert(arr[dq.front()]);
		}
	}
	if(s.size()==n-k+1 && *s.rbegin()==n-k+1){
		return 1;
	}
	return 0;
}

void solve(){
	cin>>n;
	int minn = 1e9;
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		minn = min(minn,arr[i]);
		s.insert(arr[i]);
	}
	if(minn!=1){
		for(int i=0;i<n;i++) cout<<0;
		cout<<"\n";
		return ;
	}
	if(n==1){
		cout<<1<<"\n";
		return ;
	}
	cout<<(s.size()==n && *s.rbegin()==n);
	int l = 1;int r = n;
	while(r-l>1){
		int m = (l+r)/2;
		if(check(m)) r= m;
		else l = m;
	}
	for(int i=2;i<=l;i++) cout<<0;
	for(int i=r;i<n;i++) cout<<1;
	cout<<1<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

