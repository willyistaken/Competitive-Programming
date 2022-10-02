#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


bool comp(string a,string b){
	if(a.size()!=b.size()){
		return a.size()<b.size();
	}
	return a<b;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		string arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			reverse(arr[i].begin(),arr[i].end());
		}
		int ans = arr[0].size();
		sort(arr,arr+n,comp);
		for(int i=0;i<n-1;i++){
			if(arr[i].size()!=arr[i+1].size()){
				ans = min((int)arr[i].size(),ans);
			}else{
				int re=0;
				for(int k=0;k<arr[i].size();k++){
					if(arr[i][k]==arr[i+1][k]){
						re++;
					}else{
						break;
					}
				}
				ans = min(ans,(int)arr[i].size()-re);
			}
		}
		cout<<ans-1<<"\n";	
	}
	return 0;
}
