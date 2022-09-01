#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int w;cin>>w;
	int maxn=-1;
	for(int i=0;i<w;i++){
		int cmaxn = -1;
		for(int j=0;j<w;j++){
			int k;cin>>k;
			cmaxn = max(cmaxn,k);
			if(k>maxn) cout<<"("<<j<<","<<i<<")\n";
		}
		maxn = cmaxn;
	}

	return 0;
}
