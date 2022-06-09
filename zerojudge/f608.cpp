#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct cor{
	int x;
	int y;

};
int mps;
void change(int ind,int v,vector<int> &fenwick){
	while(ind<=mps){
		fenwick[ind]=max(fenwick[ind],v);
		ind+=(ind & -ind);	
	}

}

int query(int ind,vector<int> &fenwick){
	int maxn = -1e9;
	while(ind){
		maxn = max(maxn,fenwick[ind]);
		ind-=(ind & -ind);
	}
	return maxn;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	map<int,int> mp;
	cor arr[n];
	for(int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;

	sort(arr,arr+n,[](const cor &a,const cor &b){return a.y<b.y;});
	for(int i=0;i<n;i++){
		if(!mp.count(arr[i].y)){
			mp.insert({arr[i].y,mp.size()+1});
		}
	}
	sort(arr,arr+n,[](const cor &a,const cor &b){return (a.x<b.x || (a.x==b.x && a.y<b.y));});
	vector<int> fenwick(mp.size()+1,0);
	int maxn=0;
	mps = mp.size();
	for(int i=0;i<n;i++){
		int now = query(mp[arr[i].y],fenwick);
		maxn = max(maxn,now+1);
		change(mp[arr[i].y],now+1,fenwick);
	}

	cout<<maxn<<endl;
	


	return 0;
}
