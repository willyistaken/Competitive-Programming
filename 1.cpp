#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	long long n,m;cin>>n>>m;
	long long k;cin>>k;
	long long arr[k];
	int arrc[k]={0};
	for(int i=0;i<k;i++){
		long long a,b;cin>>a>>b;
		arr[i]=(a-1)*m;
		if(a%2==0){
			arr[i]+=(m-b+1);
		}else{
			arr[i]+=b;
		}
	}
	sort(arr,arr+k);
	long long back=0;
	int conti=1;
	arrc[0]=1;
	for(int j=1;j<=k-1;j++){
		if(arr[j]==arr[j-1]+1){
			conti+=1;
		}else{
			conti=1;
		}
		if(conti>=6){
			cout<<-1<<endl;
			return 0;
		}
		arrc[j]=conti;
	}
	for(int j=0;j<k;j++){
		if((arr[j]+back)%6==0){
			back+=arrc[j];
		}
	}
    if((n*m+back)%6!=0){
        cout<<((n*m+back)/6)+1<<endl;
        }else{
            cout<<((n*m+back)/6)<<endl;
        }

	
} 