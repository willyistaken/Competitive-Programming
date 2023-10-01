#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int he[2005][2005];
int h,w;
vector<pair<int,int> > minn;

bool walked[2005][2005];
int dx[4] = {0,0,-1,1};

int Maxn,Minn;
int cnt;
int minnn = INT_MAX;
int maxnn = INT_MIN;
int minbound[2005];
int maxbound[2005];
bool check(int d){
	// min on top	
	bool works=1;
	for(int i=1;i<=h;i++){
		minbound[i] = w+1;
		maxbound[i] = 0;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(he[i][j]<maxnn-d) break;
			maxbound[i] = j;
		}
		for(int j=w;j>=1;j--){
			if(he[i][j]>minnn+d) break;
			minbound[i] = j;
		}
		if(minbound[i]-maxbound[i]>1){
			works=0;
			break;
		}
	}
	if(works){
		bool g = 1;	
		int k = 0;
		for(int i=1;i<=h;i++){
			k = max(k,minbound[i]);
			if(maxbound[i]<k-1){g=0;break;}
		}
		if(g) return 1;
		k = w+1;
		g=1;
		for(int i=1;i<=h;i++){
			k = min(k,maxbound[i]);
			if(minbound[i]>k+1){g=0;break;}
		}
		if(g) return 1;
	}

	// max on top
	works=1;
	for(int i=1;i<=h;i++){
		minbound[i] = 0;
		maxbound[i] = w;
	}
	for(int i=1;i<=h;i++){
		for(int j=w;j>=1;j--){
			if(he[i][j]<maxnn-d) break;
			maxbound[i] = j;
		}
		for(int j=1;j<=w;j++){
			if(he[i][j]>minnn+d) break;
			minbound[i] = j;
		}
		if(maxbound[i]-minbound[i]>1){
			works=0;
			break;
		}
	}
	if(works){
		bool g = 1;	
		int k = 0;
		for(int i=1;i<=h;i++){
			k = max(k,maxbound[i]);
			if(minbound[i]<k-1){g=0;break;}
		}
		if(g) return 1;
		k = w+1;
		g=1;
		for(int i=1;i<=h;i++){
			k = min(k,minbound[i]);
			if(maxbound[i]>k+1){g=0;break;}
		}
		if(g) return 1;
	}
	return 0;	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>h>>w;	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>he[i][j];
			minnn = min(minnn,he[i][j]);
			maxnn = max(maxnn,he[i][j]);
		}
	}
	int l = 0;int r = 1e9+5;		
	while(r-l>1){
		int mid = (l+(r-l)/2);
		if(check(mid))r = mid;
		else l = mid;
	}
	cout<<r<<"\n";
	return 0;
}
