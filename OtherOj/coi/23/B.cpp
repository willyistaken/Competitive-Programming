#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;	
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++) cin>>arr[i];
	vector<bool> hastobe(n+1);
	vector<bool> last(n+1);
	vector<int> cost(n);
	for(int i=0;i<n;i++) cin>>cost[i];
	for(int i=1;i<n;i++){
		if(arr[i+1]!=0 && arr[i+1]!=arr[i]+1) last[i]=1;
		else if(arr[i+1]==0) hastobe[i]=1;
	}
	last[n]=1;
		
 
	return 0;
}
