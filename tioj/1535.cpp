#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e8;
bitset<MAXN> notprime;
vector<int> ans;
int reverse(int n){
	int r=0;
	while(n){
		r*=10;
		r+=n%10;
		n/=10;
	}
	return r;
}
void init(){
	notprime[1]=1;
	for(int i=2;i<MAXN;i++){
		if(!notprime[i]){
			int k = reverse(i);
			if(k<i){
				if(!notprime[k]) {
					ans.push_back(k);
					ans.push_back(i);
				}
			}
			for(int j=2;j*i<MAXN;j++) notprime[j*i]=1;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	init();
	sort(ans.begin(),ans.end());
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		n--;
		cout<<ans[n]<<"\n";
	}
	return 0;
}
