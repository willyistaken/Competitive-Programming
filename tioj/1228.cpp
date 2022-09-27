#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<iostream>
using namespace std;
typedef long long ll;


struct node{
	int time=0; 
	int submax=0;
};
const int MAXN = 1e6+2;
int n,q;
node arr[MAXN];
vector<pair<int,int> >  side[MAXN];
bool beingchild[MAXN];
int t;
struct fenwick{
	int a[MAXN];	
	void init(){
		memset(a,0,sizeof(a));
	}
	void add(int ind,int v){
		while(ind<=n){
			a[ind]+=v;
			ind += (ind & -ind);
		}
	}
	int query(int ind){
		int result=0;
		while(ind){
			result+=a[ind];
			ind -=(ind & -ind);
		}
		return result;
	}
} bit;
void dfs(int r){
	arr[r].time=++t;			
	for(auto i : side[r]){
		if(!arr[i.first].time){
			dfs(i.first);
			bit.add(arr[i.first].time,i.second);
		}
	}
	arr[r].submax = t;
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i=0;i<n-1;i++){
		int a,b,m;
		scanf("%d %d %d",&a,&b,&m);
		side[a].push_back({b,m});
		beingchild[b]=1;
	}
	bit.init();
	for(int i=0;i<n;i++){
		if(!beingchild[i]){
			dfs(i);
		}
	}
	while(q--){
		int type;scanf("%d",&type);
		if(type){
			int d;scanf("%d",&d);
			int ans;
			ans = bit.query(arr[d].submax)-bit.query(arr[d].time);
			printf("%d\n",2*ans);
		}else{
			int d;int v;
			scanf("%d %d",&d,&v);
			int ind = arr[d].time;
			int og = bit.query(arr[d].time)-bit.query(arr[d].time-1);
			bit.add(ind,-og);
			bit.add(ind,v);
		}
	}
	return 0;
}





//flatten the tree: the kind where you only mark in time(sum),  if you wants to cancel out the effect of subtree: use in and out marking;

