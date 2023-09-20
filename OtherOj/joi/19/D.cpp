#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int cnt[200005][2];


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll ans = 0;
	int n;cin>>n;
	for(int i=0;i<2*n;i++){
		int x,y;cin>>x>>y;	
		if(y>=2){
			if(x<1){
				cnt[1][1]+=1;
				ans+=abs(x-1)+abs(y-2);
			}else if(x>n){
				cnt[n][1]+=1;
				ans+=abs(x-n)+abs(y-2);
			}else{
				cnt[x][1]+=1;
				ans+=abs(y-2);
			}
		}else{
			if(x<1)	{
				cnt[1][0]+=1;
				ans+=abs(x-1)+abs(y-1);
			}else if(x>n){
				cnt[n][0]+=1;
				ans+=abs(x-n)+abs(y-1);
			}else{
				cnt[x][0]+=1;
				ans+=abs(y-1);
			}
		}
	}
	int d[2]={0,0};
	for(int x=1;x<=n;x++){
		d[0]+=cnt[x][0]-1;
		d[1]+=cnt[x][1]-1;
		if(d[0]>0 && d[1]<0){
			int g = min(d[0],-d[1]);
			ans+=g;
			d[0]-=g;d[1]+=g;
		}else if(d[0]<0 && d[1]>0){
			int g = min(-d[0],d[1]);
			ans+=g;
			d[0]+=g;d[1]-=g;
		}
		ans+=abs(d[0])+abs(d[1]);
	}
	cout<<ans<<"\n";
	return 0;
}
