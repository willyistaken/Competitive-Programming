#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cur;cin>>cur;
	unordered_map<int,int> s;
	s[cur]=1;
	cout<<"1 "<<cur<<endl;
	int n;
	while(cin>>n && n){
		s[n]++;
		if(s[cur]<s[n] || (s[cur]==s[n]&&cur>n)) cur = n;
		cout<<s[cur]<<" "<<cur<<endl;
	}

	return 0;
}
