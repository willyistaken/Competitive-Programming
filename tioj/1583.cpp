#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct people{
	string name;
	int h;
	int w;
};
bool comp(const people &a,const people &b){
	return (a.w*b.h*b.h>b.w*a.h*a.h);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	people arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].name>>arr[i].w>>arr[i].h;
	}
	sort(arr,arr+n,comp);
	for(int i=0;i<min(n,10);i++) cout<<arr[i].name<<"\n";

	return 0;
}
