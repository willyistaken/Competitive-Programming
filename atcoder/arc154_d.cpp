#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



int n;
int pos=1;

char ans[3];
bool comp(int a,int b){
	cout<<"? "<<a<<" "<<pos<<" "<<b<<endl;
	scanf("%s",ans);
	return (ans[0]=='N');
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		cout<<"? "<<i<<" "<<i<<" "<<pos<<endl;
		scanf("%s",ans);
		if(ans[0]=='N') pos = i;
	}
	int arr[n];
	for(int i=0;i<n;i++) arr[i]=i+1;
	stable_sort(arr,arr+n,comp);
	int out[n+1];
	for(int i=0;i<n;i++){
		out[arr[i]] = i+1;
	}
	cout<<"! ";	
	for(int i=1;i<n;i++){
		cout<<out[i]<<" ";
	}
	cout<<out[n]<<endl;
	return 0;
}
