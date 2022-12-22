#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




double arr[601];
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	arr[0]=1.0;
	for(int i=1;i<=n;i++){
		for(int j=600;j>=0;j--){
			arr[j] = 0;
			for(int k=1;k<=6 && j-k>=0;k++){
				arr[j] +=arr[j-k];
			}
			arr[j] = arr[j]/6.0;
		}
	}
	int a,b;cin>>a>>b;
	double ans = 0;
	for(int i=a;i<=b;i++) ans+=arr[i];
	cout<<fixed<<setprecision(6)<<ans<<"\n";
	return 0;
}
