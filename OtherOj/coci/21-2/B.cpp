#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct dsu{
	vector<int> arr;
	void init(int s){
		arr.resize(s);
		for(int i=0;i<s;i++){
			arr[i]=i;
		}
	}
	int query(int a){
		if(arr[a]==a) return arr[a];
		arr[a] = query(arr[a]);
		return arr[a];
	}
	void join(int a,int b){
		a = query(a);
		b=  query(b);
		arr[a]=b;
		return ;
	}
} D;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;			
	D.init(n);
	for(int i=0;i<m;i++){
		for(int i=0;i<n;i++){
			int b;cin>>b;
			b--;
			D.join(i,b);
		}
	}
	while(q--){
		int a,b;cin>>a>>b;
		a--;b--;
		if(D.query(a)==D.query(b)) cout<<"DA\n";
		else cout<<"NE\n";
	}
	return 0;
}
