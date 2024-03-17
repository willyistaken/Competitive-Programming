#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<vector<int> > Q(q,vector<int>(4,0));
	int cnt = 0;
	for(int i=0;i<q;i++){
		cin>>Q[i][0];
		cnt+=Q[i][0];
		for(int k=1;k<4-Q[i][0];k++) cin>>Q[i][k];
	}
	vector<int> a(cnt);
	bool k=0;
	for(int i=0;i<cnt;i++) cin>>a[i];
	for(int i=0;i<cnt;i++){
		int b;cin>>b;
		if(b!=a[i]){
			k=1;
		}
	}
	if(k){
		cout<<n<<" "<<q<<"\n";
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<"\n";
		for(int i=0;i<q;i++){
			for(int j=0;j<4-Q[i][0];j++) cout<<Q[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"------\n";
	}

	return 0;
}
