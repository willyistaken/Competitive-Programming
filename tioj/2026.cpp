#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


priority_queue<int> smallerq;
priority_queue<int,vector<int>,greater<int> > biggerq;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int q;cin>>q;
	int type;
	int k;
	cin>>type>>k;q--;
	smallerq.push(k);
	while(q--){
		cin>>type;
		if(type==2){
			cout<<smallerq.top()<<"\n";
		}else{
			cin>>k;
			if(k>smallerq.top()) biggerq.push(k);
			else  smallerq.push(k);
			if(smallerq.size()>biggerq.size() && smallerq.size()-biggerq.size()>1) {
				biggerq.push(smallerq.top());
				smallerq.pop();
			}	
			if(biggerq.size()>smallerq.size()){
				smallerq.push(biggerq.top());
				biggerq.pop();
			}
		}
	}

	return 0;
}
