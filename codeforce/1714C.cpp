#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void find(int k){
	vector<int> s;
	for(int i=9;i>=1;i--){
		if(k>=i) {
			k-=i;
			s.push_back(i);
		}
	}
	for(int i=s.size()-1;i>=0;i--) cout<<s[i];
	cout<<"\n";
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int a;cin>>a;
		find(a);
	}

	return 0;
}
