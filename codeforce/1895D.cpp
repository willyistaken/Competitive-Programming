#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n]={0};
	int x = 0;
	for(int i=1;i<n;i++){
		cin>>arr[i];
		arr[i]^=arr[i-1];
		x^=arr[i];
	}
	int y = 0;		
	for(int i=0;i<n;i++) y^=i;
	if(n&1)	y^=x;
	else{
				
	}
	return 0;
}
