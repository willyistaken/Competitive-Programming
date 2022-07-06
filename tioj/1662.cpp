#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char f(char c){
	if('a'<=c && c<='z') return (c-32);
	if('A'<=c && c<='Z') return (c+32);
	return ' ';
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	while(getline(cin,s)){
		for(auto i : s){
			cout<<f(i);
		}
		cout<<"\n";
	}

	return 0;
}
