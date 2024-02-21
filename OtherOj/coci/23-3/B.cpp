#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e5+5;

struct T{
	int x;
	int t;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<T> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].x>>arr[i].t;
		int a;cin>>a;
	}
	sort(arr.begin(),arr.end(),[](const T &a,const T &b){return a.x<b.x;});
	vector<int> ans(m);
	vector<int> X(m);
	vector<int> ord;
	vector<int> maxn(n);
	vector<bool> onleft(n);
	for(int i=0;i<m;i++) cin>>X[i];
	for(int i=0;i<m;i++) ord.push_back(i);
	for(int i=0;i<n;i++) maxn[i]=i;
	sort(maxn.begin(),maxn.end(),[&](const int &a,const int &b){return arr[a].t-arr[a].x>arr[b].t-arr[b].x;});
	int lmax = -1e9;	
	sort(ord.begin(),ord.end(),[&](const int &a,const int &b){return X[a]<X[b];});
	int head = 0;
	int head2=0;
	for(int i=0;i<m;i++){
		int k = ord[i];
		while(head<n && arr[head].x<=X[k] ){
			onleft[head]=1;
			lmax = max(lmax,arr[head].t+arr[head].x);
			head++;
		}
		while(head2<n && onleft[maxn[head2]]) head2++;
		ans[k] = max(0,lmax-X[k]);
		if(head2<n) ans[k] = max(ans[k],arr[maxn[head2]].t-arr[maxn[head2]].x+X[k]);
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
