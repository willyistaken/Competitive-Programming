#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

void getmap(int k,vector<vector<int> > &mapk,vector<int> &fack){
	for(int i=1;i*i<=k;i++){
		if(k%i==0){
			fack.push_back(k/i);
			fack.push_back(i);
		}
	}
	sort(fack.begin(),fack.end());
	mapk.resize(fack.size());
	for(int i=0;i<fack.size();i++){
		for(int j=0;j<i;j++){
			if(fack[i]%fack[j]==0) mapk[i].push_back(j);
		}
	}
}


int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int x,y;
        cin>>x>>y;
		vector<int> facx;vector<int> facy;
		vector<vector<int> > mapx; getmap(x,mapx,facx);
		vector<vector<int> > mapy; getmap(y,mapy,facy);
		bool dp[facx.size()][facy.size()]={{0}};
		for(int i=0;i<facx.size();i++){
			for(int j=0;j<facy.size();j++){
				if(facx[i]==facy[j]) dp[i][j]=0;
				else{
					int ans=0;
					if(facx[i]>facy[j]){
						for(auto v : mapx[i]){
							ans = max(ans,1-dp[v][j]);	
						}
					}
					else{
						for(auto v:mapy[j]){
							ans = max(ans,1-dp[i][v]);
						}
					}
					//cout<<facx[i]<<" "<<facy[j]<<" : "<<ans<<"\n";
					dp[i][j]=ans;
				}
					
			}
		}
		if(dp[facx.size()-1][facy.size()-1]){
			cout<<"Danb\n";	
		}else{
			cout<<"Zisk\n";	
		}
    }

    return 0;
}
