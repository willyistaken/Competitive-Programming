#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,p,q;cin>>n>>m>>p>>q;
	ll howmanystuff=(m-1)*(m-1);
	int ai[m];
	int aj[m];
	for(int i=0;i<m;i++) cin>>ai[i];
	for(int i=0;i<m-1;i++) cin>>aj[i+1];
	aj[0]=ai[0];
	for(int i=0;i<m;i++){
		int stuff=0;
		for(int j=0;j<m;j++){
			if(j!=0) {
				if((ai[i]^aj[j]^ai[0])<(ai[i]^aj[j-1]^ai[0])) stuff=0;
			}
			stuff++;
			if(stuff>=p) howmanystuff+=(min(q,stuff)-p)+1;
		}

	}
	for(int i=0;i<m;i++){
		int stuff=0;
		for(int j=0;j<m;j++){
			if(j!=0) {
				if((ai[j]^aj[i]^ai[0])<(ai[j-1]^aj[i]^ai[0])) stuff=0;
			}
			stuff++;
			if(stuff>=p) howmanystuff+=(min(q,stuff)-p)+1;
		}
	}
	cout<<howmanystuff%n<<"\n";
	return 0;
}
