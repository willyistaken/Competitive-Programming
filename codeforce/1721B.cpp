#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		bool touch[4]={0};
		int sx,sy,d;cin>>sx>>sy>>d;
		if(sy-1<=d) touch[0]=1;
		if(n-sx<=d) touch[1]=1;
		if(m-sy<=d) touch[2]=1;
		if(sx-1<=d) touch[3]=1;
		if((touch[1]&&touch[2]) || (touch[0]&&touch[3]) || (touch[1]&&touch[3])||(touch[0]&&touch[2])) cout<<-1<<"\n";
		else cout<<(n-1)+(m-1)<<"\n";
	}

	return 0;
}
