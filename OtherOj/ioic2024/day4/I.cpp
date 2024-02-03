#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> get(int k){
	vector<int> arr(k);
	if(k==1){
		arr[0]=1;
		return arr;
	}
	if(k==2){
		arr[0]=3;
		arr[1]=4;
		return arr;
	}
	if(k&1){
		int n = (k+1)/2;
		arr[0]=n;
		arr[1]=2;
		for(int i=2;i<k;i++) arr[i]=1;
		return arr;
	}else{
		int n = (k-2)/2;	
		arr[0]=n;
		for(int i=1;i<k;i++) arr[i]=1;
		return arr;
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	vector<int> a = get(n);
	vector<int> b = get(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i]*b[j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
