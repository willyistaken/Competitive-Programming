#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	while(cin>>n>>k && n && k){
	priority_queue<int,vector<int>,greater<int>  > q;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		q.push(a);
		if(q.size()>k) q.pop();

	}
	cout<<q.top()<<endl;


	}
	






}
