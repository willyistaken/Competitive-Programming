#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

const int MAXN = 5e5+5;
int num[MAXN];


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		int sum=0;
		if(arr[i]>MAXN)  break;
		for(int j=i;j>=0;j--){
			sum+=arr[j];
			if(sum>=MAXN) break;
			num[sum]++;
		}
	}
	int q;cin>>q;
	while(q--){
		int r;cin>>r;
		cout<<num[r]<<"\n";
	}

	return 0;
}

//note to self: think about brute force first and check time complexity maybe it will work!
//the time complex is nsqrt(S) because the array is increasing, so that the maxium length of a segment with the sum S is sqrt(S) 
