#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


void getbinary(bool te[25],int v){
	for(int i=24;i>=0;i--){
		if((v>>i)&1) te[24-i]=1;
		else te[i]=0;
	}
}
int n;
vector<int> arr;

struct trie{
	trie* child[2];			
				
};


ll ans(int l,int r){
	//cout<<l<<" "<<r<<"\n";
	if(r-l==1) return 0;
	int mid = (r+l)/2;
	ll divide = ans(l,mid)+ans(mid,r);	
	int lmax[mid-l+1]={0};
	int rmax[r-mid+1]={0};
	for(int i=1;i<mid-l+1;i++) lmax[i] = max(lmax[i-1],arr[mid-i]);	
	for(int i=1;i<r-mid+1;i++) rmax[i] = max(rmax[i-1],arr[mid+i-1]);
		
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	arr.resize(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<ans(0,n)<<"\n";
	return 0;
}

/*
3
5770022 4193537 8629972 

3
*/
