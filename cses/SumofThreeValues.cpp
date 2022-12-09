#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int a;cin>>a;
	pair<int,int> arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i].first;
		arr[i].second = i;
	}
	sort(arr,arr+n);
	map<int,int> s;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int sum = arr[i].first+arr[j].first;
			if(s.count(a-sum)){
				cout<<s[a-sum]+1<<" "<<arr[i].second+1<<" "<<arr[j].second+1<<"\n";
				return 0;
			}
		}
		s.insert({arr[i].first,arr[i].second});
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}
