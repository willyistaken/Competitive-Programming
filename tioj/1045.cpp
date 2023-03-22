#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll

struct q {
    int l,u,d,r;
};

signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n && n) {
        vector<q> query(n);
        vector<vector<int> > arr;
        vector<int> row;
        vector<int> col;
        for(int i=0; i<n; i++) {
            cin>>query[i].l>>query[i].u>>query[i].r>>query[i].d;
			row.push_back(query[i].l);
            row.push_back(query[i].r);
            col.push_back(query[i].u);
            col.push_back(query[i].d);
        }
        row.push_back(0);
        row.push_back(10000);
        col.push_back(0);
        col.push_back(10000);
        sort(row.begin(),row.end())	;
        row.resize(unique(row.begin(),row.end())-row.begin());
        sort(col.begin(),col.end());
        col.resize(unique(col.begin(),col.end())-col.begin());

        arr.resize(col.size());
        for(int i=0; i<col.size(); i++) arr[i].resize(row.size());
        for(int i=0; i<n; i++) {
            int l = lower_bound(row.begin(),row.end(),query[i].l)-row.begin();
            int r = lower_bound(row.begin(),row.end(),query[i].r)-row.begin();
            int u = lower_bound(col.begin(),col.end(),query[i].u)-col.begin();
            int d = lower_bound(col.begin(),col.end(),query[i].d)-col.begin();
            for(int j=u; j<d; j++) {
				for(int k = l;k<r;k++){
                	arr[j][k]++;
				}
            }
        }
		ll ans = 0;
        for(int i=0; i<col.size()-1; i++) {
            for(int j=0; j<row.size()-1; j++) {
				ans+=(1LL<<arr[i][j])*(row[j+1]-row[j])*(col[i+1]-col[i]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

