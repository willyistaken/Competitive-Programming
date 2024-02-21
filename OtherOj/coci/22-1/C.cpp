#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e5+5;
bool vis[N];
pair<int,double> S[N];
vector<pair<int,double> > side[N];
pair<double,double> P[N];
double R[N];
inline double dis(pair<double,double> a,pair<double,double> b) {
    double ans = (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    return sqrtl(ans);
}
double X;
vector<int> v;
double maxn;
double minn;
void dfs(int cur) {
    if(vis[cur]) return;
    vis[cur]=1;
    v.push_back(cur);
    for(auto i : side[cur]) {
        pair<int,double> temp = {-S[cur].first,i.second-S[cur].second};
        if(S[i.first].first!=0) {
            if(S[i.first]!=temp) {
                if(S[i.first].first==temp.first) {
                    cout<<"NE\n";
                    exit(0);
                }
                if(S[i.first].first==1) {
                    X = (temp.second-S[i.first].second)/2;
                } else {
                    X = (S[i.first].second-temp.second)/2;
                }
            }
        }
        S[i.first]=temp;
        if(S[i.first].first>0) {
            minn = max(minn,-S[i.first].second);
        } else {
            maxn = min(maxn,S[i.first].second);
        }
        dfs(i.first);
    }
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        cin>>P[i].first>>P[i].second;
    }
    for(int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        double d = dis(P[a],P[b]);
        side[a].push_back({b,d});
        side[b].push_back({a,d});
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            S[i] = {1,0};
            maxn = 1e18;
            minn = 0;
            X=-1;
            dfs(i);
            if(X!=-1) {
                if(X<-1e-4) {
                    cout<<"NE\n";
                    return 0;
                }
				minn = X;
            }else{
            	if((maxn-minn)<-1e-4) {
                	cout<<"NE\n";
                	return 0;
				}	
			}
            for(auto u : v) {
                R[u] = (S[u].first*minn)+S[u].second;
            }
            v.clear();
        }
	}
    for(int i=1; i<=n; i++) {
		if(R[i]<-1e-4){
			cout<<"NE\n";
			return 0;	
		}
        for(auto u : side[i]) {
            //cout<<i<<" "<<u.first<<" "<<u.second<<"\n";
            if(R[i]+R[u.first]<u.second-1e-6 || R[i]+R[u.first]>u.second+1e-6){
				cout<<"NE\n";
				return 0;
            }
        }
    }
    cout<<"DA\n";
    for(int i=1; i<=n; i++) cout<<setprecision(7)<<abs(R[i])<<"\n";
    return 0;
}
