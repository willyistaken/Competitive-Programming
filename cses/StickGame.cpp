#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




bool wl[1000005];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	int arr[k];
	for(int i=0;i<k;i++) cin>>arr[i];
	sort(arr,arr+k);
	for(int i=1;i<=n;i++){
		wl[i]=1;
		for(int j=0;j<k&&i-arr[j]>=0;j++){
			wl[i]&=wl[i-arr[j]];
		}
		wl[i] = !wl[i];
		cout<<"LW"[wl[i]];
	}
	cout<<"\n";
	return 0;
}
