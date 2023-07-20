#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int a=1;a<=4;a++){
		for(int b=a;b<=4;b++){
			for(int c=b;c<=4;c++){
				if(a+b>c && a+c>b && c+b>a){
					int k = a+b+c;	
					ll area = k*(k-(2*a))*(k-(2*b))*(k-(2*c));
					cout<<a<<" "<<b<<" "<<c<<":"<<area<<"\n";
				}else{
					cout<<a<<" "<<b<<" "<<c<<":0\n";
				}
			}
		}
	}

	return 0;
}
