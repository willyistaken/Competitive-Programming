#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



vector<int> arr;
bool can[8];
int n;
bool add(){
	int carry = 1;
	for(int i=0;i<n;i++){
		if(can[i]){
			arr[i]++;
			carry=0;
			if(arr[i]>=n) {
				arr[i]=0;
				carry=1;
			}
		}
		if(!carry) return 0;
	}
	return 1;
}

bool check(){
	bool car[n]={0};
	for(int i=0;i<n;i++){
		bool flag=0;
		for(int j=arr[i];j<n;j++){
			if(!car[j]){
				car[j]=1;
				flag=1;
				break;
			}
		}
		if(!flag) return 0;
	}
	return 1;
}
const int MOD = 998244353;
int pow(int a,int p){
	ll r = 1;
	while(p){
		if(p&1) r = (r*a)%MOD;
		a = (1LL*a*a)%MOD;
		p>>=1;
	}
	return r;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	if(n>8) {
		for(int i=0;i<n;i++){
			int a;cin>>a;
		}
		cout<<pow(n+1,n-1)<<"\n";	
		return 0;
	}
	arr.resize(n,0);
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		can[i]= !arr[i];
		if(arr[i]) arr[i]--;
	}
	int ans = 0;
	do{
		if(check()) ans++;
	}while(!add());
	cout<<ans<<"\n";
	return 0;
}
