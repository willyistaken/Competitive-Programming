#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int arr[n];
	vector<int> d;
	for(int i=0;i<n;i++){
		cin>>arr[i];	
		d.push_back(arr[i]);
	}
	sort(d.begin(),d.end());										
	d.resize(unique(d.begin(),d.end())-d.begin());
	vector<int> allcnt(d.size(),0);
	for(int i=0;i<n;i++){
		arr[i] = lower_bound(d.begin(),d.end(),arr[i])-d.begin();
		allcnt[arr[i]]++;
	}
	int B = sqrt(2*n);
	int C = (B/2);
	ll ans = 0;
	for(int i=0;i<n;i++){
		int maxn = 0;
		int maxstuff = -1;
		vector<int> cnt(d.size(),0);
		for(int j=i;j<i+B && j<n ;j++){
			cnt[arr[j]]++;
			if(maxn<cnt[arr[j]]){
				maxn = cnt[arr[j]];
				maxstuff = arr[j];
			}
			if(2*maxn>(j-i+1) && allcnt[maxstuff]<C) ans++;
		}
	}
	vector<int> cnt(2*n+5,0);
	for(int s=0;s<d.size();s++){
		if(allcnt[s]<C) continue;
		ll p = 0;
		int sum = 0;
		fill(cnt.begin(),cnt.end(),0);
		cnt[n]=1;
		for(int i=0;i<n;i++){
			if(arr[i]==s){
				p+=cnt[(sum++)+n];
				cnt[sum+n]++;
			}else{
				p-=cnt[(--sum)+n];
				cnt[sum+n]++;
			}
			ans+=p;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
