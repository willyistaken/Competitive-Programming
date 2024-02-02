#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int gcd(int a,int b){
	if(b==0) return a;
	a%=b;
	return gcd(b,a);
}

void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	if(n==1){
		cout<<1<<"\n";
		return;
	}
	sort(arr.begin(),arr.end());
	int x = 0;	
	for(int i=1;i<n;i++) x = gcd(abs(arr[i]-arr[i-1]),x);
	if(x<=0){
		cout<<"no\n";
		return ;
	}
	vector<int> stuff(n);
	int m = arr[0]%x;
	if(m<0) m+=x;
	for(int i=0;i<n;i++){
		stuff[i]=(arr[i]-m)/x;
	}
	ll ans = 0;
	bool k = 1;
	int s = -1;
	for(int i=n-1;i>=0;i--){
		if(i-1>=0){
			if(stuff[i]-1!=stuff[i-1]){
				if(k) s = stuff[i]-1;
				k=0;
			}
		}
		ans+=stuff[n-1]-stuff[i];
	}
	if(k){
		cout<<ans+n<<"\n";
	}else{
		ans+=stuff[n-1]-s;	
		cout<<ans<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
