#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=0;
void f(int a,int b){
	if(!a || !b) return;
	if(a<b) swap(a,b);
	ans+=a/b;
	f(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	f(n,m);
	cout<<ans<<"\n";	
	return 0;
}
