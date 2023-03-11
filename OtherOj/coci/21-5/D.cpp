#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int cnt = 0;

vector<int> pcnt;
const int N  =1e6;
int smp[1000005];
vector<int> prime;
map<int,int> mp;
void init(){
	for(int i=2;i<N;i++){
		if(!smp[i])	{
			smp[i]=i;
			mp[i] = prime.size();
			prime.push_back(i);
			for(int j=2*i;j<N;j+=i){
				if(!smp[j]) smp[j]=i;
			}
		}
	}
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	if(n<=100 && q<=200){
											
	}else{
		
	}

	return 0;
}
