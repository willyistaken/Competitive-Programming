#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	vector<string> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j = i+1;j<n;j++){
			string f = "";
			for(int m=0;m<k;m++){
				if(arr[i][m]!=arr[j][m]) f.push_back(char('0'+(6-arr[i][m]-arr[j][m]+2*'0')));
				else f.push_back(arr[i][m]);
			}
			int k = lower_bound(arr.begin(),arr.end(),f)-arr.begin();
			if(k>j && arr[k]==f) cnt++;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}
