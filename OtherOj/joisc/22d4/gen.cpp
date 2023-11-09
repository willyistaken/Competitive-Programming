#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n=8;
	mt19937 mt(time(0));
	uniform_int_distribution<> gen(1,10);
	cout<<n<<"\n";
	for(int i=0;i<n;i++) cout<<gen(mt)<<" ";
	cout<<"\n";
	int q = gen(mt);
	cout<<q<<"\n";
	for(int i=0;i<q;i++){
		int t = gen(mt)&1;
		t++;
		cout<<t<<" ";
		if(t==2){
		int l = (gen(mt)%n)+1;
		int r = (gen(mt)%n)+1;
		if(l>r) swap(l,r);
		cout<<l<<" "<<r<<"\n";
		}else{
			int ind = (gen(mt)%n)+1;
			cout<<ind<<" "<<gen(mt)<<"\n";
		}
	}
	return 0;
}
