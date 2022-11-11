#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int m;cin>>m;
	int pos[n+2];
	pos[0] = -1;
	pos[n+1] = 1e9;
	int num[n+1];
	for(int i=1;i<=n;i++){
		cin>>num[i];
		pos[num[i]]=i;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(pos[i]<pos[i-1]) ans++;
	}
	while(m--){
		int a,b;cin>>a>>b;
		int a1 = a;int b1 = b;
		a = num[a];b = num[b];
		swap(num[a1],num[b1]);
		if(a>b) swap(a,b);
		
		ans-=(pos[a]<pos[a-1]);
		ans-=(pos[a+1]<pos[a]);
		ans-=(pos[b]<pos[b-1]);
		ans-=(pos[b+1]<pos[b]);
		if(a+1==b && pos[a+1]<pos[a]) ans++;	
		swap(pos[a],pos[b]);
		ans+=(pos[a]<pos[a-1]);
		ans+=(pos[a+1]<pos[a]);
		ans+=(pos[b]<pos[b-1]);
		ans+=(pos[b+1]<pos[b]);
		if(a+1==b && pos[a+1]<pos[a]) ans--;	
		cout<<ans+1<<"\n";
	}
	return 0;
}
