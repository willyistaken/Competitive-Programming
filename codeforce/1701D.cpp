#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
	int n;cin>>n;
	pair<int,int> pos[n];
	for(int i=0;i<n;i++){
		int k;cin>>k;
		if(k==0){
			pos[i]={i+2,n};	
		}else{
			pos[i]={((i+1)/(k+1))+1,(i+1/k)};
		}
		cout<<pos[i].first<<" "<<pos[i].second<<"\n";
	}
	}
	return 0;
}
