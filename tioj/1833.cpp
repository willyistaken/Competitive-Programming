#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
const int MAXN = 1e5+5;
int father[MAXN];

int query(int a){
	if(father[a]==a) return a;
	father[a] = query(father[a]);
	return father[a];
}

void join(int a,int b){
	father[query(b)] = query(a);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++) father[i]=i;
	while(q--){
		string s;cin>>s;
		if(s[0]=='M'){
			int a,b;cin>>a>>b;
			join(a,b);
		}else{
			int x;cin>>x;
			cout<<query(x)<<"\n";
		}
	}
	return 0;
}
