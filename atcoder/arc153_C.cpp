#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n+1];
	ll sum = 0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum+=arr[i]*i;
	}
	if(sum>0){
		int k = 0;
		for(int f=n;f>0;f--){
			k+=arr[f];
			if(k==-1){
				cout<<"Yes\n";
				for(int i=1;i<f;i++){
					cout<<i<<" ";
				}
				for(int i=f;i<=n;i++){
					cout<<i+sum<<" ";
				}
				cout<<"\n";
				return 0;
			}
		}
		k = 0;
		for(int f=1;f<=n;f++){
			k+=arr[f];
			if(k==1){
				cout<<"Yes\n";
				for(int i=1;i<=f;i++){
					cout<<i-sum<<" ";
				}
				for(int i=f+1;i<=n;i++){
					cout<<i<<" ";
				}
				cout<<"\n";
				return 0;
			}
		}
	}else if(sum<0){
		int k = 0;
		for(int f=n;f>0;f--){
			k+=arr[f];
			if(k==1){
				cout<<"Yes\n";
				for(int i=1;i<f;i++){
					cout<<i<<" ";
				}
				for(int i=f;i<=n;i++){
					cout<<i-sum<<" ";
				}
				cout<<"\n";
				return 0;
			}
		}
		k = 0;
		for(int f=1;f<=n;f++){
			k+=arr[f];
			if(k==-1){
				cout<<"Yes\n";
				for(int i=1;i<=f;i++){
					cout<<i+sum<<" ";
				}
				for(int i=f+1;i<=n;i++){
					cout<<i<<" ";
				}
				cout<<"\n";
				return 0;
			}
		}
	}else{
		cout<<"Yes\n";
		for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<"\n";
		return 0;
	}
	cout<<"No\n";
	return 0;

}
