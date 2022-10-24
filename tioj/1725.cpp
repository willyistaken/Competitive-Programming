#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void zalgo(vector<int> &z,string s){
	//cout<<s<<":\n";
	int n = s.size();
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r) z[i] = min(z[i-l],r-i+1);
		while(i+z[i]<n && s[z[i]]==s[z[i]+i]) z[i]++;
		if(i+z[i]-1>r) l = i,r = i+z[i]-1;
	//	cout<<z[i]<<" ";
	}
	//cerr<<"\n";
	return ;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	string a,b;cin>>a>>b;
	vector<int> z1,z2;
	z1.resize(3*n+1,0);
	z2.resize(3*n+1,0);
	zalgo(z1,(b+"#"+a+a));
	reverse(b.begin(),b.end());
	reverse(a.begin(),a.end());
	zalgo(z2,b+"#"+a+a);
	vector<int> ans;
	for(int i=n+1;i<2*n+1;i++){
		if(z1[i]+z2[3*n-i+2]+1==n) ans.push_back(i-n-1);
	}
	if(ans.size()){
		cout<<"TAK\n";
		for(auto i : ans) cout<<i<<' ';
		cout<<"\n";
	}else{
		cout<<"NIE\n";
	}
	return 0;
}
