#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve(){
	int n;cin>>n;
	if(n==1){
		cout<<1<<"\n"<<"1 2\n";
		return ;
	}
	if(n==2){
		cout<<"1\n2 6\n";
		return ;
	}
	vector<pair<int,int> > ans;
	int howmanya = n;
	int p = 2;
	for(int i = 3*n;i>=0 && howmanya>0;i--){
		if(i%3==0){
			ans.push_back({p,i});
			p+=3;
			howmanya--;
		}
		if(i%3==2) howmanya--;

	}
	cout<<ans.size()<<"\n";
	for(auto i : ans) {
		cout<<i.first<<" "<<i.second<<"\n";
	}
}



int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

