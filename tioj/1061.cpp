#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

struct re{
	int owin=0;
	int xwin=0;
	int tie=0;
	void print(){
		cout<<owin+xwin+tie<<" "<<owin<<" "<<xwin<<" "<<tie<<"\n";
	}
};


char check(string b){
	if(b[0]==b[1] && b[1]==b[2] && b[0]!='-')  return b[0];
	if(b[3]==b[4] && b[4]==b[5] && b[3]!='-') return b[3];
	if(b[6]==b[7] && b[7]==b[8] && b[6]!='-') return b[6];
	if(b[0]==b[3] && b[3]==b[6] && b[0]!='-') return b[0];
	if(b[1]==b[4] && b[4]==b[7] && b[1]!='-') return b[1];
	if(b[2]==b[5] && b[5]==b[8] && b[2]!='-') return b[2];
	if(b[0]==b[4] && b[4]==b[8] && b[0]!='-') return b[0];
	if(b[2]==b[4] && b[4]==b[6] && b[2]!='-') return b[2];
	return '-';
}

void formatprint(string k){
	for(int i=0;i<9;i++) cout<<k[i]<<" \n"[(i%3)==2];
}

int state(string b){
	// 0 no one win yet, O turn
	// 1 no one win yet, X turn
	// 2 owin
	// 3 xwin
	// 4 tie
	char a = check(b);
	if(a=='O') return 2;
	if(a=='X') return 3;
	int ocnt=0;int xcnt=0;
	for(int i=0;i<9;i++){
		if(b[i]=='O') ocnt++;
		if(b[i]=='X') xcnt++;
	}
	if(ocnt+xcnt==9) return 4;
	if(ocnt>xcnt) return 1;
	return 0;
}
set<string> all;
void dfs(string k){
	int s = state(k);
	if(s>=2){
		/*formatprint(k);
		cout<<"\n";
		*/
		all.insert(k);
		return ;
	}
	
	if(s==0){
		for(int i=0;i<9;i++){
			if(k[i]=='-'){
				string next = k;
				next[i]='O';
				dfs(next);
			}
		}
	}else{
		for(int i=0;i<9;i++){
			if(k[i]=='-'){
				string next = k;
				next[i]='X';
				dfs(next);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string g;cin>>g;
	dfs(g);
	int owin=0;int xwin=0;int tie=0;
	
	for(auto i :all){
		int st = state(i);
		if(st==2) owin++;
		if(st==3) xwin++;
		if(st==4) tie++;
	}
	cout<<owin+xwin+tie<<" "<<owin<<" "<<xwin<<" "<<tie<<"\n";


	return 0;
}
