#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	if(n%4==3 || n%4==0){
		cout<<"YES\n";
		if(n%4==0){
			cout<<n/2<<"\n";
			for(int i=0;i<n/4;i++){
				cout<<i+1<<" "<<n-i<<" ";
			}
			cout<<"\n";
			cout<<n/2<<"\n";
			for(int i=n/4;i<n/2;i++){
				cout<<i+1<<' '<<n-i<<" ";
			}
			cout<<"\n";
		}else{
			vector<int> fr;	
			vector<int> se;
			int ele = ((n/2)+1)/2;
			for(int i=1;i<(n+1)/2-1;i++){
				if(i%2){
					fr.push_back(i);
					fr.push_back(n-i+1);
				}else{
					se.push_back(i);
					se.push_back(n-i+1);
				}
			}
			if(ele%2==0){
			fr.push_back(ele);
			fr.push_back((n+1)/2);
			se.push_back(((n+1)/2)+1);
			se.push_back(((n+1))/2-1);
			cout<<fr.size()<<"\n";
			for(auto i: fr){
				cout<<i<<" ";
			}
			cout<<"\n";
			cout<<se.size()-1<<"\n";
			for(auto i : se) {
				if(i!=ele) {
					cout<<i<<" ";
				}
			}
			cout<<"\n";
			}else{

			se.push_back(ele);
			se.push_back((n+1)/2);
			fr.push_back(((n+1)/2)+1);
			fr.push_back(((n+1))/2-1);
			cout<<se.size()<<"\n";
			for(auto i: se){
				cout<<i<<" ";
			}
			cout<<"\n";
			cout<<fr.size()-1<<"\n";
			for(auto i : fr) {
				if(i!=ele) {
					cout<<i<<" ";
				}
			}
			cout<<"\n";
			}
		}
	}else{
		cout<<"NO\n";
	}

	return 0;
}
