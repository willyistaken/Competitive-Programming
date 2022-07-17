#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int main(){
	srand(time(0));
	int n = rand();
	n%=50;
	n++;
	int q = rand();
	q%=20;
	cout<<n<<" "<<q<<"\n";
	for(int i=0;i<n;i++){
		cout<<rand()%MOD<<" ";
	}
	cout<<"\n";
	for(int i=0;i<n;i++){
		cout<<rand()%MOD<<" ";
	}
	cout<<"\n";
	for(int i=0;i<q;i++){
		int type = rand()%3;
		int l,r;l=rand()%n;r=rand()%n;
		if(l>r) swap(l,r);
		l++;r++;
		type++;
		if(type<=2){
			cout<<type<<" ";
			cout<<l<<" "<<r<<" ";
			cout<<rand()%MOD<<"\n";
		}else{
			cout<<type<<" "<<l<<" "<<r<<"\n";
		}
	}
}
