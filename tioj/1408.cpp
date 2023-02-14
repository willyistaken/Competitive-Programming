#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e6+5;
struct BIT{
	int arr[N+1] = {0};
	int s = N;
	void add(int i){
		while(i<=s){
			arr[i]++;
			i+=(i&-i);
		}
	}
	int query(int i){
		int ans=  0;
		while(i){
			ans+=arr[i];
			i-=(i&-i);
		}
		return ans;
	}
	void clear(){
		fill(arr,arr+N+1,0);
	}
} bit;

struct q{
	int l,r,c;
};

void solve(int k){
	int n = k;
	bit.clear();
	q query[n];		
	for(int i=0;i<n;i++) {cin>>query[i].l>>query[i].r>>query[i].c;query[i].l++;}
	sort(query,query+n,[](const q &a,const q &b){return (a.r==b.r)?(a.l<b.l):(a.r<b.r);});
	int pos = 0;					
	stack<int> ready;
	for(int i=1;i<N;i++){
		ready.push(i);
		while(pos<n && query[pos].r==i){
			int l = query[pos].l;
			int r = query[pos].r;
			int have = bit.query(r)-bit.query(l-1);
			for(int i=0;i<query[pos].c-have;i++){
				bit.add(ready.top());
				ready.pop();
			}
			pos++;
		}
	}
	cout<<bit.query(N)<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		solve(n);
	}	

	return 0;
}
