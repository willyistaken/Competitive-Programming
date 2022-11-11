#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
ll ans = 0;
int arr[8][8];

bool check(int x,int y){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(arr[i][j]!=2) continue;
			if(x==i || y==j || abs(x-i)==abs(y-j)) return 0;
		}
	}
	return 1;
}

void dfs(int queens){
	if(queens==8){
		ans++;
		return ;
	}
		for(int j=0;j<8;j++){
			if(arr[queens][j]) continue;
			if(check(queens,j)){
				arr[queens][j] =2;
				dfs(queens+1);
				arr[queens][j] = 0;
			}
		}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<8;i++){
		string s;cin>>s;
		for(int j=0;j<8;j++){
			arr[i][j] = (s[j]=='*');
		}
	}
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}
