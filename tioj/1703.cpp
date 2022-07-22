#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
while(cin>>n){
	int ans=0;
	int power=3;
	while(power<=n){
		ans+=(n-(n%power))/power;
		power*=3;
	}
	cout<<ans<<endl;
}
}
