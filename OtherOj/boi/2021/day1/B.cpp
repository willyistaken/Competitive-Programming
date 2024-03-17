    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    //#include<bits/extc++.h>
    //__gnu_pbds
     
     
    struct qT {
        int type;
        int a;
        int d;
        int t;
        qT(int _type,int _a,int _d,int _t):type(_type),a(_a),d(_d),t(_t) {}
    };
    const int N = 120005;
    vector<pair<int,int> > side[N];
    static const int B = 20;
    int P[N][B];
    int iv[N][B];
    int dv[N][B];
    pair<int,int> dfn[N];
     
    struct Qstruct {
        int n;
        int T;
        void dfs(int cur,int p,int v) {
            dfn[cur].first=++T;
            P[cur][0]=p;
            iv[cur][0]=v;
            dv[cur][0]=v;
            for(auto e : side[cur]) {
                if(e.first!=p) dfs(e.first,cur,e.second);
            }
            dfn[cur].second=++T;
        }
        void init(int _n) {
            n = _n;
            T = 0;
			dfs(1,1,0);
			for(int i=0;i<B;i++){
				P[1][i]=1;
				iv[1][i]=-1;
				dv[1][i]=-1;
			}
			for(int j=1;j<B;j++){
				for(int i=2;i<=n;i++){
					P[i][j] = P[P[i][j-1]][j-1];
					if(iv[i][j-1]==-1 || iv[P[i][j-1]][0]<iv[i][j-1]) iv[i][j]=-1;
					else iv[i][j]=iv[P[i][j-1]][j-1];
					if(dv[i][j-1]==-1 || dv[P[i][j-1]][0]>dv[i][j-1]) dv[i][j]=-1;
					else dv[i][j]=dv[P[i][j-1]][j-1];
				}
			}
        }
        bool isanc(int a,int b) {
            return (dfn[a].first<=dfn[b].first)&(dfn[a].second>=dfn[b].second);
        }
        int lca(int a,int b) {
            if(isanc(a,b)) return a;
            if(isanc(b,a)) return b;
            for(int j=B-1; j>=0; j--) {
                if(!isanc(P[a][j],b)) a = P[a][j];
            }
            return P[a][0];
        }
		int dec(int a,int b){
			assert(isanc(a,b));
			assert(a!=b);
			int v = 1e9;
			for(int j=B-1;j>=0;j--){
				if(!isanc(P[b][j],a)){
					if(v==-1 || dv[b][0]>v) v=-1;
					else v=dv[b][j];
					b = P[b][j];
				}
			}
			if(v==-1 || dv[b][0]>v) return -1;
			else return dv[b][0];
		}
		int inc(int a,int b){
			assert(isanc(a,b));
			assert(a!=b);
			int v = -1e9;
			for(int j=B-1;j>=0;j--){
				if(!isanc(P[b][j],a)){
					if(v==-1 || iv[b][0]<v) v=-1;
					else v=iv[b][j];
					b = P[b][j];
				}
			}
			if(v==-1 || iv[b][0]<v) return -1;
			else return iv[b][0];
		}
		bool query(int a,int d,int t){
			if(a==d) return 1;
			if(isanc(a,d)){
				int c = inc(a,d);
				return (c<=t)&&(c!=-1);
			}
			if(isanc(d,a)){
				int c = dec(d,a);
				return (dv[a][0]<=t)&&(c!=-1);
			}
			int c = lca(d,a);
			int na = dec(c,a);
			int nd = inc(c,d);
			if(na==-1 || nd==-1) return 0;
			if(na<nd) return 0;
			return (dv[a][0]<=t);
		}
    };
     
    struct Cstruct{
		
	};
     
    int main() {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
        int n,k;
        cin>>n>>k;
        vector<qT> query;
        for(int i=1; i<=n+k-1; i++) {
            char t;
            cin>>t;
            if(t=='S') {
                int a,b;
                cin>>a>>b;
                side[a].push_back({b,i});
                side[b].push_back({a,i});
            }
            if(t=='Q') {
                int a,d;
                cin>>a>>d;
                query.emplace_back(0,a,d,i);
            }
            if(t=='C') {
                int d;
                cin>>d;
                query.emplace_back(1,0,d,i);
            }
        }
        Qstruct Qans;
        Qans.init(n);
        for(auto cur : query)	{
            if(cur.type==0) {
                if(Qans.query(cur.a,cur.d,cur.t)){
    				cout<<"yes\n";
    			}else{
    				cout<<"no\n";
    			}
            } else {
            }
        }
        return 0;
    }
