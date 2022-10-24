#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	int r = 1;
	while(r--){
		int n = rand()%50;
		cout<<n<<" ";
		for(int i=0;i<n;i++) cout<<rand()<<" ";	
		cout<<rand()%1000000<<"\n";
	}
	cout<<0<<"\n";
	return 0;
}
