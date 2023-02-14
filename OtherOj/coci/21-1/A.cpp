#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int prevtime[8]={0};
	ll team[2] = {0};
	for(int i=0;i<n;i++){
		int t;cin>>t;
		int a,b;cin>>a>>b;
		a--;b--;
		team[a/4]+=100;
		if(prevtime[a] && prevtime[a]+10>=t) {
			team[a/4]+=50;
		}
			
		prevtime[a]=t;
	}
	cout<<team[0]<<" "<<team[1]<<"\n";

	return 0;
}
