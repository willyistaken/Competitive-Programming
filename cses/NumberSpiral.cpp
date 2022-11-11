#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int y,x;cin>>y>>x;	
	int layer = max(x,y);
	if(layer%2){
		if(x>y){	
			ll num = 1LL*layer*layer;
			num-=y;
			num++;
			cout<<num<<"\n";
			return ;
		}else{
			ll num = 1LL*(layer-1)*(layer-1)+1;
			num+=x;
			num-=1;
			cout<<num<<"\n";
			return ;
		}
	}else{
		if(x>y){
			ll num = 1LL*(layer-1)*(layer-1)+1;
			num+=y;
			num--;
			cout<<num<<"\n";
		}else{
			ll num = 1LL*layer*layer;
			num-=x;
			num++;
			cout<<num<<"\n";
		}
	}
	
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--) solve();

	return 0;
}
