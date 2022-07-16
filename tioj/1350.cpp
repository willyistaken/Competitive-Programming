#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100;
bool notprime[MAXN];
vector<int> prime;
void init(){
for(int i=2;i<MAXN;i++){
	if(!notprime[i]){
		prime.push_back(i);
		for(int j=2;j*i<MAXN;j++){
			notprime[j*i]=1;
		}
	}
}
}
int stuff[MAXN][1229];
int main(){
	init();
	cout<<prime.size();	
	for(int i=1;i<=MAXN;i++){
		if(notprime[i]){
			for(int g=0;g<prime.size();g++)	{
				if(i%prime[g]==0) stuff[i][g]+=1;
				int how = i/prime[g];
				for(int h=0;h<1229;h++){
					stuff[i][h]+=stuff[how][h];
				}
			}
		}else{
			int k =  lower_bound(prime.begin(),prime.end(),i)-prime.begin();
			stuff[i][k]=1;
		}
	}
	int testdata;cin>>testdata;
	cout<<"hello";
	while(testdata--){
		int b;cin>>b;
		if(b==1) {
			cout<<"(1)";
			continue;
		}
		int flag=0;
		for(int i=0;i<1229;i++){
			if(stuff[b][i]){
				if(flag) cout<<"*";
				cout<<"(";
				cout<<prime[i];
				if(stuff[b][i]!=1) cout<<"^"<<stuff[b][i];
				cout<<")";
				flag=1;
			}
		}
		cout<<"\n";
	}
	return 0;
}
