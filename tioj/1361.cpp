#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int b;

ll dp[10][10][2][2];

vector<int> num;

void getnum(){
	while(b){
		num.push_back(b%10);
		b/=10;
	}
	reverse(num.begin(),num.end());
}

ll DP(int p,int cnt,bool f,bool s){

		
}


ll solve(int k){
	if(k<0) return 0;
	if(k==0) return 1;
	b = k;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			dp[i][j][0][0]=-1;
			dp[i][j][1][0]=-1;
			dp[i][j][0][1]=-1;
			dp[i][j][1][1]=-1;
		}
	}
	num.clear();
	getnum();
	return DP(0,0,0,0);
}



int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a;
	while(cin>>a){
		cout<<solve(a)<<"\n";	
	}

	return 0;
}
