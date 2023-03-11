#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<vector<ll> > dis;
int n,m;
vector<vector<ll> > ans;
void pow(int p) {
    ans.resize(n);
    for(int i=0; i<n; i++) ans[i].resize(n,1e17);
	for(int i=0;i<n;i++) ans[i][i]=0;
	vector<vector<ll> > og;
    while(p) {
        if(p&1) {
			og = ans;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    for(int k=0; k<n; k++) {
                        og[i][j] = min(og[i][j],ans[i][k]+dis[k][j]);
                    }
                }
            }
            ans = og;
        }
		og = dis;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                for(int k=0; k<n; k++) {
                    og[i][j] = min(og[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
		dis = og;
		p>>=1;
    }


}


int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    dis.resize(n);
    for(int i=0; i<n; i++) dis[i].resize(n,1e17);
    for(int i=0; i<n; i++) dis[i][i]=0;
    for(int i=0; i<m; i++) {
        ll a,b,c;
        cin>>a>>b>>c;
		a--;b--;
        dis[a][b] = min(dis[a][b],c);
    }
	int k,q;cin>>k>>q;
	pow(k);
	while(q--){
		int a,b;cin>>a>>b;
		a--;b--;
		if(ans[a][b]>5e16){
			cout<<-1<<"\n";
		}else{
			cout<<ans[a][b]<<"\n";
		}
	}


    return 0;
}
