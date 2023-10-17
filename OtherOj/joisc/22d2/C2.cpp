#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
const int N = 305;

int Xsum[N][N][N];
int Ysum[N][N][N];
int Zsum[N][N][N];



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n>4000){
	for(int i=0;i<n;i++){
		int a,b,c;cin>>a>>b>>c;
		Xsum[a][b][c]++;
		Ysum[b][a][c]++;
		Zsum[c][a][b]++;
	}
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			for(int k=1;k<N;k++){
				Xsum[i][j][k] = Xsum[i][j][k]+Xsum[i][j-1][k]+Xsum[i][j][k-1]-Xsum[i][j-1][k-1];
				Ysum[i][j][k] = Ysum[i][j][k]+Ysum[i][j-1][k]+Ysum[i][j][k-1]-Ysum[i][j-1][k-1];
				Zsum[i][j][k] = Zsum[i][j][k]+Zsum[i][j-1][k]+Zsum[i][j][k-1]-Zsum[i][j-1][k-1];
			}
		}
	}
	int ans = -1;
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			for(int k=1;k<N;k++){
				if(Xsum[i][j-1][k-1] && Ysum[j][i-1][k-1] && Zsum[k][i-1][j-1]) ans = max(ans,i+j+k);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
	}else{
		
	vector<int> Y;
	vector<int> Z;
	vector<int> X;
	X.resize(n);
	Y.resize(n);
	Z.resize(n);
	vector<int> w(n);
	for(int i=0;i<n;i++) cin>>X[i]>>Y[i]>>Z[i];
	for(int i=0;i<n;i++) {w[i]=i;}
	sort(w.begin(),w.end(),[&](const int a,const int b){return Y[a]<Y[b];});
	int ans = -1;
	int prevy = 1e9;
	for(int i=0;i<n;i++){
		int maxn = -1e9;
		vector<int> tadd;
		for(int j=0;j<n;j++){
			if(X[w[j]]>=X[i]) continue;
			if(Y[w[j]]>prevy){
				while(tadd.size()){
					maxn = max(maxn,Z[tadd.back()]);
					tadd.pop_back();
				}
			}
			prevy = Y[w[j]];
			tadd.push_back(w[j]);
			if(Y[w[j]]>Y[i]){
				if(maxn>Z[i] && maxn>Z[w[j]]){
//					cout<<i<<" "<<w[j]<<" "<<maxn<<"\n";
					ans = max(ans,maxn+Y[w[j]]+X[i]);
				}
			}
		}
	}
	cout<<ans<<"\n";

	return 0;
	}
}
