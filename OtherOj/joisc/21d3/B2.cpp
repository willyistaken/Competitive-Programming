#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;
 
struct pe{
	int t,a,b,c;
};
struct li{
	struct line{
		int m,k;
		line(){
			m=0,k=-1e18;
		}
		line(int a,int b){
			m=a;
			k=b;
		}
		int gv(int x){
			return m*x+k;
		}
	};
	struct no{
		no* lch=nullptr,*rch=nullptr;
		line val;
	};
	no* root=new no();
	void insert(no* v,line x,int L,int R){
		int m=(L+R)/2;
		if(x.gv(m)>v->val.gv(m)){
			swap(x,v->val);
		}
		if(L==R){
			return;
		}
		if(x.m>v->val.m){
			if(!v->rch){
				v->rch=new no();
				v->rch->val=x;
				return;
			}
			insert(v->rch,x,m+1,R);
		}
		else{
			if(!v->lch){
				v->lch=new no();
				v->lch->val=x;
				return;
			}
			insert(v->lch,x,L,m);
		}
	}
	int query(no* v,int p,int L,int R){
		if(!v){
			return -1e18;
		}
		if(L==R){
			return v->val.gv(p);
		}
		int m=(L+R)/2;
		if(p<=m){
			return max(v->val.gv(p),query(v->lch,p,L,m));
		}
		else{
			return max(v->val.gv(p),query(v->rch,p,m+1,R));
		}
	}
	inline void add(int a,int b){
		insert(root,line(a,b),0,1e10);
	}
	inline int qu(int x){
		return query(root,x,0,1e10);
	}
};
struct qu{
	int x,y;
	int lx,ly;
};
signed main(){
	AquA;
	int n,q;
	cin >> n >> q;
	vector<pe> v(n);
	vector<pair<int,int> > vp;
	vector<int> x,y;
	for(int i=0;i<n;i++){
		cin >> v[i].t >> v[i].a >> v[i].b >> v[i].c;
		v[i].c/=2;
		int e=v[i].t+abs(v[i].a-v[i].b),f=v[i].b;
		x.push_back(v[i].t+v[i].a);
		y.push_back(v[i].t-v[i].a);
		x.push_back(e+f);
		y.push_back(e-f);
	}
	x.push_back(1e10);
	y.push_back(1e10);
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	auto lis=[&](vector<int>& a,int b){
		return lower_bound(a.begin(),a.end(),b)-a.begin();
	};
	int sx=x.size(),sy=y.size();
	vector<vector<int> > ve(sx,vector<int>(sy)),ho=ve,dp=ve;
	for(int i=0;i<n;i++){
		int fx=lis(x,v[i].t+v[i].a),fy=lis(y,v[i].t-v[i].a);
		int e=v[i].t+abs(v[i].a-v[i].b),f=v[i].b;
		int tx=lis(x,e+f),ty=lis(y,e-f);
		assert(fx==tx || fy==ty);
		if(fx==tx){
			assert(fy<ty);
			for(int j=fy+1;j<=ty;j++){
				ho[fx][j]=max(ho[fx][j],v[i].c);
			}
		}
		else{
			assert(fx<tx);
			for(int j=fx+1;j<=tx;j++){
				ve[j][fy]=max(ve[j][fy],v[i].c);
			}
		}
	}
	for(int i=sx-1;i>=0;i--){
		for(int j=sy-1;j>=0;j--){
			if(i+1<sx){
				dp[i][j]=max(dp[i][j],dp[i+1][j]+(x[i+1]-x[i])*ve[i+1][j]);
			}
			if(j+1<sy){
				dp[i][j]=max(dp[i][j],dp[i][j+1]+(y[j+1]-y[j])*ho[i][j+1]);
			}
		}
	}
	vector<qu> vq(q);
	vector<int> ans(q);
	vector<vector<pair<int,int> > > ax(sx),ay(sy);
	for(int i=0;i<q;i++){
		int a,b;
		cin >> a >> b;
		int c=a+b,d=a-b;
		int e=lis(x,c),f=lis(y,d);
		vq[i].x=c;
		vq[i].y=d;
		vq[i].lx=e;
		vq[i].ly=f;
		ax[e].push_back({f,i});
		ay[f].push_back({e,i});
	}
	for(int i=0;i<sx;i++){
		sort(ax[i].begin(),ax[i].end());
		reverse(ax[i].begin(),ax[i].end());
	}
	for(int i=0;i<sy;i++){
		sort(ay[i].begin(),ay[i].end());
		reverse(ay[i].begin(),ay[i].end());
	}
	for(int i=0;i<sx;i++){
		li lst;
		int l=0;
		for(int j=sy-1;j>=0;j--){
			lst.add(ve[i][j],dp[i][j]);
			while(l<ax[i].size() && ax[i][l].fs==j){
				int id=ax[i][l].sc;
				ans[id]=max(ans[id],lst.qu(x[i]-vq[id].x));
				l++;
			}
		}
	}
	for(int i=0;i<sy;i++){
		li lst;
		int l=0;
		for(int j=sx-1;j>=0;j--){
			lst.add(ho[j][i],dp[j][i]);
			while(l<ay[i].size() && ay[i][l].fs==j){
				int id=ay[i][l].sc;
				ans[id]=max(ans[id],lst.qu(y[i]-vq[id].y));
				l++;
			}
		}
	}
	for(int i=0;i<q;i++){
		cout << ans[i] << "\n";
	}
	return 0;
}
