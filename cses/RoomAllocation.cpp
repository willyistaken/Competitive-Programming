#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


struct T{
	int t;
	int id;
	bool type;
};

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	vector<T> arr;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		arr.push_back({a,i,0});
		arr.push_back({b+1,i,1});
	}
	int ans = 0;
	sort(arr.begin(),arr.end(),[](const T &a,const T &b){return (a.t==b.t)?(a.type>b.type):(a.t<b.t);});
	int which[n]={0};
	stack<int> room;
	for(int i=n+1;i>=1;i--) room.push(i);
	for(auto i : arr){
		if(i.type) room.push(which[i.id]);
		else {
			which[i.id]=room.top();
			room.pop();
		}
	}
	for(int i=0;i<n;i++) ans = max(which[i],ans);
	cout<<ans<<"\n";
	for(int i=0;i<n;i++){
		cout<<which[i]<<" \n"[i==n-1];
	}
	return 0;
}
