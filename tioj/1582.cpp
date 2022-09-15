#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

map<int,int> poly;
string s;
int t;
int getint(){
	int flag=0;
	if(s[t]=='-') flag=1;
	if(flag || s[t]=='+') t++;
	if(s[t]=='x') return flag?(-1):(1);
	int ans=0;
	while(s[t]!='x' && t<s.size() && s[t]!='+' && s[t]!='-'){
			ans*=10;
			ans+=s[t]-'0';
			t++;
	}
	if(flag) ans=-ans;
	//cout<<ans<<"int\n";
	return ans;
}
bool getterm(){
	if(t>=s.size()-1) return false;
	int coeff = getint();
	if(t>=s.size()) return 0;
	if(s[t]=='+'||s[t]=='-'){
		poly.insert({0,coeff});
		return 1;
	}
	t++;
	int pow = 1;
	if(s[t]!='^'){
		pow=1;
	}else{
		t++;
		pow = getint();
	}
	poly.insert({pow,coeff});
	//cout<<pow<<" "<<coeff<<"term\n";
	return 1;
}





int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	getline(cin,s);
	while(getterm()){
			
	}
	/*for(auto i =poly.rbegin();i!=poly.rend();i++){
		cout<<i->first<<" "<<i->second<<"\n";

	}*/
	if(poly.size()==0){
		cout<<0;
	}
	for(auto i =poly.rbegin();i!=poly.rend();i++){
		if(i->first==0) continue;
		if(i->first==1){
			if(i->second>0 && i!=poly.rbegin()) cout<<'+';
			cout<<i->second;
		}else if(i->first==2){
			if((i->second*i->first)>0 && i!=poly.rbegin()) cout<<'+';
			cout<<i->second*i->first<<"x";
		}else{
			if((i->second*i->first)>0 && i!=poly.rbegin()) cout<<'+';
			cout<<i->second*i->first<<"x^"<<i->first-1;
		}
	}
	cout<<"\n";
	return 0;
}
