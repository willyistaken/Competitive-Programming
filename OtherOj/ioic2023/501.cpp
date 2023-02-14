#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int MOD = 998244353;
int type[20];
int n,k;
int op(int a,int b){
	int ans=  0;	
	for(int i=0;i<k;i++){
			bool t = (a>>i)&1;
			bool p = (b>>i)&1;
			if(type[i]==0) t = t&p;
			if(type[i]==1) t = t|p;
			if(type[i]==2) t = t^p;
			if(type[i]==3) t = ~(t&p);
			if(type[i]==4) t = ~(t|p);
			if(type[i]==5) t = ~(t^p);
			if(t) ans+=(1<<i);
	}
	return ans;
}

void tf(vector<int> &arr,bool type){
	for(int k=0;k<n;k<<=1){
		for(int i=0;i<n;i+=2*k){
			for(int j=0;j<k;j++){
				arr[i+j+k];
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;	
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<k;i++) cin>>type[k];
	tf(a,1);tf(b,1);
	for(int i=0;i<n;i++){
		a[i]=(1LL*a[i]*b[i])%MOD;
	}
	tf(a,0);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}
