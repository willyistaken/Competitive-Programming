#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int f(int n){
	int sum=0;
	if(n<=0) return 0;
	if(n==1) return 1;
	sum+=f(n-1);
	sum+=f(n-2);
	return sum;
}
int main(){
	f(4);








	return 0;
}
