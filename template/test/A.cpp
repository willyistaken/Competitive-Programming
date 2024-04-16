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
     
     
    struct DSU{
    	vector<int> P;
    	int n;
    	void init(int _n){
    		n = _n;
    		P.resize(_n+1);
    		for(int i=1;i<=n;i++) P[i]=i;
    	}
    	int query(int a){
    		if(P[a]==a) return a;
    		P[a] = query(P[a]);
    		return P[a];
    	}
    	void join(int a,int b){
    		a = query(a);
    		b = query(b);
    		P[a]=b;
    		return;
    	}
    };
     
    const int MOD = 1e9+7;
    const int N = 2005;
    vector<int> side[N];
     
    int vis[N];
     
    bool dfs(int cur,int c){
    	vis[cur]=3-c;
    	bool k = 1;
    	for(auto i : side[cur]){
    		if(!vis[i])	k&=dfs(i,vis[cur]);
    		else if(vis[i]==vis[cur]){
    			return 0;
    		}
    	}
    	return k;
    }
     
    int main(){
    	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    	int n;cin>>n;	
    	vector<pair<int,int> > seg(n+1);
    	for(int i=1;i<=n;i++) cin>>seg[i].first>>seg[i].second;
    	sort(seg.begin()+1,seg.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.second<b.second;});
    	DSU d;
    	d.init(n);
    	for(int i=1;i<=n;i++){
    		for(int j=i-1;j>=1;j--)	{
    			if(seg[i].first>seg[j].second) continue;
    			if(seg[j].first>seg[i].first) continue;
    			side[i].push_back(j);
    			side[j].push_back(i);
    		}
    	}
    	ll ans = 1;
    	for(int i=1;i<=n;i++){
    		if(!vis[i]) {
    			if(!dfs(i,2)){
    				cout<<0<<"\n";
    				return 0;
    			}
    			ans = (2*ans)%MOD;
    		}
    	}
    	cout<<ans<<"\n";
    	
    	return 0;
    }
