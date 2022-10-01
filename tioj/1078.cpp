#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b;
vector<bool> num;

void init(){
	for(int i=49;i>=0;i--){
		num.push_back((b>>i)&1);
	}
}

ll dp[50][50+1][50][2]={0};
/*
digit dp:
 p : the current place
 f : the first none zero digit
 cnt : the count of 1
 s : is the number smaller than b yet

*/
ll DP(int p,int f,int cnt,bool s){
	if(b==0) return 0;
	if(p>=num.size()){
		if(num.size()-f+1<2*cnt) return 1;
		else return 0;
	}
	if(dp[p][f][cnt][s]!=-1) return dp[p][f][cnt][s];
	ll result=0;
	if(!s && !num[p]) result = DP(p+1,f,cnt,s);
	else{
		if(f && s){
			result+=DP(p+1,f,cnt+1,s);
			result+=DP(p+1,f,cnt,s);
		}else if(f){
			result+=DP(p+1,f,cnt+1,s);
			result+=DP(p+1,f,cnt,1);
		}else if(s){
			result+=DP(p+1,p+1,cnt+1,s);
			result+=DP(p+1,f,cnt,s);
		}else{
			result+=DP(p+1,p+1,cnt+1,s);
			result+=DP(p+1,f,cnt,1);
		}
	}
	dp[p][f][cnt][s] = result;
	return result;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>b;
		num.clear();
		init();
		for(int i=0;i<50;i++){
			for(int j=0;j<50;j++){
				for(int k=0;k<50;k++){
					dp[i][j][k][0]=-1;
					dp[i][j][k][1]=-1;
				}
			}
		}
		cout<<DP(0,0,0,0)<<"\n";
	}
	return 0;
}
