#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int id(int l,int r){
	return (l+r)|(l!=r);
}

void built(int l,int r){
	cout<<id(l,r)<<" "<<l<<" "<<r<<'\n';
	if(l==r) return ;
	int m = (l+r)/2;
	built(l,m);
	built(m+1,r);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	built(1,n);
	return 0;
}
