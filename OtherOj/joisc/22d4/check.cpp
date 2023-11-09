#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ifstream in;
	in.open("testcase.in");
	int n;in>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) in>>arr[i];
	int q;in>>q;
	vector<vector<int>> qu(q,vector<int>(3,0));
	int cnt=0;
	for(int i=0;i<q;i++){
		in>>qu[i][0]>>qu[i][1]>>qu[i][2];
		if(qu[i][0]==2) cnt++;
	}
	vector<int> f(cnt);
	for(int i=0;i<cnt;i++) cin>>f[i];
	bool works=1;
	for(int i=0;i<cnt;i++){
		int a;cin>>a;
		if(f[i]!=a) works=0;
	}
	if(works==0){
		cout<<"oh no...\n";
		cout<<n<<"\n";
		for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<"\n";
		cout<<q<<"\n";
		for(int i=0;i<q;i++){
			cout<<qu[i][0]<<qu[i][1]<<qu[i][2]<<"\n";
		}
	}
	return 0;
}
