#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,M;
bool can(int a,int where[],int arr[]){
	int nowsize =M;
	int nowk = k;
	for(int i=0;i<n;i++){
		if(where[i]<a){
			if(arr[i]>M) return false;
			if(arr[i]>nowsize){
				nowsize=M;
				nowk--;
			}
				nowsize-=arr[i];
		}
	}
	return (nowk>1 ||( nowk==1 && nowsize>=0));
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k>>M;	
	int arr[n];
	pair<int,int> tobesort[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		tobesort[i] = {arr[i],i};
	}
	sort(tobesort,tobesort+n);
	int where[n];
	for(int i=0;i<n;i++){
		where[tobesort[i].second]=i;
	}
	int l = 0;int r = n+1;
	while(r-l>1){
		int mid = (r+l)/2;
		if(can(mid,where,arr)) l = mid;
		else r = mid;
	}
	cout<<l<<"\n";
	return 0;
}


/*
STUCK:  what is the optimal strategies
THINK: is the smaller the better, could I construct a counter example or proof it
	can't think of counter example: proof?
AHA: greedly chose first A smallest turtle and see if possible:binary search
doesn't work


try dp







*/
