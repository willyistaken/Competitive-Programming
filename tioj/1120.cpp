#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<pair<int,int> > place;
	for(int i=0;i<=5;i++){
		place.push_back({10+i,5});
	}
	for(int i=1;i<=10;i++){
		place.push_back({15,5+i});
	}
	for(int i=1;i<=10;i++){
		place.push_back({15-i,15});
	}
	for(int i=1;i<=10;i++){
		place.push_back({5,15-i});
	}
	for(int i=1;i<=4;i++){
		place.push_back({5+i,5});
	}
	int t;
	while(cin>>t){
		t = 6*t;
		t%=40;
		cout<<"("<<place[t].first<<","<<place[t].second<<")\n";
	}
	return 0;
}
