#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct stuff{
	bool type=0;
	map<string,int> s;
};

bool is_big(char a){
	return (a-'A'>=0 && a-'A'<26);
}

bool is_num(char a){
	return (a-'0'>=0 && a-'0'<10);
}

int main(){
	stack<stuff> stk;
	string s;cin>>s;
	int cur = 0;
	string curs;
	for(int i=0;i<s.size();i++){
		if(is_num(s[i])){
			if(curs.size()){
				stuff g;
				g.s[curs]+=1;
				stk.push(g);
				curs.clear();
			}
			cur*=10;
			cur+=s[i]-'0';
		}else if(is_big(s[i])){
			if(cur){
				for(auto &i : stk.top().s){
					i.second*=cur;
				}
				cur=0;
			}
			if(curs.size()){
				stuff g;
				g.s[curs]+=1;
				stk.push(g);
				curs.clear();
			}
			curs.push_back(s[i]);
		}else if(s[i]=='('){
			if(cur){
				for(auto &i : stk.top().s){
					i.second*=cur;
				}
				cur=0;
			}
			if(curs.size()){
				stuff g;
				g.s[curs]+=1;
				stk.push(g);
				curs.clear();
			}
			stuff p;
			p.type=1;
			stk.push(p);
		}else if(s[i]==')'){
			if(cur){
				for(auto &i : stk.top().s){
					i.second*=cur;
				}
				cur=0;
			}
			if(curs.size()){
				stuff g;
				g.s[curs]+=1;
				stk.push(g);
				curs.clear();
			}
			stuff ne;
			while(stk.size() && !stk.top().type){
				for(auto i : stk.top().s){
					ne.s[i.first]+=i.second;
				}
				stk.pop();
			}
			if(stk.size()) stk.pop();
			stk.push(ne);
		}else{
			curs.push_back(s[i]);
		}
	}

			if(cur){
				for(auto &i : stk.top().s){
					i.second*=cur;
				}
				cur=0;
			}
			if(curs.size()){
				stuff g;
				g.s[curs]+=1;
				stk.push(g);
				curs.clear();
			}
	map<string,int> ans;
	while(stk.size()){
		for(auto i : stk.top().s){
			ans[i.first]+=i.second;
		}
		stk.pop();
	}
	cout<<s<<"\n";
	for(auto i : ans){
		cout<<i.first<<":"<<i.second<<"\n";
	}
	return 0;
}
