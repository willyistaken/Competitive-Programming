#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> a;
int check(int l,int r,int k){
	if(l==r) return 0;
	int prev = l;		
	int ans = 0;
	for(int i=l+1;i<r;i++){
		if(a[i]!=a[i-1]){
			if(a[prev]==k){
				if((i-prev)%2) return -1;
				ans+=(i-prev)/2;
			}
			prev = i;
		}
	}
	if(a[prev]==k){
		if((r-prev)%2) return -1;
		ans+=(r-prev)/2;	
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int minn = 1e9;	
	for(int i=0;i<=n;i++){
		int a = check(0,i,1);
		int b = check(i,n,-1);
		if(a!=-1 && b!=-1) minn = min(minn,a+b);
	}
	if(minn>n){
		cout<<-1<<"\n";
	}else{
		cout<<minn<<"\n";
	}
	return 0;
}
