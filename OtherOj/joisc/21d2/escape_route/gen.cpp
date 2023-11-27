#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	for(int i=0;i<1000;i++){
		int a,b;
		a = rand()%6;
		b = rand()%6;
		if(a==b) a = (a+1)%6;
		int t = rand()%100;
		cout<<a<<" "<<b<<" "<<t<<"\n";
	}


	return 0;
}
