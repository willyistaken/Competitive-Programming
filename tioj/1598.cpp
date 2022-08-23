#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n;
vector<int> pancake;
int b;
// note: a person can pass pancakes on , so the optimal structure should be a binary tree
bool workink(int v, int k, int t){
	int lowlayer = __lg(k+1);
	ll temp = k-((1<<lowlayer)-1);
	ll allstuff = (t-lowlayer-1)*temp*2;
	allstuff += (t-lowlayer)*((1<<lowlayer)-temp);
	return allstuff>=v;
}
bool work(int t){
	int ans=0;
		for(int i=0;i<n;i++){
			int l=-1;int r = b+1;
			while(r-l>1){
				int mid = (l+r)/2;
				if(workink(pancake[i],mid,t)) r = mid;
				else l = mid;
			}
			ans+=r;
			if(ans>b) return 0;
		}
		return 1;
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>b;
	pancake.resize(n);
	for(int i=0;i<n;i++) cin>>pancake[i];
	int l=0;int r = *max_element(pancake.begin(),pancake.end());
	while(r-l>1){
		int mid = (l+r)/2;
		if(work(mid)) r= mid;
		else l = mid;
	}
	cout<<r<<"\n";
	return 0;
}
