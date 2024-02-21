#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 5e5+5;
const int MOD = 1e9+7;
vector<pair<int,int> > side[N];
vector<pair<int,int> > rside[N];
int in[N];
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int a,b,w;
        cin>>a>>b>>w;
        side[a].push_back({b,w});
        rside[b].push_back({a,w});
        in[b]++;
    }
    vector<int> order;
    queue<int> remove;
    for(int i=1; i<=n; i++) {
        if(in[i]==0) remove.push(i);
    }
    while(remove.size()) {
        for(auto i : side[remove.front()]) {
            in[i.first]--;
            if(in[i.first]==0) remove.push(i.first);
        }
        order.push_back(remove.front());
        remove.pop();
    }
    vector<pair<ll,ll> > dp1(n+1, {-1e18,0});
    dp1[1].first = 0;
    dp1[1].second = 1;
    for(auto i : order) {
        for(auto u : rside[i]) {
            if(dp1[i].first<dp1[u.first].first+u.second) {
                dp1[i].first=dp1[u.first].first+u.second;
                dp1[i].second = dp1[u.first].second;
            } else if(dp1[i].first==dp1[u.first].first+u.second) {
                dp1[i].second=(dp1[i].second+dp1[u.first].second)%MOD;
            }
        }
    }
    vector<pair<ll,ll> > dp2(n+1, {-1e18,0});
    dp2[n].first=0;
    dp2[n].second=1;
    for(int ii=n-1; ii>=0; ii--) {
        int i = order[ii];
        for(auto u : side[i]) {
            if(dp2[i].first<dp2[u.first].first+u.second) {
                dp2[i].first=dp2[u.first].first+u.second;
                dp2[i].second = dp2[u.first].second;
            } else if(dp2[i].first==dp2[u.first].first+u.second) {
                dp2[i].second=(dp2[i].second+dp2[u.first].second)%MOD;
            }
        }
    }
    vector<int> revorder(n+1);
    int ttt = 0;
    for(auto i : order) {
        revorder[i]=++ttt;
    }
    vector<vector<pair<ll,int> > > add(n+1);
    vector<vector<pair<ll,int> > > rem(n+2);
    for(int i=1; i<=n; i++) {
        for(auto u : side[i]) {
            ll dis = dp1[i].first+dp2[u.first].first+u.second;
            ll cnt = (1LL*dp1[i].second*dp2[u.first].second)%MOD;
            add[revorder[i]+1].push_back({dis,cnt});
            rem[revorder[u.first]].push_back({dis,cnt});
        }
    }
    pair<ll,int> def = dp1[n];
    map<ll,int> cnt;
    map<ll,int> exist;
	vector<pair<ll,int>> ans(n+1);
    for(int k=1; k<=n; k++) {
        for(auto i : add[k]) {
            cnt[i.first]=(cnt[i.first]+i.second)%MOD;
            exist[i.first]++;
        }
        for(auto i : rem[k]) {
            cnt[i.first]=(cnt[i.first]-i.second)%MOD;
            exist[i.first]--;
            if(exist[i.first]==0) exist.erase(i.first);
        }
        if(k<revorder[1] || k>revorder[n])	{
			ans[k] = def;
        } else {
            if(exist.empty()) ans[k] = {-1,0};
            else {
                auto it = exist.rbegin();
                ll dis = it->first;
                ll rcnt = cnt[dis];
                if(rcnt<0) rcnt+=MOD;
				ans[k] = {dis,rcnt};
            }
        }
    }
	cout<<-1<<"\n";
	for(int i=2;i<n;i++){
		if(ans[revorder[i]].first<=0){
			cout<<-1<<"\n";
		}else{
			cout<<ans[revorder[i]].first<<" "<<ans[revorder[i]].second<<"\n";
		}
	}
	cout<<-1<<"\n";
    return 0;
}
