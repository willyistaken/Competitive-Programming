#include "lib1087.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::


int main(){

	int a=10;
	int b = 15;
	int c = 20;
	Initialize();
	while(true){
		int compile=0;
		int  comnum=0;
		int wholeG = a^b^c^((a>1)+(b>1)+(c>1)<=1);
		if((wholeG^a)<a){
			Take_Stone(1,a -( wholeG^a),&compile,&comnum);
			a = wholeG^a;

		}else if((wholeG^b)<b){
			Take_Stone(2,b - (wholeG^b),&compile,&comnum);
			b = wholeG^b;
		}else if((wholeG^c)<c){
			Take_Stone(3,c - (wholeG^c),&compile,&comnum);
			c = wholeG^c;
		}
		if(compile==1) a-=comnum;
		else if(compile==2) b-=comnum;
		else if(compile==3) c-=comnum;
	}

}
