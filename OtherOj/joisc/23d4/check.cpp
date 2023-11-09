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
		cout<<a<<" "<<b<<"\n";
		int n;in>>n;		
		vector<int> x(n);
		for(int i=0;i<n;i++) in>>x[i];
		int q;in>>q;
		vector<int> y(q);
		for(int i=0;i<q;i++) in>>y[i];
		cout<<n<<"\n";
		for(int i=0;i<n;i++) cout<<x[i]<<" ";
		cout<<"\n"<<q<<"\n";
		for(int i=0;i<q;i++) cout<<y[i]<<"\n";
	}
	return 0;
}
