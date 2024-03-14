#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int arr[8] = {1,2,3,5,8,13,21,55};
int sum[60];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<8;i++) sum[arr[i]]++;
	for(int i=1;i<60;i++) sum[i]+=sum[i-1];
	int l,r;cin>>l>>r;
	l = min(l-1,59);
	r = min(r,59);
	cout<<sum[r]-sum[l]<<"\n";
	return 0;
}
