#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::

struct node{
	ll arr[1000000];
	node* a;
};

int main(){
	int n;cin>>n;
	vector<ll> a;
	if(n<=1){
		cout<<0<<"\n";
		return 0;
	}
	if(n==2){
		cout<<2<<"\n";
		return 0;
	}
	if(n==3){
		node* p = new node;
		for(int i=0;i<100000000;i++){
			p->a = new node;
			p = p->a;
		}
		cout<<n<<"\n";
		return 0;
	}
	cout<<n<<"\n";
	return 0;
}
