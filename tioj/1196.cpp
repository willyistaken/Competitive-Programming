#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int chartoint(char a){
	if(a-'0'>=0 && a-'0'<=9){
		return a-'0';
	}
	if(a=='X') return -1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n][n]={0};
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<n;j++) arr[i][j]=chartoint(s[j]);
	}
	int ans[n][n]={{0}};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==-1){ans[i][j]=-1;continue;}
			if(!i || !j){
				if(!i && !j) continue;
				if(!i){
					ans[i][j] = (ans[i][j-1]==-1) ? -1:ans[i][j-1]+arr[i][j];
				}else{
					ans[i][j] = (ans[i-1][j]==-1) ? -1:ans[i-1][j]+arr[i][j];
				}
			}else{
				if(ans[i-1][j] == -1 && ans[i][j-1]==-1){ans[i][j]=-1;continue;}
				ans[i][j] = max(ans[i-1][j],ans[i][j-1])+arr[i][j];
			}
		}
	}
	if(ans[n-1][n-1]<0) cout<<"X\n";
	else cout<<ans[n-1][n-1]<<"\n";
	return 0;
}
