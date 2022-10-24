#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int arr[n];
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		if(sum%2) {
			cout<<-1<<"\n";
			continue;
		}
		if(sum==0){
			cout<<n<<"\n";
			for(int i=1;i<=n;i++) cout<<i<<" "<<i<<"\n";
			continue;
		}
			
			int t = (sum>0)?(1):(-1);
			sum = abs(sum);
			int k = sum;
			for(int i=0;i<n;i++){
				if(arr[i+1]==t) {
					arr[i] = 5;
					k-=2;
					i++;
				}
				if(k==0) break;
			}
			if(k){
				cout<<"-1\n";
				continue;
			}else{
				cout<<n-(sum/2)<<"\n";
				for(int i=0;i<n;){
					if(arr[i]!=5) {
						cout<<i+1<<" "<<i+1<<"\n";
						++i;
					}else{
						cout<<i+1<<" "<<(i+2)<<"\n";
						i+=2;
					}
				}
			}
	}

	return 0;
}
