#include <bits/stdc++.h>
using namespace std;


int main(){ 
    long long n=300000000;
    vector<bool> arr(n+1,0);
    long long c=0;
	long long sum=0;
	long long const MOD = 4294967296;
    for(long long i=2;i<=n;i++){
        if(!arr[i]){
            long long j=2;
            while(i*j<=n){
                arr[j*i]=1;
                j++;
            }
            ++c;
			sum+=i;
			sum%=MOD;
        }
        if(i%100000==0) cout<<i<<endl;
    }
    cout<<endl<<endl;
	cout<<c<<endl<<sum<<endl;

    return 0;
}
