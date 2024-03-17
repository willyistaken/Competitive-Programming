#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int get(int x,int y){
	if(x==1 && y==1) return 0;
	int m = max(x,y);
	m--;
	int k = __lg(m);
	k = (1<<k);
	int a=0;
	if(x>k && y>k){
		a=get(x-k,y-k);
	}else if(x>k){
		a=get(x-k,y);
	}else{
		a=get(x,y-k);
	}
	if(a==__lg(k)) return a+1;
	else return a;
}

void solve(){
	int n;cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		ans^=get(x,y);
	}
	if(ans) cout<<"Erste\n";
	else cout<<"Zweite\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
				
