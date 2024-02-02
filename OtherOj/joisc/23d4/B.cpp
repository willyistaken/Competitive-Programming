#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct node{
	ll prio;
	int u,v;
	node* cd=nullptr;
	node* sb=nullptr;
	int size = 1;
};


node* merge(node* a,node* b){
		if(a==nullptr) return b;
		if(b==nullptr) return a;
		if(a->prio>b->prio) {
			a->sb = b->cd;
			b->cd = a;
			b->size+=a->size;
			return b;
		}else{
			b->sb = a->cd;	
			a->cd = b;
			a->size+=b->size;
			return a;
		}
		assert(1==0);
		return a;
}

node* merge_sb(node *a){
	if(a==nullptr) return a;
	if(a->sb==nullptr) return a;
	return merge(merge(a,a->sb),merge_sb(a->sb->sb));
}
int get_size(node* a){
	if(a==nullptr) return 0;
	return a->size;
}

node* pop(node* a){
	assert(a!=nullptr);
	int z  = get_size(a);
	node* ans = merge_sb(a->cd);
	if(ans!=nullptr) ans->size = z-1;
	return ans;
}

const int N = 2e5+5;
int P[N];
int A[N];
int query(int x){
	if(x!=P[x])  P[x] = query(P[x]);
	return P[x];
}

void join(int a,int b){
	a = query(a);
	b = query(b);
	if(a==b) return;
	P[a]=b;
}


node* R[N];

ll cost[N];

priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;

bool taken[N];


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	for(int i=1;i<=n;i++) P[i]=i;
	for(int i=1;i<=n;i++) cin>>A[i];
	ll additional = 0;
	vector<ll> ans(n);
	pair<ll,int> maxn = {-1,-1};
	pair<ll,int> minn = {1e18,-1};
	for(int i=1;i<=n;i++){
		ans[n-1]+=A[i];
		additional-=A[i];
		maxn = max(maxn,{A[i],i});
		minn = min(minn,{A[i],i});
	}
	additional+=maxn.first;
	int ONE = minn.second;
	ans[n-1]+=1LL*(n-2)*A[ONE];
	/*
	step?:
	find the smallest cost and the two component and merge them
	repeat
	find the smallest cost component
		define cost of a componet: minus a1 bridge and add cross componet edge
	global_min prioirty_queue inorder to get everything
		if the top of prioirty queue is not up to date (the cost is not the same) pop
		merge componet on the pop of priority queue, push the new one into prioirty_queue
		record the answer 
		repeat till added edge = 0
		the component's  union find set rrepresent it
	*/
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		node* tempu = new node;
		tempu->prio = A[u]+A[v];
		tempu->u = u;
		tempu->v = v;
		R[u] = merge(R[u],tempu);
		node* tempv = new node;
		tempv->prio = A[u]+A[v];
		tempv->u = v;
		tempv->v = u;
		R[v] = merge(R[v],tempv);
	}
	for(int i=1;i<=n;i++){
		cost[i]	=  -(A[ONE]+A[i])+(R[i]->prio);
		pq.push({cost[i],i});
	}
	for(int i=n-2;i>=0;i--){
		pair<ll,int> cur = {-1,-1};
		while(pq.size()){
			cur = pq.top();
			pq.pop();
			if(taken[cur.second]) continue;
			if(cost[cur.second]!=cur.first) continue;
			break;
		}
		taken[cur.second]=1;
		ans[i] = ans[i+1]+cost[cur.second];
		int a = cur.second;
		int b = query(R[cur.second]->v);
		join(a,b);
		R[b] = merge(R[a],R[b]);
		while(get_size(R[b])){
			if(query(R[b]->u)==query(R[b]->v)) R[b] = pop(R[b]);
			else break;
		}
		ll prev = cost[b];
		if(!get_size(R[b])) cost[b] = 1e15;
		else cost[b] = -(A[ONE]+A[b])+(R[b]->prio);
		if(cost[b]!=prev){
			pq.push({cost[b],b});
		}
	}
	for(int i=0;i<=q;i++){
		cout<<ans[min(i,n-1)]+additional<<"\n";
	}
	return 0;
}
