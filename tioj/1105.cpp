#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n;
struct pt{
	ll x;
	ll y;
	int id=-1;
};

pt operator-(const pt &a,const pt &b){
	return {a.x-b.x,a.y-b.y,-1};
}
ll operator^(const pt &a,const pt &b){
	return a.x*b.y-a.y*b.x;
}

ll operator*(const pt &a,const pt &b){
	return a.x*b.x+a.y*b.y;
}

inline int m(int i){return i%n;}

ll dis(const pt &a,const pt &b){
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

ll area(const pt &r,const pt &b,const pt &c){
	return abs((b-r)^(c-r));
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	while(cin>>n && n){
		vector<pt> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i].x>>arr[i].y;
			arr[i].id = i;
		}
		int st;
		stable_sort(arr.begin(),arr.end(),[](const pt &a,const pt &b){return (a.x==b.x)?(a.y<b.y):(a.x<b.x);});
		for(int i=0;i<n-1;i++) if(arr[i].x==arr[i+1].x && arr[i].y==arr[i+1].y) arr[i+1].id = arr[i].id;
		vector<pt> convex;
		for(int t=0;t<2;t++){
			int size=convex.size();
			for(int i=0;i<n;i++){
				while(convex.size()-size>=2){
						int b = convex.size();
						if(((arr[i]-convex[b-2])^(convex[b-1]-convex[b-2]))<0) break;
						convex.pop_back();
				}
				convex.push_back(arr[i]);
			}
			convex.pop_back();
			reverse(arr.begin(),arr.end());
		}
		ll maxdis = 0;
		st = 1;
		pair<int,int> ans = make_pair(5000,5000);
		for(int i=0;i<n;i++){
			while(area(convex[i],convex[m(i+1)],convex[st])<area(convex[i],convex[m(i+1)],convex[m(st+1)])){
				st = m(st+1);
			if(maxdis<dis(convex[i],convex[st])){
				maxdis = dis(convex[i],convex[st]);
				ans = {min(convex[i].id,convex[st].id),max(convex[i].id,convex[st].id)};
			}else if(maxdis == dis(convex[i],convex[st])){
				pair<int,int> temp = {min(convex[i].id,convex[st].id),max(convex[i].id,convex[st].id)};
				ans = min(ans,temp);
			}
			}
		}
		cout<<ans.first<<" "<<ans.second<<"\n";	
	}
	return 0;
}
