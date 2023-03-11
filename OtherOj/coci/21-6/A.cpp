#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<pair<int,string>> best;
	vector<pair<int,string> > worse;
	pair<string,int> score[n];
	for(int i=0;i<n;i++){
		string s;cin>>s;
		score[i].second=0;
		for(int j=0;j<5;j++){
			int a;cin>>a;
			score[i].second+=a;
		}
		score[i].first = s;
		best.push_back({-score[i].second-500,score[i].first});
		worse.push_back({-score[i].second,score[i].first});
	}
	sort(best.begin(),best.end());	
	sort(worse.begin(),worse.end());
	for(int i=0;i<n;i++){
		pair<int,string> p = {-score[i].second-500,score[i].first};
		int g = upper_bound(worse.begin(),worse.end(),p)-worse.begin();	
		cout<<g+1<<" ";
		p.first+=500;
		g = upper_bound(best.begin(),best.end(),p)-best.begin();	
		cout<<g<<"\n";	
	}
	return 0;
}
