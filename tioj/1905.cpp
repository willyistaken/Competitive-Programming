#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,f;
vector<int> arr(100005);
vector<int> d(100005);

struct seg{
	vector<int> arr;
	int s;
	void init(int g){
		s = g;
		arr.resize(2*s,INT_MAX);
	}

	void modify(int ind,int v){
		ind+=s;
		arr[ind]=min(arr[ind],v);
		ind>>=1;
		while(ind){
			arr[ind] = min(arr[2*ind],arr[2*ind+1]);
			ind>>=1;
		}
	}
	
	int query(int l,int r){
		int ans = INT_MAX;
		l+=s;r+=s;
		while(l<r){
			if(l&1) ans = min(ans,arr[l++]);
			if(r&1) ans = min(ans,arr[--r]);
			l>>=1;r>>=1;
		}
		return ans;
	}
};

struct Q{
	int l,r;
	int id;
	int ans;
};

int getid(int v){
	return lower_bound(d.begin(),d.end(),v)-d.begin();
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		d[i] = arr[i];
	}
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	cin>>f;
	Q q[f];
	for(int i=0;i<f;i++){
		cin>>q[i].l>>q[i].r;
		q[i].l--;q[i].r--;
		q[i].id = i;
	}
	sort(q,q+f,[](const Q &a,const Q &b){return a.r<b.r;});
	
	seg mindis;mindis.init(n);
	seg update;update.init(d.size());
	update.modify(getid(arr[0]),-0);	
	int qhead=0;
	for(int i=1;i<n;i++){
		// smaller side
		int c=0;
		int u;
		while(arr[i]-c>1 && (u = update.query(getid(c),getid(arr[i])+1) )<=0){
			u = -u;
			mindis.modify(u,arr[i]-arr[u]);
			c = (arr[u]+((arr[i]-arr[u])/2))+((arr[i]-arr[u])&1);
		}
		// larger side
		c = INT_MAX;
		while( c-arr[i]>1 &&(u = update.query(getid(arr[i]),getid(c)))<=0){
			u = -u;
			mindis.modify(u,arr[u]-arr[i]);
			c = (arr[i]+((arr[u]-arr[i])/2));
		}
		
		// update
		update.modify(getid(arr[i]),-i);
		// getans 
		while(qhead<f && q[qhead].r==i){
			q[qhead].ans = mindis.query(q[qhead].l,q[qhead].r);
			qhead++;
		}
	}
	sort(q,q+f,[](const Q &a,const Q &b){return a.id<b.id;});
	for(int i=0;i<f;i++){
		cout<<q[i].ans<<"\n";
	}



}