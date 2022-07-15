#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		string a;cin>>a;
		string b;cin>>b;
		if(a[0]!=b[0] || a[n-1]!=b[n-1]){
			cout<<-1<<"\n";
			continue;
		}
		if(a[0]=='1'){
			for(int i=0;i<n;i++){
				a[i] = '0'+(a[i]=='0');
				b[i] = '0'+(b[i]=='0');
			}
		}
		int difa[n]={0};
		int difb[n]={0};
		vector<int> oosa;
		vector<int> oosb;
		vector<int> loca;
		vector<int> locb;
		for(int i=1;i<n;i++){
			difa[i] = a[i]-a[i-1];
			difb[i] = b[i]-b[i-1];
			if(difa[i]){
				oosa.push_back(difa[i]);
				loca.push_back(i);
			}
			if(difb[i]){
				oosb.push_back(difb[i]);
				locb.push_back(i);
			}

		}
		if(oosa!=oosb) {
			cout<<-1<<"\n";
			continue;
		}
		ll ans=0;
		for(int i=0;i<loca.size();i++){
			ans+=abs(loca[i]-locb[i]);
		}
		cout<<ans<<"\n";
	}

	return 0;
}
