#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 1e6+5;
int has[N];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	while(n--){
		int a;cin>>a;
		has[a]+=1;
	}
	for(int i=N-1;i>=1;i--){
		int cnt = 0;
		for(int h = i;h<N;h+=i){
			cnt+=has[h];
		}
		if(cnt>=2){
			cout<<i<<"\n";
			return 0;
		}
	}
	return 0;
}
