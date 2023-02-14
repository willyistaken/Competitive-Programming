#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	int n = 10;
	int q = 100;
	cout<<n<<" "<<q<<"\n";
	for(int i=0;i<n;i++) cout<<rand()%100<<" ";
	cout<<"\n";
	while(q--){
		int ty = rand()%4;
		ty++;
		cout<<ty<<" ";
		int l = rand()%n;
		int r = rand()%n;
		if(l>r) swap(l,r);
		l++;r++;
		cout<<l<<" "<<r<<" ";
		int x = rand()%100000000;
		if(ty<=2) cout<<x<<"\n";
		else cout<<"\n";
	}
	return 0;
}
