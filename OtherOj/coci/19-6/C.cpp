#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int k;cin>>k;
	if(k>=0){
	int a = k;
	a++;
	int n = a+2;
	cout<<n<<" "<<2*a<<"\n";
	for(int i=2;i<=a+1;i++){
		cout<<1<<" "<<i<<"\n";
		cout<<i<<" "<<n<<"\n";
	}
	}else{
		int b = abs(k);
		int n = b+5;
		cout<<n<<" "<<3*b+5<<"\n";
		cout<<1<<" "<<2<<"\n";
		cout<<1<<" "<<3<<"\n";
		for(int i=4;i<=4+b;i++){
			cout<<2<<" "<<i<<"\n";
			cout<<3<<" "<<i<<"\n";
			cout<<i<<" "<<n<<"\n";
		}
	}

	return 0;
}
