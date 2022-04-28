#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int n;
int main(){
	cin>>n;
	int maxn=1;
	int ia,ib;cin>>ia>>ib;
	int curstuff=1;
	int cur=ia;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		if(a>=cur){
			curstuff++;
			maxn=max(maxn,curstuff);
			cur=a;
		}else{
			curstuff=0;
			cur=a;
		}
	}
	cout<<maxn<<endl;
}