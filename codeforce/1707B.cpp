#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		deque<int> arr;
		int n;cin>>n;
		for(int i=0;i<n;i++) {
			int a;cin>>a;
			arr.push_back(a);
		}
		sort(arr.begin(),arr.end());
		int flag=0;
		while(arr.size()>1){
			int g=arr.size();
			for(int j=0; j<g-1 ;j++){
			//	cout<<j<<" "<<arr[1]<<" "<<arr[0]<<"\n";
				if(arr[1]-arr[0]){
					arr.push_back(arr[1]-arr[0]);
				}else flag+=1;
				arr.pop_front();
			}
			arr.pop_front();
			if(flag){
				arr.push_back(0);
				flag--;
			}
			sort(arr.begin(),arr.end());
		}
		cout<<arr[0]<<"\n";
	}

	return 0;
}
