#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	while(cin>>n && n){
		priority_queue<int> pq;
		for(int i=0;i<n;i++){
			int a;cin>>a;
			pq.push(a);
		}
		bool pass=1;
		while(!pq.empty() && pass){
			int top = pq.top();
			pq.pop();
			vector<int> work;
			while(top--){
				if(pq.empty()){pass=0;break;}
				int m = pq.top();
				pq.pop();
				m--;
				if(m<0){ pass=0;break;}
				work.push_back(m);
			}
			for(auto i : work) pq.push(i);
		}
		if(pass){
			cout<<"yes\n";
		}else{
			cout<<"no\n";
		}
	}

	return 0;
}
