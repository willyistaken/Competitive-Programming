#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	srand(time(0));
	int t = rand();
	t%=5;
	t++;
	while(t--){
		int n =rand()%20;		
		n++;
		cout<<n<<"\n";
		for(int i=0;i<n;i++){
			int l = rand()%n;	
			int r = rand()%n;	
			int u = rand()%n;	
			int d = rand()%n;	
			l++;r++;u++;d++;
			if(l>r) swap(l,r);
			if(u>d) swap(u,d);
			cout<<l<<" "<<r<<" "<<u<<" "<<d<<"\n";
		}
		cout<<"\n";
	}



    return 0;
}
