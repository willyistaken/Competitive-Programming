#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<int> man(string s){
	vector<int> d(s.size(),1);
	int n = s.size();
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r) d[i]= min(d[l+r-i],r-i);
		while(i-d[i]>=0 && i+d[i]<n && s[i-d[i]]==s[i+d[i]]) d[i]++;
		if(i+d[i]>r) l = i-d[i],r= i+d[i];
	}
	return d;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;	
	string sp;
	for(auto i : s){
		sp+=i;
		sp+='#';
	}
	vector<int> d = man(sp)	;
	int maxn = 0;int maxi = -1;
	for(int i=0;i<sp.size();i++){
		int l = 0;
		//cout<<i<<" "<<d[i]<<"\n";
		if(i&1){
			if(d[i]&1){
				l = (d[i]-1);
			}else{
				l = d[i];
			}
		}else{
			if(d[i]&1){
				l = 2*((d[i]+1)/2)-1;
			}else{
				l = d[i]-1;	
			}
		}
		if(maxn<l){
			//cout<<i<<" "<<l<<"max\n";
			maxn = l;
			maxi = i;
		}
	}
	if(maxi&1){
		int b = (maxi/2)-((maxn/2)-1);
		for(int i=b;i<b+maxn;i++) cout<<s[i];
		cout<<"\n";
		return 0;
	}else{
		int b = (maxi/2)-(maxn/2);
		for(int i=b;i<b+maxn;i++) cout<<s[i];
		cout<<"\n";
		return 0;
	}
	return 0;
}
