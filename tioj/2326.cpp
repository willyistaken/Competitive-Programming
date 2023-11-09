#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	int A,B,K;
	cin>>A>>B>>K;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	while(q--){
		int l,r;cin>>l>>r;
		l--;r--;
		int cnt = 0;
		for(int i=l;i<=r;i++){
			for(int j=i+1;j<=r;j++){
				if((arr[i]^arr[j]^A)+(arr[i]^arr[j]^B)>=K) cnt++;
			}
		}
		cout<<cnt<<"\n";
	}

	return 0;
}
