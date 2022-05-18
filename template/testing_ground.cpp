#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
bool eval(bool a,bool b,bool c,bool d){
	return (a || !d)&&(!a || b)&&(!b || c)&&(!a || !b || !c)&&(a || !c || d);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<16;i++){
		if(eval(i&1,(i>>1)&1,(i>>2)&1,(i>>3)&1)){
			cout<<i;
		}
	}






	return 0;
}
