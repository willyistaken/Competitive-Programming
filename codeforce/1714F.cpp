#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void solve(){
	int n,d12,d23,d31;cin>>n>>d12>>d23>>d31;
	int ar[4] = {0,1,2,3};
	if(d23<=d12 && d23<=d31){
		swap(ar[3],ar[1]);
		swap(d23,d12);
	}else if(d31<=d12 && d31<=d23){
		swap(ar[2],ar[3]);
		swap(d31,d12);
	}
	for(int dis1=0;dis1<=d12;dis1++){
		int a = dis1;
		int b = d12-dis1;
		if(d31-a==d23-b && d31-a>0 && a+b+d31-a<=n-1){
			cout<<"YES\n";
			int t = 3;		
			if(d12==1){
				cout<<ar[1]<<" "<<ar[2]<<"\n";
			}else{
			cout<<ar[1]<<" "<<++t<<"\n";
			for(int i=0;i<d12-2;i++){
				cout<<t<<" "<<++t<<"\n";
			}
			cout<<t<<" "<<ar[2]<<"\n";
			}
			int g = 4+a-1;		
			if(a==0) g = ar[1];
			else if(a==d12) g=ar[2];
			int len = d31-a;
			if(len==1) cout<<g<<" "<<ar[3]<<"\n";
			else{
				cout<<g<<" "<<++t<<"\n";
				for(int i=0;i<len-2;i++){
					cout<<t<<" "<<++t<<"\n";
				}
				cout<<t<<" "<<ar[3]<<"\n";
			}
			++t;
			for(;t<=n;t++){
				cout<<ar[1]<<" "<<t<<"\n";
			}
			return ;
		}
	}
	cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}
