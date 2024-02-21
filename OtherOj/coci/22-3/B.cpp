#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int n,q;
vector<int> cnt;

void add(int c,int v){
	c+=(n-1);
	cnt[c]+=v;
}

int query(int c){
	c+=(n-1);
	return cnt[c];
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	vector<int> dif(n);	
	vector<int> arr(n);
	vector<int> pos(n);
	cnt.resize(2*n-1);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i]--;
		pos[arr[i]]=i;
	}
	for(int i=0;i<n;i++){
		dif[i] = arr[(i+1)%n]-arr[i];
		add(dif[i],1);
	}
	while(q--){
		int x,y;cin>>x>>y;	
		x--;
		y--;
		swap(arr[pos[x]],arr[pos[y]]);
		swap(pos[x],pos[y]);
		set<int> nc;
		int k = pos[x]-1; 
		if(k<0) k+=n;
		nc.insert(k);
		nc.insert((k+1)%n);
		k = pos[y]-1; 
		if(k<0) k+=n;
		nc.insert(k);
		nc.insert((k+1)%n);
		for(auto i : nc){
			add(dif[i],-1);
			dif[i] = arr[(i+1)%n]-arr[i];
			add(dif[i],1);
		}
		if((query(1)==n-1 && query(-(n-1))==1) || (query(-1)==n-1 && query(n-1)==1)) cout<<"DA\n";
		else cout<<"NE\n";
	}
	return 0;
}
