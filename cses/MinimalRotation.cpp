#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<pair<int,int> > fac(string s){
	int n  =s.size();
	vector<pair<int,int> > ans;
	for(int i=0;i<n;){
		int j = i+1;int k = i;
		while(j<n && s[j]>=s[k]){
			if(s[j]==s[k]){
				k++;
			}else{
				k = i;
			}
			j++;
		}
		while(i<=k){
			ans.push_back({i,i+j-k-1});
			i+=j-k;
		}
	}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;cin>>s;	
	int n = s.size();
	vector<pair<int,int> > arr = fac(s+s);
	for(auto i : arr){
		if(i.first<n && i.second>=n){
			for(int j=i.first;j<n;j++) cout<<s[j];
			for(int j=0;j<i.first;j++) cout<<s[j];
			cout<<"\n";
			return 0;
		}
	}
	cout<<s<<"\n";
	return 0;
}
