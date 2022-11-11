#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		string s;cin>>s;
		int mcnt =0;
		vector<int> where;
		int ocnt= 0;
		for(int i=0;i<2*n;i++){
			if(s[i]=='1') ocnt++;
		}
		if(ocnt&1){
			cout<<"-1"<<"\n";
			continue;
		}
		for(int i=0;i<2*n;i+=2){
			if(s[i]!=s[i+1]){
				mcnt+=1;
				if(mcnt&1){
					if(s[i]=='0') where.push_back(i);
					else where.push_back(i+1);
				}else{
					if(s[i]=='1') where.push_back(i);
					else where.push_back(i+1);
				}

			}
		}
		cout<<mcnt;
		for(int i=0;i<mcnt;i++){
			cout<<" "<<where[i]+1;
		}
		cout<<"\n";
		for(int i=1;i<=2*n;i+=2){
			cout<<i<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
