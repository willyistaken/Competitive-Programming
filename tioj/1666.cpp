#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b;
	while(cin>>a>>b){
		if(a^b){
			cout<<"kelvin\n";
		}else{
			cout<<"yiping\n";	
		}
	}
	return 0;
}
