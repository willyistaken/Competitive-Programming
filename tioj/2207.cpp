#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;cin>>n>>k;
	if(k==1){
		string a;cin>>a;
		for(auto i : a){
			cout<<(i=='0');
		}
		cout<<"\n";
	}
	if(k==2){
		string a,b;cin>>a>>b;
		int difa,difb;
		difa=0;difb=0;
		for(int i=0;i<n;i++){
			if(a[i]==b[i]) cout<<(a[i]=='0');
			else{
				if(difa>=difb){
					cout<<(a[i]=='0');
					difb++;
				}else{
					cout<<(b[i]=='0');
					difa++;
				}
			}
		}
	}
	if(k==3){
		string s[3];
		int dif[3]={0};
		int whichisdif[n];
		bool ans[n];
		cin>>s[0]>>s[1]>>s[2];
		for(int i=0;i<n;i++){
			int sum  = (s[0][i]-'0')+(s[1][i]-'0')+(s[2][i]-'0');
			if(sum==0 || sum==3){
				whichisdif[i]=-1;
				ans[i] = (s[0][i]=='0');
			}
			else{
				if(sum==1){
					ans[i]=1;
					for(int g=0;g<3;g++){
						if(s[g][i]=='1'){
							dif[g]++;
							whichisdif[i]=g;
							break;
						}
					}
				}else{
					ans[i]=0;
					for(int g=0;g<3;g++){
						if(s[g][i]=='0'){
							dif[g]++;
							whichisdif[i]=g;
							break;
						}
					}
				}
			}
		}
		int wh=0;
		for(int i=0;i<3;i++){
			if(dif[i]==max({dif[0],dif[1],dif[2]}))  wh=i;
		}
		sort(dif,dif+3);
		int howmanystuff = dif[2]-dif[1];
		for(int i=0;i<n && howmanystuff>0;i++){
			if(whichisdif[i]==wh){
				ans[i] = !ans[i];
				howmanystuff-=2;
			}
		}
		for(int i=0;i<n;i++) cout<<ans[i];
		cout<<"\n";

	}

	return 0;
}
