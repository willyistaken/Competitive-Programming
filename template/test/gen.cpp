#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	mt19937 rng(time(0));
	int n = 20;
	int q = 10;
	cout<<n<<" "<<q<<"\n";
	for(int i=0;i<n;i++){
		cout<<rng()%100+1<<" ";
	}
	cout<<'\n';
	for(int i=0;i<q;i++){
		int t = !(i&1);
		if(t){
			int l = rng()%n+1;
			int r = rng()%n+1;
			if(r<l) swap(l,r);
			cout<<t<<" "<<l<<" "<<r<<"\n";
		}else{
			int l = rng()%n+1;
			int r = rng()%n+1;
			if(r<l) swap(l,r);
			int c = rng()%100+1;
			cout<<t<<" "<<l<<" "<<r<<' '<<c<<"\n";
		}
	}

	return 0;
}
