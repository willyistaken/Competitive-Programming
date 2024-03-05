#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

int cor[3][3];
int C = 16;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int v1,v2,v3;cin>>v1>>v2>>v3;	
	if(v1+v2+v3>3*7*7*7){
		cout<<"No\n";
		return 0;
	}
	for(cor[1][0]=0;cor[1][0]<=C;cor[1][0]++){
		for(cor[1][1]=0;cor[1][1]<=C;cor[1][1]++){
			for(cor[1][2]=0;cor[1][2]<=C;cor[1][2]++){
				for(cor[2][0]=0;cor[2][0]<=C;cor[2][0]++){
					for(cor[2][1]=0;cor[2][1]<=C;cor[2][1]++){
						for(cor[2][2]=0;cor[2][2]<=C;cor[2][2]++){
							int rv3 = 1;	
							{
							pair<int,int> r[3];
							for(int i=0;i<3;i++) r[i] = {-1e9,1e9};
							for(int i=0;i<3;i++){
								for(int j=0;j<3;j++){
									r[i].first = max(r[i].first,cor[j][i]);
									r[i].second = min(r[i].second,cor[j][i]+7);
								}
								rv3*=max(0,r[i].second-r[i].first);
							}
							}
							int rv2 = 0;
							{
							for(int k=0;k<3;k++){
								int rv2k = 1;
								pair<int,int> r[3];
								for(int i=0;i<3;i++) r[i] = {-1e9,1e9};
								for(int i=0;i<3;i++) r[i] = {-1e9,1e9};
							for(int i=0;i<3;i++){
								for(int j=0;j<3;j++){
									if(j==k) continue;
									r[i].first = max(r[i].first,cor[j][i]);
									r[i].second = min(r[i].second,cor[j][i]+7);
								}
								rv2k*=max(0,r[i].second-r[i].first);
							}
								rv2+=rv2k;	
							}
							}
							rv2-=3*rv3;
							int rv1 = 3*7*7*7-2*rv2-3*rv3;
							if(rv1==v1 && rv2==v2 && rv3==v3){
								cout<<"Yes\n";
								for(int i=0;i<3;i++){
									for(int j=0;j<3;j++){
										cout<<cor[i][j]<<" ";
									}
								}
								cout<<"\n";
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout<<"No\n";
	return 0;
}
