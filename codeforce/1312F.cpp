#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

const int N = 100;
int sg[N+5][3];

int mex(int a,int b,int c){
	if(c<a)	 swap(a,c);
	if(c<b) swap(b,c);
	if(b<a) swap(a,b);
	int r = 0;
	if(r==a) r++;
	if(r==b) r++;
	if(r==c) r++;
	return r;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x,y,z;cin>>x>>y>>z;	
	for(int i=1;i<=N;i++){
		sg[i][0] = mex(sg[max(0,i-x)][0],sg[max(0,i-y)][1],sg[max(0,i-z)][2]);
		sg[i][1] = mex(sg[max(0,i-x)][0],sg[max(0,i-z)][2],1e9);
		sg[i][2] = mex(sg[max(0,i-x)][0],sg[max(0,i-y)][1],1e9);
		cout<<sg[i][0]<<' '<<sg[i][1]<<" "<<sg[i][2]<<"\n";
	}
	return 0;
}
