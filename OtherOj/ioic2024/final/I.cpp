#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 2e5+5;
int lpos[N][20];
int cnt[3];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int q;cin>>q;
	string s;cin>>s;		
	s = " "+s;
	int head = 1;
	for(int i=0;i<20;i++){
		lpos[n+1][i] = -1;
	}
	for(int i=1;i<=n;i++){
		while(((!cnt[0]) || !cnt[1] || !cnt[2]) && head<=n){
			cnt[s[head++]-'a']++;
		}
		if(!(!cnt[0] || !cnt[1] || !cnt[2])) lpos[i][0]=head;
		else lpos[i][0]=-1;
		cnt[s[i]-'a']--;
	}
	for(int j=1;j<20;j++){ 
		for(int i=1;i<=n;i++)	{
			if(lpos[i][j-1]==-1) lpos[i][j]=-1;
			else lpos[i][j] = lpos[lpos[i][j-1]][j-1];
		}
	}
	while(q--){
		int t;cin>>t;
		if(t==1) return 0;
		int l,r;cin>>l>>r;
		ll ans = 0;
		for(int p=19;p>=0;p--)	{
			if(lpos[l][p]!=-1 && lpos[l][p]-1<=r){
				l = lpos[l][p];
				ans+=(1<<p);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
