#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;
	vector<pair<int,int> > cor(n+1);
	vector<pair<int,int> > rcor(n+1);
	string s;cin>>s;
	s = " "+s;
	for(int i=1;i<=n;i++){
		cor[i]=cor[i-1];
		if(s[i]=='U') cor[i].second++;
		if(s[i]=='D') cor[i].second--;
		if(s[i]=='R') cor[i].first++;
		if(s[i]=='L') cor[i].first--;
	}
	for(int i=n;i>=1;i--){
		rcor[n-i+1] = rcor[n-i];
		if(s[i]=='U') rcor[n-i+1].second++;
		if(s[i]=='D') rcor[n-i+1].second--;
		if(s[i]=='R') rcor[n-i+1].first++;
		if(s[i]=='L') rcor[n-i+1].first--;
	}
	map<pair<int,int>,vector<int> > cormp;		
	map<pair<int,int>,vector<int> > rcormp;		
	for(int i=1;i<=n;i++) cormp[cor[i]].push_back(i);
	for(int i=1;i<=n;i++) rcormp[rcor[i]].push_back(i);
	while(q--){
		pair<int,int> now;
		cin>>now.first>>now.second;
		int l,r;cin>>l>>r;
		if(now.first==0 && now.second==0){
			cout<<"YES\n";
			continue;
		}
		if(cormp.count(now)){
			if(cormp[now][0]<l){
				cout<<"YES\n";
				continue;
			}
		}
		pair<int,int> tnow;
		tnow.first = now.first-cor[l-1].first-(rcor[n-l+1].first-rcor[n-r].first)+cor[r].first;
		tnow.second = now.second-cor[l-1].second-(rcor[n-l+1].second-rcor[n-r].second)+cor[r].second;
		if(cormp.count(tnow)){
			if(cormp[tnow].back()>r){
				cout<<"YES\n";
				continue;
			}
		}	
		pair<int,int> snow;
		snow.first = now.first-cor[l-1].first+rcor[n-r].first;
		snow.second = now.second-cor[l-1].second+rcor[n-r].second;
		if(rcormp.count(snow)){
			auto il = lower_bound(rcormp[snow].begin(),rcormp[snow].end(),n-r+1)-rcormp[snow].begin();
			auto ir = upper_bound(rcormp[snow].begin(),rcormp[snow].end(),n-l+1)-rcormp[snow].begin();
			if(il!=ir){
				cout<<"YES\n";
				continue;
			}
		}
		cout<<"NO\n";
	}
	return 0;
}
