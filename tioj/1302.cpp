#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


unordered_map<string,string> ntod;
unordered_map<string,string> dton;
int main(){
	string type;
	while(cin>>type){
		if(type[0]=='a'){
			string n;
			string d;
			cin>>n>>d;
			ntod.insert({n,d});
			dton.insert({d,n});
		}
		if(type[0]=='c'){
			string s;cin>>s;
			string b = s.substr(1,s.size()-1);
			if(s[0]=='n'){
				if(!ntod.count(b)){cout<<"Not found.\n";continue;}
				cout<<b<<" "<<ntod[b]<<"\n";
			}else{
				if(!dton.count(b)){cout<<"Not found.\n";continue;}
				cout<<dton[b]<<" "<<b<<"\n";
			}
		}
		if(type[0]=='d'){
			string s;cin>>s;
			string b = s.substr(1,s.size()-1);
			if(s[0]=='n'){
				dton.erase(ntod[b]);
				ntod.erase(b);
			}else{
				ntod.erase(dton[b]);
				dton.erase(b);
			}
		}
	}
	return 0;
}
