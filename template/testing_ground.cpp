#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n+1]={0};
	arr[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			arr[j] = arr[j]+arr[j-1];	
		}
		cout<<arr[i]<<"\n";
	}

	return 0;
}
