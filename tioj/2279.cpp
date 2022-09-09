#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include<unistd.h>
#include <csignal>
#include <signal.h>


int f(int g){
	if(g<=1) return 1;
	return f(g-1)+f(g-2);
}

int g(){
	int p=1;
	while(1){
		if(p) cout<<2<<"\n";	
		p=0;
	}
}
void init(){
	vector<ll> a;
	a.resize(1000000000,0);
	
}
int main(){
	int n;scanf("%d",&n);
	if(n<=1){
		printf("0\n");
	}
	if(n==2){
		g();
	}
	if(n==3){
		init();
		cout<<3<<"\n";
	}
	if(n==4){
		init();
		cout<<4<<"\n";	
	}
	if(n==5){
		cout<<5<<"\n";
	}
	if(n==6){
		cout<<6<<"\n";	
		return 1;
	}
	if(n==7){
		cout<<7<<"\n";
	}
	if(n==8){
		int p = f(20);
		cout<<8<<"\n";	
	}
	if(n==9){
		cout<<9<<"\n";	
	}
}
