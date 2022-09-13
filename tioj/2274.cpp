#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int l,r,u,d;ll maxn = -1e15;
	for(int i=0;i<n;i++){
		int nowl=-1;
		ll now = -1e15;
		for(int j=0;j<m;j++){
			if(arr[i][j]+now<arr[i][j]){
				now = arr[i][j];
				nowl = j;
			}else{
				now+=arr[i][j];
			}
			if(now>maxn){
				maxn=now;
				u = i;d = i;
				r = j;
				l = nowl;
			}
		}
	}
	for(int j=0;j<m;j++){
		int nowu=-1;
		ll now = -1e15;
		for(int i=0;i<n;i++){
			if(arr[i][j]+now<arr[i][j]){
				now = arr[i][j];
				nowu = i;
			}else{
				now+=arr[i][j];
			}
			if(now>maxn){
				maxn=now;
				l = j;r = j;
				u = nowu;
				d = i;
			}
		}
	}
	cout<<maxn<<"\n";	
	for(int i=0;i<l;i++) cout<<"L";
	for(int i=0;i<m-r-1;i++) cout<<"R";
	for(int i=0;i<u;i++) cout<<"U";
	for(int i=0;i<n-d-1;i++) cout<<"D";
	if(l==r){
		cout<<"R\n";
	}else if(u==d){
		cout<<"U\n";
	} 
}
