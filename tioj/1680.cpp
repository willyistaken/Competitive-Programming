#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> ans;
vector<int> arr;
int n,m;
int convert(int ind){
	if(ind==m) return arr[m];
	int prev = convert(ind+1);	
	if(prev>=arr[ind]) ans.push_back(1);
	else ans.push_back(0);
	return abs(arr[ind]-arr[ind+1]);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<bool> ref(m,0);
	for(int i=0;i<m;i++){
		int k;cin>>k;
		ref[m-i-1]=k;
	}
	for(int i=0;i<n;i++){
		ans.clear();
		arr.clear();
		for(int i=0;i<=m;i++){
			int k;cin>>k;
			arr.push_back(k);
		}
		convert(0);
		if(ans==ref){
			for(auto i : arr) cout<<i<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
