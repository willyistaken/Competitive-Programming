#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 1e6;
bitset<N+1> notprime;

void init(){
	for(int i=2;i<=N;i++){
		if(!notprime[i]){
			for(int j=i+i;j<=N;j+=i){
				notprime[j]=1;
			}
		}
	}
}

struct q{
	int n;
	int m;
	int t;
	int ans;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int arr[N+1];
	int ans[N+1];
	for(int i=1;i<=N;i++) arr[i]=i;
	for(int i=1;i<=N;i++) ans[i]=i;
	init();
	int t;cin>>t;
	q query[t];
	for(int i=0;i<t;i++){
		cin>>query[i].n>>query[i].m;
		query[i].t = i;
	}
	sort(query,query+t,[](const q &a,const q &b){return a.n<b.n;});
	int h = 0;
	for(int p=2;p<=N;p++){
		if(h>=t) break;
		if(!notprime[p]){
		int head = arr[p];
		for(int i=p+p;i<=N;i+=p){
			swap(ans[arr[i]],ans[head]);
			swap(arr[i],head);
		}
		swap(ans[arr[p]],ans[head]);
		arr[p] = head;
		}
		if(h<t && query[h].n==p ){
			query[h].ans = ans[query[h].m];
			h++;
		}
	}
	sort(query,query+t,[](const q &a,const q &b){return a.t<b.t;});
	for(int i=0;i<t;i++){
		if(notprime[query[i].ans]) cout<<query[i].ans<<"\n";
		else cout<<"Geng Jian malheureux roi mauvaise!!\n";
	}
}
