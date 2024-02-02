#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


vector<int> arr;
int n;
vector<int> prime;
const int N = 1e5+5;
bool notprime[N];
pair<int,int> realupdate(int p){
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(ans<p) ans+=p-(arr[i]%p);
		else ans+=min(arr[i]%p,p-(arr[i]%p) );
	}
	return {ans,p};
}
pair<int,int> update(int g){
	if(g==0) return {1e9,1};
	pair<int,int> minn = {1e9,1};
	for(auto i : prime)	{
		if(g%i==0){
			minn = min(minn,realupdate(i));
			while(g%i==0) g/=i;
		}
	}
	if(g!=1) minn = min(minn,realupdate(g));
	return minn;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin>>n;
	for(int i=2;i<N;i++){
		if(!notprime[i]){
			prime.push_back(i);
			for(int j=i;j<N;j+=i){
				notprime[j]	=1;
			}
		}
	}
	pair<int,int> ans = {0,2};
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i]	;
		if(arr[i]&1) ans.first++;
	}
	ans.first = min(ans.first,n-ans.first);
	for(int t=0;t<20;t++){
		int k = uniform_int_distribution<int>(0,n-1)(rng);
		ans = min(ans,update(arr[k]-1));
		ans = min(ans,update(arr[k]));
		ans = min(ans,update(arr[k]+1));
	}
	for(int i=0;i<n;i++){
		if(arr[i]<ans.second) cout<<ans.second<<" ";
		else{
		if(arr[i]%(ans.second)<ans.second-arr[i]%(ans.second)) cout<<arr[i]-arr[i]%(ans.second)<<" ";
		else cout<<arr[i]+ans.second-arr[i]%ans.second<<" ";
		}
	}
	return 0;
}
