#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int t;cin >> t;
	cin.ignore();
	string s;
	while(t--){
		
		getline(cin,s);
		if(s=="1"){
			cout<<0<<"\n";
			continue;
		}
		double ans = (s.size()-1)*log2(10);
		double front=0;
		double power=1;
		for(int i=0;i<min((int)s.size(),18);i++){
				front+=(s[i]-'0')*power;
				power*=0.1;
		}
		ans += log2(front);
		cout<<fixed<<setprecision(0)<<floor(ans)<<"\n";
		/*
		ll n;
		cin>>n;
		cout<<__lg(n)<<"\n";
		*/	
	}
}
