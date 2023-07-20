#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	vector<bool> arr(n);
	for(int i=0;i<n;i++) arr[i] = (s[i]=='R');
	bool plate=1;
	int cnt = 0;
	for(int i=0;i<n;i++){
		plate^=1;
		if(arr[i]!=plate){
			cnt++;
		}
		plate = arr[i];
	}
	cout<<max(0,m-cnt)<<"\n";
	return 0;
}
