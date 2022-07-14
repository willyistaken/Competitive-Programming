#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int i,vector<int> &a,vector<bool> &vis){
	vis[i]=1;
	if(!vis[a[i]]) dfs(a[i],a,vis);
}


int main(){
	vector<int> a,b;
	a.push_back(0);b.push_back(0);
	int number=0;
	int flag=0;
	while(true){
		char c = getchar();
		if(c=='\n'){
			a.push_back(number);
			number=0;
			break;
		}
		if(c==' '){
			if(flag==0){
				a.push_back(number);
				number=0;
			}
			flag=1;
			continue;
		}
		if(c>='0'){
			number*=10;
			number+=c-'0';
			flag=0;
		}
	}
	number=0;
	flag=0;
	while(true){
		char c = getchar();
		if(c=='\n'){
			b.push_back(number);
			number=0;
			break;
		}
		if(c==' '){
			if(flag==0){
			b.push_back(number);
			number=0;
			}
			flag=1;
			continue;
		}
		if(c>='0'){
			number*=10;
			number+=c-'0';
			flag=0;
		}
	}

	if(a.size()!=b.size()) {
		cout<<-1<<"\n";
		return 0;
	}


	int n = a.size()-1;

	vector<int> now(n+1);

	for(int i=1;i<=n;i++){
		now[b[i]] = i;
	}

	for(int i=1;i<=n;i++){
		a[i] = now[a[i]];
	}

	vector<bool> vis(n+1,0);	

	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[a[i]]){
		
			ans++;
			dfs(a[i],a,vis);
		}
	}
	assert(n-ans>=0 && ans>=1);
	printf("%d\n",n-ans);


	return 0;
}
// note to self: the testcase of this problem is so bad..., there may be two or more spaces between numbers.... why can't it be normal input output....
