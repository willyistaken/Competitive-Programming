#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	int n = 20;
	int q = 10;
	cout<<n<<" "<<q<<"\n";
	for(int i=0;i<n;i++) cout<<rand()%100<<" ";
	cout<<"\n";
	while(q--){
		int ty = rand()%2;
		if(ty){
			cout<<"2 ";
		}else{
			cout<<"1 ";
		}
		int a = rand()%n+1;int b = rand()%n+1;
		if(a>b) swap(a,b);
		cout<<a<<' '<<b<<"\n";
	}
	return 0;
}
