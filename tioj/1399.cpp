#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T,n;
	while(cin>>T>>n){
		int f[n];
		int d[n];
		int dis[n];
		for(int i=0;i<n;i++) cin>>f[i];
		for(int i=0;i<n;i++) cin>>d[i];
		for(int i=0;i<n;i++) cin>>dis[i];
		priority_queue<int,vector<int> , greater<int> > pq;
		ll ans = 0 ;ll sum=0;
		for(int i=0;i<n;i++){
			T-=dis[i];
			while(T<0 && pq.size()){
				sum-=pq.top();
				pq.pop();
				T++;
			}
			if(T<0 || (T==0 && pq.empty())) break;
			for(int j=0;j*d[i]<f[i];j++){
				int newv = f[i]-(j*d[i]);
				if(T>0){
					pq.push(newv);
					sum+=newv;
					T--;
				}else if(pq.top()<newv){
					sum+=newv;
					sum-=pq.top();
					pq.pop();
					pq.push(newv);
				}else break;
			}
			ans = max(ans,sum);
		}
		cout<<ans<<"\n";	
	}
	

	return 0;
}
