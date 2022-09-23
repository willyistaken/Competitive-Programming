#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,k;
string s;
void recur(int t){
	if(n-t<=k) return;
	int mind = 10;
	int ind=0;
	for(int i=t;i<min((t+k)+1,n);i++){
		if(mind>(s[i]-'0')){
			mind = (s[i]-'0');
			ind = i;
		}
	}
	cout<<s[ind];
	k-=ind-t;
	recur(ind+1);
	return;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n>>k){
	cin>>s;
	int mind=10;
	int ind=0;
	for(int i=0;i<=k;i++){
		if((s[i]-'0')<mind && s[i]!='0')	{
			mind = s[i]-'0';
			ind = i;
		}
	}
	k-=ind;
	cout<<mind;
	recur(ind+1);	
	cout<<"\n";
	}
	return 0;
}
