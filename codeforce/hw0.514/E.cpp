#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


pair<int,int> frac(int a,int b){
	if (a==0){
		return {0,1};
	}
	if (b==0) {
		return {1e9,1e9};
	}
	int d = __gcd(a,b);
	a/=d;
	b/=d;
	if(a*b<0 && a>0){
		a*=-1;
		b*=-1;
	}
	return {a,b};
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	map<pair<int,int>,int> cnt;
	for(int i=1;i<n;i++){
		cnt[frac(arr[i],arr[i-1])]++;
	}
	if (!cnt.count({1e9,1e9}) && cnt.size()<=1){
		cout<<0<<"\n";
		return 0;
	}
	for(int i=0;i<n;i++){
		int l = i-1;
		int r = i+1;
		if (l>=0 && l<n){
			auto pl = frac(arr[i],arr[l]);
			cnt[pl]--;
			if (cnt[pl] == 0){
				cnt.erase(pl);
			}
		}
		if (r>=0 && r<n){
			auto pr = frac(arr[r],arr[i]);
			cnt[pr]--;
			if (cnt[pr] == 0){
				cnt.erase(pr);
			}
		}
		if(r>=0 && r<n && l>=0 && l<n){
			auto plr = frac(arr[r],arr[l]);
			cnt[plr]++;
		}
		if (!cnt.count({1e9,1e9}) && cnt.size()<=1){
			cout<<1<<"\n";
			return 0;
		}
		if(r>=0 && r<n && l>=0 && l<n){
			auto plr = frac(arr[r],arr[l]);
			cnt[plr]--;
			if (cnt[plr] == 0){
				cnt.erase(plr);
			}
		}
		if (r>=0 && r<n){
			auto pr = frac(arr[r],arr[i]);
			cnt[pr]++;
		}
		if (l>=0 && l<n){
			auto pl = frac(arr[i],arr[l]);
			cnt[pl]++;
		}
	}
	cout<<2<<"\n";
	return 0;
}
