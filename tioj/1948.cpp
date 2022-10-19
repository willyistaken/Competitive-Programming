#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,L;
const int MAXN = 1e6+5;
pair<int,int> arr[MAXN];
bool v[MAXN];
int l,r;
bool getnext(){
	while(l<n && l<r){
		l++;
		if(v[arr[l].second]==1){
			return 1;
		}
	}
	return 0;
}

bool getprev(){
	while(r>=0&&r>l){
		r--;
		if(v[arr[r].second]==0){
			return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>L;
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second = i;
		cin>>v[i];
	}
	sort(arr,arr+n);
	int maxind = 0;
	int maxtime=0;
	for(int i=0;i<n;i++){
		int t = v[arr[i].second]?(L-arr[i].first):(arr[i].first);
		if(maxtime<=t){
			maxind = i;
			maxtime = t;
		}
	}
	l = maxind;
	r = v[arr[l].second]?(n):(-1);

	if(l>r) swap(l,r);
	if(v[arr[maxind].second]){
		while(1){
			if(!getprev()){
				cout<<arr[l].second<<"\n";
				return 0;
			}
			if(!getnext()){
				cout<<arr[r].second<<"\n";
				return 0;
			}
		}
	}else{
		while(1){
			if(!getnext()){
				cout<<arr[r].second<<"\n";
				return 0;
			}
			if(!getprev()){
				cout<<arr[l].second<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
