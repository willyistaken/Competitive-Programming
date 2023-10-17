#include<bits/stdc++.h>
#include<fstream>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a,b;cin>>a>>b;
	ifstream in;
	in.open("testcase.in");
	if(a!=b){
		cout<<"\nhasstuff:"<<a<<" "<<b<<":\n";
		int n;in>>n;	
		cout<<n<<"\n";
		for(int i=0;i<n;i++){
			int x,y,z;cin>>x>>y>>z;
			cout<<x<<" "<<y<<" "<<z<<"\n";
		}
		cout<<"\n\n\n";
	}
		

	


	return 0;
}
