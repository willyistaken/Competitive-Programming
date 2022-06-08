#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	int tc=1;
	int n;
	while(scanf("%d",&n) && n){
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		int temp;scanf("%d",&temp);
		pq.push(temp);	
	}
	bool yes=1;
	while(!pq.empty() && yes){
		int top = pq.top();
		pq.pop();
		queue<int> q;
		for(int i=0;i<top;i++){
			if(pq.empty()){
				yes=0;
				break;
			}
			if(pq.top()-1<0) {
				yes=0;
				break;
			}
			q.push(pq.top()-1);
			pq.pop();
		}
		while(!q.empty()){
			pq.push(q.front());
			q.pop();
		}
	}

	if(yes){
		printf("Case #%d:Yes\n",tc);	
	}else{
		printf("Case #%d:No\n",tc);	
	}
	tc+=1;
	}
	return 0;
}
// havel's theorm 
