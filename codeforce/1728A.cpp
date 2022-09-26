#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int maxc=0;int maxccnt=0;
		for(int i=0;i<n;i++){
			int a;cin>>a;
			if(maxccnt<a){
				maxccnt = a;
				maxc = i;
			}
		}
		cout<<maxc+1<<"\n";
	}

	return 0;
}
