#include<bits/stdc++.h>
using namespace std;
//#include<bits/extc++.h>
//__gnu_pbds
vector<long long> x;
vector<int> rlim[20];
vector<int> llim[20];
int n;
long long ans = 0;

int getmax(int l,int r){
	int len = (r-l+1);
	len = __lg(len);
	return max(rlim[len][l],rlim[len][r-(1<<(len))+1]);
}
int getmin(int l,int r){
	int len = (r-l+1);
	len = __lg(len);
	return min(llim[len][l],llim[len][r-(1<<len)+1]);
}

void solve(){
	int a;cin>>a;	
//	cout<<a<<endl;
	int k = lower_bound(x.begin(),x.end(),a)-x.begin();
	if(abs(x[k-1]-a)<=abs(x[k]-a)) k--;
	ans=abs(x[k]-a);
	int cur = k;
	int l = k;int r = k;
	while(l!=1 || r!=n){
		//cout<<ans<<"\n";
		//cout<<l<<" "<<r<<"\n";
		if(abs(x[l-1]-x[cur])<=abs(x[r+1]-x[cur])){
			ans+=abs(x[l-1]-x[cur]);
			cur = l-1;
			int rr = l;
			int ll = 1;
			while(rr-ll>1){
				int mid = (rr+ll)/2;
				if(getmax(mid,l-1)>=r) ll = mid;
				else rr = mid;
			}
			ans+=abs(x[ll]-x[cur]);
			l = ll;
			cur = l;
		}else{
			ans+=abs(x[r+1]-x[cur]);		
			cur = r+1;
			int rr = n;
			int ll = r;
			while(rr-ll>1){
				int mid = (rr+ll)/2;
				if(getmin(r+1,mid)<=l) rr = mid;
				else ll = mid;
			}
			ans+=abs(x[rr]-x[cur]);
			r = rr;
			cur = r;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;	
	x.resize(n+2);
	for(int p=0;p<20;p++){
		rlim[p].resize(n+2);
		llim[p].resize(n+2);
	}
	x[0]=-1e15;
	x[n+1]=1e15; 
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		int l = i;int r = n+1;	
		while(r-l>1){
			int mid = (l+r)/2;
			if(abs(x[i]-x[i-1])>abs(x[mid]-x[i])) l = mid;
			else r = mid;
		}
		rlim[0][i]=l;
	}
	for(int i=1;i<=n;i++){
		int r = i;int l = 0;
		while(r-l>1){
			int mid = (l+r)/2;
			if(abs(x[i]-x[i+1])>=abs(x[mid]-x[i]))  r = mid;
			else l = mid;
		}
		llim[0][i]=r;
	}
	for(int p=1;p<20;p++){
		for(int i=1;i+(1<<(p-1))<=n;i++){
			rlim[p][i] = max(rlim[p-1][i],rlim[p-1][i+(1<<(p-1))]);
			llim[p][i] = min(llim[p-1][i],llim[p-1][i+(1<<(p-1))]);
		}
	}
	int q;cin>>q;
	while(q--){
		solve();
	}
	return 0;
}
