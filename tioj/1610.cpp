#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int w[n];
	int l[n];
	for(int i=0;i<n;i++) cin>>w[i];
	for(int i=0;i<n-1;i++) cin>>l[i];
	l[n-1]=0;
	sort(w,w+n,greater<int>());
	sort(l,l+n);
	ll ans=0;
	for(int i=0;i<n;i++){
		if(i) l[i] = l[i-1]+l[i];
		ans+=1LL*w[i]*l[i];	
	}
	cout<<ans<<"\n";
	return 0;
}


/* property:

C = sum(suml[i]*w[i])

and we need to min c

if sum[i] is bigger, w[i] must be smaller 

so sort sum[i] and w[i] and add them up;

sort sum[i] is the same as sum after sort l[i] 

*/
