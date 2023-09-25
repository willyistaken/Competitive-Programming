#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
#define int ll



signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	ll total=0;
	int a;cin>>a;
	if(n==1){
		cout<<1<<"\n";
		return 0;
	}
	int f = a;
	int b=0;
	vector<int> t;
	for(int i=1;i<n;i++){
		cin>>b;
		t.push_back(b-a-1);
		a = b;
	}
	total = b-f+1;		
	sort(t.begin(),t.end(),greater<int>());
	for(int i=0;i<min(k-1,n-1);i++){
		total-=t[i]	;
	}
	cout<<total<<"\n";
	
	return 0;
}
