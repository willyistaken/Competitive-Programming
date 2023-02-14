#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	n--;
	int arr[6]={0};
	arr[0]=1;	
	for(int i=0;i<6;i++){
		arr[5-i]+=n%10;
		n/=10;
	}
	cout<<arr[0]<<arr[0]<<arr[1]<<arr[2]<<arr[3]<<arr[3]<<arr[4]<<arr[5]<<arr[4]<<"\n";

	return 0;
}
