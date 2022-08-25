#include "lib1088.h";
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int a[3];
	Initialize(a+0,a+1,a+2);
	while(true){
		int G = a[0]^a[1]^a[2];
		int compile=0;
		int comnum=0;
		if(!G){
			for(int i=0;i<3;i++){
				if(a[i]){
					Take_Stone(i+1,a[i],&compile,&comnum);
					a[i]=0;
					a[compile-1]-=comnum;
					break;
				}
			}
		}else{
			for(int i=0;i<3;i++){
				if((G^a[i])<a[i]){
					Take_Stone(i+1,a[i]-(G^a[i]),&compile,&comnum);
					a[i] = G^a[i];
					a[compile-1]-=comnum;
					break;
				}
			}
		}
	}
	return 0;
}
