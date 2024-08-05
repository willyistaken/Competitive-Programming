#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	random_device rd;
	mt19937 gen(rd());
	int n = 8;
	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		cout<<((gen()%2)?"B ":"R ")<<gen()%10000001<<" "<<gen()%10000001<<"\n";
	}
	cout<<"\n";

	return 0;
}
