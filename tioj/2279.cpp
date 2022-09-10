#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include<unistd.h>
#include <csignal>
#include <signal.h>

struct node{
	ll arr[1000000];
	node* p;
};

int main(){
	int n;cin>>n;
	if(n<=1){
		cout<<0<<endl;
	}
	if(n==2){
		cout<<2<<endl;
		while(1){
			
		}
	}
	if(n==3){
		cout<<3<<endl;
		auto a = new long long [7800][1000];
		a[0][0]=1;
	}
	if(n==4){
		cout<<4<<endl;	
		node* a = new node;
		for(int i=0;i<500;i++){
			memset(a->arr,0,sizeof(a->arr));
			a->p = new node;
			a = a->p;
			
		}
	}
	if(n==5){
		cout<<5;
		for(int i=0;i<100000000;i++){
			for(int j=0;j<100000000;j++){
				cout<<" ";	
			}
		}
		cout<<"\n";
	}
	if(n==6){
		cout<<6<<endl;	
		return 1;
	}
	if(n==7){
		cout<<7<<endl;
		assert(1==0);
	}
	if(n==8){
		cout<<8<<endl;	
		auto a = new long long [1000][1000];
		a[0][0]=1;
	}
	if(n==9){
		cout<<9<<"\n";	
	}
}
