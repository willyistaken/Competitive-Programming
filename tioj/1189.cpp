#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds
int act(int x,int y,int t){
	if(t==0) return x+y;
	if(t==1) return x-y;
	if(t==2) return x*y;
	if(t==3){
		if(y==0 || x%y!=0) return -100;
		return x/y;
	}
	return -100;
}

bool solve(int a,int b,int c,int d){
	int arr[3] = {0,0,0};
	int ta = a;int tb = b;int tc = c;int td = d;
	for(int i = 0;i<64;i++){
		for(int i = 0;i<2;i++){
			if(arr[i]>3) {
				arr[i] = 0;
				arr[i+1]++;
			}
		}
		// 1 2 3
			bool f = 1;
			a = ta;b =tb;c = tc;d = td;
			if((a = act(a,b,arr[0]))==-100) f= 0;
			if((a = act(a,c,arr[1]))==-100)	f = 0; 
			if((a = act(a,d,arr[2]))==-100)	f = 0;	
			if(a==24 && f) return 1;
		/// 1 3 2
			a = ta;b =tb;c = tc;d = td;
			f = 1;
			if((a = act(a,b,arr[0]))==-100) f= 0;
			if((c = act(c,d,arr[2]))==-100) f= 0;
			if((a = act(a,c,arr[1]))==-100) f= 0;
			if(a==24 && f) return 1;
		/// 2 1 3
			a = ta;b =tb;c = tc;d = td;
			f = 1;
			if((b = act(b,c,arr[1]))==-100) f= 0;
			if((a = act(a,b,arr[0]))==-100) f= 0;
			if((a = act(a,d,arr[2]))==-100) f= 0;
			if(a==24 && f) return 1;

		// 2 3 1
			a = ta;b =tb;c = tc;d = td;
			f = 1;
			if((b = act(b,c,arr[1]))==-100) f= 0;
			if((b = act(b,d,arr[2]))==-100) f= 0;
			if((a = act(a,b,arr[0]))==-100) f= 0;
			if(a==24 && f) return 1;


		// 3 1 2
			a = ta;b =tb;c = tc;d = td;
			f = 1;
			if((c = act(c,d,arr[2]))==-100) f= 0;
			if((a = act(a,b,arr[0]))==-100) f= 0;
			if((a = act(a,c,arr[1]))==-100) f= 0;
			if(a==24 && f) return 1;

		/// 3 2 1
			a = ta;b =tb;c = tc;d = td;
			f = 1;
			if((c = act(c,d,arr[2]))==-100) f= 0;
			if((b = act(b,c,arr[1]))==-100) f= 0;
			if((a = act(a,b,arr[0]))==-100) f= 0;
			if(a==24 && f) return 1;
		arr[0]++;
	}
	return 0;
}


int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int arr[4];
	while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3] && (arr[0] && arr[1] && arr[2] && arr[3])) {
		int k[4] = {0,1,2,3};	
		bool flag=0;
		for(int i=0;i<24;i++){
			if(solve(arr[k[0]],arr[k[1]],arr[k[2]],arr[k[3]])){
				cout<<"YES\n";
				flag=1;
				break;
			}
			next_permutation(k,k+4);
		}
		if(!flag) cout<<"NO\n";
	}

	return 0;
}
