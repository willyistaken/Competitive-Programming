#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

/*
is I know the division, checking will be if there a segment that intersegt and not entirly contain.
i think this is a dp problem..
every segment will have some segment that it cannot be together with.. , count the number of partition
it can be turn into count the number of way to 2-color a graph
the answer seems to be 2^x ??? why
*/



// the below code is wrong

struct BIT{
	vector<int> arr;
	int _n;
	void init(int s){
		arr.resize(s+1,0);
		_n = s;
	}
	void modify(int ind,int v){
		while(ind<=_n){
			arr[ind]+=v;
			ind+=(ind & -ind);
		}
	}
	int query(int ind){
		int ans = 0;
		while(ind){
			ans+=arr[ind];
			ind-=(ind & -ind);
		}
		return ans;
	}

};



const int MOD = 1e9+7;
const int N = 1e6+5;
int vis[N];

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    vector<int> action(2*n+1);
    vector<pair<int,int> > seg(n+1);
    for(int i=1; i<=n; i++) cin>>seg[i].first>>seg[i].second;
    sort(seg.begin()+1,seg.end());
    for(int i=1; i<=n; i++) {
        action[seg[i].first]=i;
        action[seg[i].second]=-i;
    }
    /*
     check for 2 color in back: if then return 0
     check for no color in back: if then ++ and random assign a color
     check for 1 color in back if then ++ and assign opposite color
    */
    vector<int> color(n+1,0);
    BIT cnt[2];
	for(int i=0;i<2;i++) cnt[i].init(n);
    set<int> noc;
	int cc = 0;
    for(int i=1; i<=2*n; i++) {
        int p = abs(action[i]);
        if(action[i]>0) {
            if(color[p]==0) noc.insert(p);
            else cnt[color[p]-1].modify(p,1);
        } else {
            if(color[p] && cnt[color[p]-1].query(n)-cnt[color[p]-1].query(p)) {
                cout<<0<<"\n";
                return 0;
            }
            bool cnt1 = (cnt[1-1].query(n)-cnt[1-1].query(p)>0);
            bool cnt2 = (cnt[2-1].query(n)-cnt[2-1].query(p)>0);
            if(cnt1 && cnt2) {
                cout<<0<<"\n";
                return 0;
            }
            if(!color[p]){
				if(cnt1) color[p]=2;
				else color[p]=1;
				cnt[color[p]-1].modify(p,1);
				if(!cnt1 && !cnt2) cc++;
				noc.erase(p);
			}
            while(noc.size()) {
                auto t = noc.rbegin();
				if(*t<=p) break;
                color[*t]=3-color[p];
                cnt[color[*t]-1].modify(*t,1);
                noc.erase(*t);
            }
			cnt[color[p]-1].modify(p,-1);
		}
		cout<<i<<","<<p<<":\n";
		for(auto k : noc) cout<<k<<" ";
		cout<<"\n";
		for(int k=0;k<2;k++){
			for(int j=1;j<=n;j++) cout<<cnt[k].query(j)-cnt[k].query(j-1);
			cout<<"\n";
		}
    }
	ll ans = 1;
	for(int i=0;i<cc;i++){
		ans = (2*ans)%MOD;
	}
	cout<<ans<<"\n";
    return 0;
}
