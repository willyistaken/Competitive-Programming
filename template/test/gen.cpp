#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	mt19937 rng(time(0));
	int n = rng()%5+2;
	cout<<n<<"\n"; 
	for(int i=0;i<n;i++){
		cout<<rng()%100<<" "<<rng()%100<<"\n";
	}

	return 0;
}
