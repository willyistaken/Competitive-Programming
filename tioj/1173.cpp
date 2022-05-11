#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b,c;cin>>a>>b>>c;
	if((double)b==((double)(a+c)/2)){	
		if((a&&b&&c)&&((double)c/b == (double)b/a)){
			cout<<"both\n";
			return 0;
		}else{
			cout<<"arithmetic\n";
			return 0;
		}
	}
	if(((a&&b&&c)&&((double)c/b == (double)b/a))){
		cout<<"geometric\n";
		return 0;
	}
	cout<<"normal\n";
	return 0;
}
