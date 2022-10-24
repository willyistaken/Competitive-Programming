#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


bitset<100000005> grundy;
int t[1<<20];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m,n;cin>>m>>n;
	if(m<=100000003){
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	int ans = 0;
	grundy.reset();
	for(int i=0;i<=m;i++){
		if(grundy[i]) ++ans;
		else{
			for(int j = 0; (j<n) && (arr[j]+i<=m) ; j++) grundy[arr[j]+i] = 1;
		}
	}
	cout<<ans<<"\n";
	}else{
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		int s = 0;
		grundy[0]=0;
		for(int i=1;i<20;i++){
			int g = 1;
			for(int j = 0;j<n && i-arr[j]>=0;j++){
				g&= ((s>>(i-arr[j]))&1);
			}
			g = !g;
			grundy[i] = g;
			s+=(g<<i);
		}
		int k = 19;
		int cnt= 0;
		while(!t[s]){
			t[s] = k;	
			int g = 1;
			for(int j = 0;j<n;j++){
				g&=((s>>j)&1);	
			}
			g = !g;
			s+=(g<<20);
			cnt+=g;
			s>>=1;
			k++;
			grundy[k] = g;
		}
		int pd = k-t[s];
		int 		
	}
	return 0;
}
