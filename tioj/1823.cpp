/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool islucky(int n){
	if( n==1 || n==7) return true;
	if(n<10) return false;
	int sum=0;
	while(n){
		sum+= (n%10)*(n%10);
		n/=10;
	}
	return islucky(sum);
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	vector<int> p;
	int i=1;
	while(p.size()<10000){
		if(islucky(i)) p.push_back(i);
		i++;
	}
	for(auto i : p) cout<<i<<"\n";
	cout<<p[9]<<"\n";
	cout<<p[49]<<"\n";
	cout<<p[99]<<"\n";
	cout<<p[999]<<"\n";
	cout<<p[9999]<<"\n";
	return 0;
}
*/

#include<cstdio>
using namespace std;
typedef long long ll;



int main(){
	puts("44\n320\n694\n6899\n67169");

	return 0;
}
