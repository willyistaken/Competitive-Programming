#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<int> normal(1<<n);
	vector<int> sum1(1<<n);
	vector<int> sum0(1<<n);
	string s;cin>>s;
	for(int i=0;i<(1<<n);i++){
		normal[i] = s[i]-'0';
		sum1[i]=normal[i];
		sum0[i]=normal[i];
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<(1<<n);i++){
			if((i>>j)&1) sum1[i]+=sum1[i^(1<<j)];
		}
	}
	for(int j=0;j<n;j++){
		for(int i=(1<<n)-1;i>=0;i--){
			if(!((i>>j)&1))	 sum0[i]+=sum0[i^(1<<j)];
		}
	}
	while(q--){
		string qs;cin>>qs;
		int cnt0=0;
		int cnt1=0;
		int cntq=0;
		for(int i=0;i<n;i++){
			cnt0+=(qs[i]=='0');
			cnt1+=(qs[i]=='1');
			cntq+=(qs[i]=='?');
		}
		if(cnt0<=cnt1 && cnt0<=cntq){
			int calc = 0;	
			vector<int> b;
			for(int i=0;i<n;i++){
				if(qs[i]=='1') calc+=(1<<(n-1-i));
				if(qs[i]=='0') b.push_back(i);
			}
			int ans = 0;
			for(int mask=0;mask<(1<<cnt0);mask++){
				int f = calc;	
				int cntbit=0;
				for(int i=0;i<cnt0;i++) if((mask>>i)&1){f+=(1<<(n-1-b[i]));cntbit++;}
				ans+=(((cntbit)&1)?(-1):(1))*sum0[f];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(cnt1<=cnt0 && cnt1<=cntq){
			int calc = 0;	
			vector<int> b;
			for(int i=0;i<n;i++){
				if(qs[i]=='?') calc+=(1<<(n-1-i));
				if(qs[i]=='1') b.push_back(i);
			}
			int ans = 0;
			for(int mask=0;mask<(1<<cnt1);mask++){
				int f = calc;	
				int cntbit=0;
				for(int i=0;i<cnt1;i++) if((mask>>i)&1){f+=(1<<(n-1-b[i]));cntbit++;}
				ans+=(((cnt1^cntbit)&1)?(-1):(1))*sum1[f];
			}
			cout<<ans<<"\n";
			continue;	
		}
		if(cntq<=cnt1 && cntq<=cnt0){
			int calc = 0;
			vector<int> b;
			for(int i=0;i<n;i++){
				if(qs[i]=='1') calc+=(1<<(n-1-i));
				if(qs[i]=='?') b.push_back(i);
			}
			int ans = 0;
			for(int mask=0;mask<(1<<cntq);mask++){
				int f = calc;	
				for(int i=0;i<cntq;i++) if((mask>>i)&1) f+=(1<<(n-1-b[i]));
				ans+=normal[f];
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
