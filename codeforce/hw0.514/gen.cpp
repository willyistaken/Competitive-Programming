#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	random_device rd;
	mt19937 gen(rd());
	int n = gen()%10+1;
	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		cout<<gen()%100<<" ";
	}
	cout<<"\n";

	return 0;
}
