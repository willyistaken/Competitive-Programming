#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	int cnt = 0;
	string a,b,c;
	while(cin>>s){
		a=b;
		b=c;
		c = s;
		if(a=="A" && b=="5" && c=="cow") cnt++;
	}
	cout<<cnt<<"\n";

	return 0;
}
