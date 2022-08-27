#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string n;
	while(cin>>n && n!="0"){
		string s,g;cin>>s>>g;
		cout<<s<<"\n";
	}

	return 0;
}

/*
suppose the og state is a loosing state , that means that every state the og state can go to is in the wining state, but consider the state with 2,3,4.....n , every staet that it can go to the og state can go to also, so if og state is loosing then 2,3,4...n is winning but if 2,3,4,5 is winning it means there is a loosing state that it can go to which means there is a loosing state the og state can go to , which means og state is a winning state.

*/
