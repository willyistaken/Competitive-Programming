#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	srand( time(NULL) );
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = rand()%100+5;
	int m = rand()%100+5;
	cout<<n<<" "<<m<<"\n";	
	for(int i=0;i<m;i++){
		cout<<rand()%n + 1<<" "<<rand()%n + 1<<" "<<((rand()%2)?(-1):(1))*(rand()%11)<<"\n";
	}
	return 0;
}
