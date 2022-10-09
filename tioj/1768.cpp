#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n+1];
	ll sum = 0;
	ll board=0;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		sum+=arr[i];
		board+=1LL*i*arr[i];
	}
	for(int x=0;x<max(1,n/2);x++){
		if(x){
		board-=1LL*x*arr[x];
		board-=1LL*(n-x+1)*arr[n-x+1];
		board+=1LL*(n-x+1)*arr[x];
		board+=1LL*x*arr[n-x+1];
		}
		if(board%sum==0){
				cout<<x<<" "<<(board/sum)-1<<"\n";
				return 0;
		}

	}


	return 0;
}
