#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int root(int x){
	if(!x) return 0;
	return (x-1)%9+1;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,r;cin>>n>>r;
	n--;
	string s;cin>>s;
	int sum=0;
	for(int i=0;i<n;i++) sum+=s[i]-'0';
	bitset<10> vis;
	int minn=11;
	int maxn=-1;
	for(int i=0;i<=9;i++){
		if(root(sum+i)==r){
			vis[i]=1;
			minn = min(minn,i);
			maxn = max(maxn,i);
		}
	}
	set<string> strs;
	for(int i=0;i<=9;i++){
		if(!vis[i]) continue;
		for(int j=n;j>=0;j--){
			int head=0;
			string add="";
			for(int k=0;k<=n;k++){
				if(k==j) add+='0'+i;
				else add+=s[head++];
			}
			strs.insert(add);
		}
	}
	auto g = strs.begin();
	int forward = strs.size()-2;
	while(forward--){
		++g;
		cout<<*g<<"\n";
	}
	return 0;
}
