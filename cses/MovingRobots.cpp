#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


double prob[8][8];
double ans[8][8];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool inbound(int i,int j){
	if(i<0 || i>=8 ||j<0 ||j>=8) return 0;
	return 1;
}
int cnt(int i,int j){
	int ans= 0 ;
	for(int k=0;k<4;k++) if(inbound(i+dx[k],j+dy[k])) ans++;
	return ans;
}
void calc(int k){
	double next[8][8];
	for(int n=0;n<k;n++){
		memset(next,0.0,sizeof(next));
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				for(int h=0;h<4;h++) {
					double g = cnt(i,j);
					if(inbound(i+dx[h],j+dy[h])) next[i+dx[h]][j+dy[h]]+=(prob[i][j]/g);
				}
			}
		}
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				prob[i][j] = next[i][j];
			}
		}
	}
	return ;
}

void update(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			ans[i][j]*=(1-prob[i][j]);
		}
	}
}
void print(double arr[8][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<fixed<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k;cin>>k;	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			ans[i][j]=1.0;
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			memset(prob,0,sizeof(prob));			
			prob[i][j]=1;
			calc(k);
			update();
			
		}
	}
	double exp = 0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			exp+=ans[i][j];
		}
	}
	cout<<fixed<<setprecision(6)<<exp<<"\n";
	return 0;
}

