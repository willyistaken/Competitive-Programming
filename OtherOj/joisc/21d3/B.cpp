#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
//#include<bits/extc++.h>
//__gnu_pbds

vector<ll> xd;
vector<ll> yd;
struct T{
	ll x1,y1;
	ll x2,y2;
} ;

struct lichao{
	struct line{
		ll m = 0 ;
		ll k = -1e18;
		ll operator()(ll x){
			return m*x+k;	
		}
	};
	struct node{
		line L;
		node* lc = nullptr;
		node* rc = nullptr;
		~node(){
			if(lc!=nullptr) delete(lc); 
			if(rc!=nullptr) delete(rc);
		}
	};
	node* head = new node();	
	void add(node* cur,ll L,ll R,line s){
		if(cur==nullptr) return;
		ll M = L+((R-L)/2);
		if(cur->L(M)<s(M)) swap(cur->L,s);
		if(L==R) return;
		if(s.m>cur->L.m){
			if(cur->rc==nullptr){
				cur->rc = new node();
				cur->rc->L = s;
				return;
			}
			add(cur->rc,M+1,R,s);
		}else{
			if(cur->lc==nullptr){
				cur->lc = new node();
				cur->lc->L = s;
				return;
			}
			add(cur->lc,L,M,s);
		}
	}

	ll query(node* cur,ll L,ll R,ll x){
		if(cur==nullptr) return -1e18;
		if(L==R) return cur->L(x);
		ll M = L+(R-L)/2;
		if(x>M) return max(cur->L(x),query(cur->rc,M+1,R,x));
		else return max(cur->L(x),query(cur->lc,L,M,x));
	}
	ll CX = 1e10;
	void insert(ll m,ll k){
		line p;		
		p.m = m;
		p.k = k;
		add(head,-CX,CX,p);
	}

	ll get(ll v){
		assert(abs(v)<CX);
		return query(head,-CX,CX,v);
	}
	
	~lichao(){
		delete(head);
	}
	
};



signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,Q;cin>>n>>Q;		
	vector<ll> C(n+1);
	vector<T> people(n+1);
	// input
	for(int i=1;i<=n;i++){
		int T,a,b;
		cin>>T>>a>>b>>C[i];
		C[i]/=2;
		people[i].x1 = a+T;
		people[i].y1 = T-a; 
		people[i].x2 = b+(abs(b-a)+T);
		people[i].y2 = (abs(b-a)+T)-b;
		xd.push_back(people[i].x1);
		yd.push_back(people[i].y1);
		xd.push_back(people[i].x2);
		yd.push_back(people[i].y2);
	}

	
	// cor com
	sort(xd.begin(),xd.end());
	xd.resize(unique(xd.begin(),xd.end())-xd.begin());
	sort(yd.begin(),yd.end());
	yd.resize(unique(yd.begin(),yd.end())-yd.begin());
	int X = xd.size();
	int Y = yd.size();
	vector<vector<ll> > dp(X+1,vector<ll>(Y+1,0));
	vector<vector<ll> >	costx(X+1,vector<ll>(Y+1,0));
	vector<vector<ll> >	costy(X+1,vector<ll>(Y+1,0));
	
	for(int i=1;i<=n;i++){
		people[i].x1 = lower_bound(xd.begin(),xd.end(),people[i].x1)-xd.begin();
		people[i].x2 = lower_bound(xd.begin(),xd.end(),people[i].x2)-xd.begin();
		people[i].y1 = lower_bound(yd.begin(),yd.end(),people[i].y1)-yd.begin();
		people[i].y2 = lower_bound(yd.begin(),yd.end(),people[i].y2)-yd.begin();
	}

	// cost init
	for(int i=1;i<=n;i++){
		if(people[i].x1==people[i].x2){
			for(int k = people[i].y1;k<people[i].y2;k++){
				costy[people[i].x1][k] = max(costy[people[i].x1][k],C[i]);
			}
		}else if(people[i].y1==people[i].y2){
			for(int k = people[i].x1;k<people[i].x2;k++){
				costx[k][people[i].y1] = max(costx[k][people[i].y1],C[i]);
			}
		}else{
			assert(1==0);
		}
	}
	// dp
	for(int x = X-1;x>=0;x--){
		for(int y=Y-1;y>=0;y--){
			if(y+1<Y) dp[x][y] = max(dp[x][y],dp[x][y+1]+(yd[y+1]-yd[y])*costy[x][y]);
			if(x+1<X) dp[x][y] = max(dp[x][y],dp[x+1][y]+(xd[x+1]-xd[x])*costx[x][y]);
		}
	}

	//ans
	vector<ll> ans(Q);
	vector<ll> qx(Q);
	vector<ll> qy(Q);
	vector<ll> qxB(Q);
	vector<ll> qyB(Q);
	vector<int> ord(Q);
	for(int i=0;i<Q;i++){
		ll t,x;cin>>t>>x;
		qx[i] = t+x;
		qy[i] = t-x;
		qxB[i] = upper_bound(xd.begin(),xd.end(),qx[i])-xd.begin();
		qyB[i] = upper_bound(yd.begin(),yd.end(),qy[i])-yd.begin();
		ord[i]=i;
	}

	sort(ord.begin(),ord.end(),[&](const int &a,const int &b){
		if(qyB[a]==qyB[b]) return qx[a]>qx[b];
		return qyB[a]<qyB[b];
	});
	int head = 0;	
	for(int y=0;y<Y;y++){
		lichao segy;
		for(int x=X-1;x>=0;x--){
			while(head<Q && qyB[ord[head]]==y && qx[ord[head]]>xd[x]){
				ans[ord[head]] = max(ans[ord[head]],segy.get(qy[ord[head]]));
				head++;
			}
			ll cy = (y==0)?(0):(costy[x][y-1]);
			segy.insert(-cy,dp[x][y]+cy*yd[y]);
		}
		while(head<Q && qyB[ord[head]]==y){
			ans[ord[head]] = max(ans[ord[head]],segy.get(qy[ord[head]]));
			head++; 
		}
	}
	sort(ord.begin(),ord.end(),[&](const int &a,const int &b){
		if(qxB[a]==qxB[b]) return qy[a]>qy[b];
		return qxB[a]<qxB[b];
	});
	head = 0;
	for(int x=0;x<X;x++){
		lichao segx;
		for(int y=Y-1;y>=0;y--){
			while(head<Q && qxB[ord[head]]==x && qy[ord[head]]>yd[y]){
				ans[ord[head]] = max(ans[ord[head]],segx.get(qx[ord[head]]));
				head++;
			}
			ll cx = (x==0)?(0):(costx[x-1][y]);
			segx.insert(-cx,dp[x][y]+cx*xd[x]);
		}
		while(head<Q && qxB[ord[head]]==x){
			ans[ord[head]] = max(ans[ord[head]],segx.get(qx[ord[head]]));
			head++;
		}
	}
	
	for(int i=0;i<Q;i++){
		cout<<ans[i]<<"\n";
	}

	return 0;
}
