#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b;cin>>a>>b;
	queue<int> q;
	q.push(a);
	map<int,int> prev;
	while(q.size()){
		int cur = q.front();
		q.pop();
		if(cur==b){
			cout<<"YES"<<endl;	
			stack<int> s;
			while(cur!=a){
				s.push(cur);
				cur = prev[cur];
			}
			cout<<s.size()+1<<"\n";
			cout<<a<<" ";
			while(s.size()){
				cout<<s.top()<<" ";
				s.pop();
			}
			cout<<"\n";
			return 0;
		}
		if(2LL*cur<=b){
			q.push(2*cur);
			prev[2*cur]=cur;
		}
		if(10LL*cur+1<=b){
			q.push(10*cur+1);
			prev[10*cur+1]=cur;
		}
	}
	cout<<"NO\n";

	return 0;
}
