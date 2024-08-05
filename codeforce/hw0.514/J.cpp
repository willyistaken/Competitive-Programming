#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,c;
	cin>>n>>m>>c;
	int S=0;
	int ac = 0;
	for(int i=1;i<=m;i++){
		int a;cin>>a;
		S+=a;
		if(i==c) ac=a;
	}
	if(S<n){
		cout<<-1<<"\n";
		return 0;
	}
	if(S-ac-n+1<0){
		cout<<1<<"\n";
		return 0;
	}
	double ret = 1.0;
	for(int i=1;i<=ac-1;i++){
		ret*=(double)(S-n-ac+1+i);
		ret/=(double)(S-ac+i);
	}
	cout<<setprecision(8)<<fixed<<(1.0-ret)<<"\n";


	return 0;
}
