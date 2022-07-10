#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	int n;scanf("%d",&n);
	while(n--){
		int m;scanf("%d",&m);
		pair<int,int> arr[m];
		for(int i=0;i<m;i++){
			int a,b;scanf("%d %d",&b,&a);
			arr[i] = {a,b};
		}
		sort(arr,arr+m);
		int now=0;
		bool pass=1;
		for(int i=0;i<m;i++){
			now+=arr[i].second;
			if(now>arr[i].first){
				puts("unschedulable");
				pass=0;
				break;
			}
		}
		if(pass) puts("schedulable");
	}

	return 0;
}
