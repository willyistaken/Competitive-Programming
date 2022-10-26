#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int lcm(int a,int b,int c){
	int l1 = (a*b/__gcd(a,b));
	return (l1*c/__gcd(l1,c));
}
void solve(){
	int l,r;cin>>l>>r;
	vector<int> factor[r-l+1];
	for(int i = l;i<=r;i++){
		for(int j = 2*i ; j<=r ; j+=i){
			factor[j-l].push_back(i);
		}
	}
	int twos[r-l+1] = {0};
	for(int i = l;i<=r;i++){
		int g = i;
		while(g%2==0) {
			twos[i-l]++;
			g/=2;
		}
	}
	vector<int> twofactor[r-l+1];
	for(int i = l;i<=r;i++){
		if(twos[i-l]){
			for(int j = i+(i/2) ; j<=r ; j+=(i/2)){
				if(twos[j-l]==(twos[i-l]-1)) {
					twofactor[j-l].push_back(i);
				}
			}
		}
	}
	ll all = (1LL*(r-l+1)*(r-l)*(r-l-1))/6;
	for(int i= l;i<=r;i++){
		//cout<<(1LL*arr[i-l]*(arr[i-l]-1))/2<<"\n";
		all-=(1LL*factor[i-l].size()*(factor[i-l].size()-1))/2;
		ll temp = 0;
		for(int j = 0;j<twofactor[i-l].size();j++){
			all-=(factor[i-l].size()-(upper_bound(factor[i-l].begin(),factor[i-l].end(),i-twofactor[i-l][j])-factor[i-l].begin()));
			all-=(twofactor[i-l].size()-(upper_bound(twofactor[i-l].begin(),twofactor[i-l].end(),max(i-twofactor[i-l][j],twofactor[i-l][j]))-twofactor[i-l].begin()));
		}
	}
	cout<<all<<"\n";
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
