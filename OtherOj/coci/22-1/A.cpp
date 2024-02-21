#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int r,s;cin>>r>>s;
	while(n--){
		vector<string> arr(r);
		for(int i=0;i<r;i++){
			cin>>arr[i]	;
		}
		int maxn = -1;
		int minn = 1e9;
		for(int i=0;i<s;i++){
			for(int j=r-1;j>=0;j--){
				if(arr[j][i]=='#'){
					maxn = max(maxn,r-j);
					minn = min(minn,r-j);
					break;
				}
			}
		}
		cout<<maxn-minn<<"\n";
	}

	return 0;
}
