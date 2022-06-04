#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=2;i<=100000;i++){
		int number=0;
		int sum=0;
		for(int j=1;j<=i;j++){
			
			if(i%j==0) {
				sum+=j;
				number+=1;
			}
		}
		cout<<i<<":"<<sum<<" "<<number<<" "<<sum*number<<endl;
	}







	return 0;
}