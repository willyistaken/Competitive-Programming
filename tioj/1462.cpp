#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
struct pt{
	ll x;
	ll y;
};

ll operator^(pt a,pt b){
	return a.x*b.y-a.y*b.x;
}

ll operator*(pt a,pt b){
	return a.x*b.x+a.y*b.y;
}

pt operator-(pt a,pt b){
	return {a.x-b.x,a.y-b.y};
}
void solve(int n,int t,pt p){
	for(int i=0;i<n;i++){
		pt b;
		int px,py;cin>>b.x>>b.y;
		cin>>px>>py;
		pt v = {1LL*t*px,1LL*t*py};
		if(((p-b)^v)==0){
			if(((p-b)*v)>=0){
				if((p-b)*v<=(v*v)){
					cout<<"true\n";
					for(int j = i+1;j<n;j++){
						int a;
						cin>>a;cin>>a;cin>>a;cin>>a;
					}
					return ;
				}
			}
		}
	}
	cout<<"false\n";
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,t;
	pt p;
	while(cin>>n>>t>>p.x>>p.y && n){
		solve(n,t,p);
	}

	return 0;
}
