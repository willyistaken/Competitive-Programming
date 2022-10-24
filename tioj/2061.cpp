#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

struct bit{
	vector<int> arr;
	int s;
	void init(int k){
		arr.resize(k+1,-1);
		s = k;
	}
	int query(int ind){
		int r = 0;
		while(ind){
			r = max(r,arr[ind]);
			ind-=(ind & -ind);
		}
		return r;
	}
	void change(int ind,int v){
		while(ind<=s){
			arr[ind] = max(arr[ind],v);
			ind+=(ind & -ind);
		}
	}
};


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<int> loc[10];
	string s;cin>>s;
	vector<int> dp(s.size()+1,0);
	vector<int> start(10,0);
	bit fenwick;
	fenwick.init(s.size());
	s  = " "+s;
	for(int i=1;i<s.size();i++){
		if(!start[s[i]-'0']) start[s[i]-'0'] = i;
	}
	for(int i=1;i<s.size();i++){
		if()	
	}
	return 0;
}
