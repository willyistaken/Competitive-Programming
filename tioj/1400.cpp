#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	priority_queue<int> firstk;
	priority_queue<int,vector<int>,greater<int> > other;
	while(true){
		string s;cin>>s;
		if(s[1]=='N') return 0;
		if(s[1]=='X'){
			firstk = priority_queue<int>();
			other = priority_queue<int,vector<int>,greater<int> >();
		}
		if(s[1]=='U'){
			int g;cin>>g;
			if(firstk.empty()){
				other.push(g);	
			}else{
				if(g>=firstk.top())	{
					other.push(g);
				}else{
					firstk.push(g);
					other.push(firstk.top());
					firstk.pop();
				}
			}
		}
		if(s[1]=='E'){
			if(!other.empty()){
				cout<<other.top()<<"\n";
				firstk.push(other.top());
				other.pop();
			}
		}
	}

	return 0;
}


/* I use two pq and juggle the element between  two pq
this trick is also used in tioj 2026
which I am calling  pq juggling
*/
