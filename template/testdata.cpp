#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	srand( time(NULL) );
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = rand()%15;
	cout<<n<<"\n";
	for(int i=0;i<n;i++) cout<<rand()%10000000<<" ";
	cout<<"\n";
	return 0;
}
