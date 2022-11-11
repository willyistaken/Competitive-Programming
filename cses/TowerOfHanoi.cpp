#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds


void move(int n,int from,int to){
	if(n==1){
		cout<<from<<" "<<to<<"\n";
		return;
	}
	move(n-1,from,6-from-to);
	cout<<from<<" "<<to<<"\n";	
	move(n-1,6-from-to,to);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	cout<<(1<<n)-1<<"\n";
	move(n,1,3);
	return 0;
}
