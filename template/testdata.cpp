#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	srand( time(NULL) );
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n = rand()%10+5;
	int m = rand()%10+5;
	if(n>m) swap(n,m);
	cout<<n<<" "<<m<<"\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<setw(3)<<rand()%100<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
