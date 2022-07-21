#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int qt = 0;
		int r = 0;
		int l = 0;
		for(auto i : s){
			if(i=='?') qt++;
			if(i==')') r++;
			if(i=='(') l++;
		}
		
		int a = (qt+(l-r))/2;
		int b = (qt-(l-r))/2;

		int level=0;
		bool flag=0;
		for(auto i : s){
			if(i=='(') level++;
			if(i==')') level--;
			if(i=='?'){
				if(b){
					b--;
					level++;
				}else{
					a--;
					level--;
				}
			}
			if(!b  && a==((qt+(l-r))/2) && level<=1){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}

	return 0;
}
