#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	int x[n]={0},y[m]={0};
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int k;cin>>k;
			x[i]+=k;y[j]+=k;
			sum+=k;
		}
	}
	sum=(sum+1)>>1;
	int xsum=0;
	for(int i=0;i<n;i++){
		if(xsum+x[i]<sum){
			xsum+=x[i];
		}else{
			cout<<i+1<<" ";
			break;
		}
	}
	int ysum=0;
	for(int i=0;i<m;i++){
		if(ysum+y[i]<sum){
			ysum+=y[i];
		}else{
			cout<<i+1<<"\n";
			break;
		}
	}
	return 0;
}
