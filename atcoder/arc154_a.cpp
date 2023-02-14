#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



const int MOD =  998244353;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string A;
	string B;
	cin>>n;	
	cin>>A;
	cin>>B;
	for(int i=0;i<n;i++){
		if(A[i]-'0'>B[i]-'0') swap(A[i],B[i]);
	}
	ll a=0;
	ll b = 0;
	for(int i=0;i<n;i++){
		a = (a*10)%MOD;
		a = (a+A[i]-'0')%MOD;
		b = (b*10)%MOD;
		b = (b+B[i]-'0')%MOD;
	}
	cout<<(a*b)%MOD<<"\n";
	return 0;
}
