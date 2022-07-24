#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		bool arr[m]={0};
		for(int i=0;i<n;i++){
			int k;cin>>k;
			if(arr[k-1]==0 && arr[m-k]==0) arr[min(k-1,m-k)]=1;
			else{
				if(arr[k-1]==1) arr[m-k]=1;
				else arr[k-1]=1;
			}
		}
		for(int i=0;i<m;i++){
			cout<<(arr[i]?'A':'B');
		}
		cout<<"\n";
	}

	return 0;
}
