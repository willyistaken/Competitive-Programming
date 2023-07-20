#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds



bool double_check(int a,int b,int c,int d){
	for(int i=0;i<16;i++){
		int f;
		if(i%4==0) f= a+b;
		if(i%4==1) f=a-b;
		if(i%4==2) f=a*b;
		if(i%4==3){
			if(a%b!=0) continue;
			f = a/b;
		}
		int s;
		if(i/4==0) s= f+c;
		if(i/4==1) s = f-c;
		if(i/4==2) s = f*c;
		if(i/4==3){
			if(f%c!=0) continue;
			s = f/c;
		}
		if(s==d) return 1;
	}
	for(int i=0;i<16;i++){
		int s;
		if(i/4==0) s= b+c;
		if(i/4==1) s = b-c;
		if(i/4==2) s = b*c;
		if(i/4==3){
			if(b%c!=0) continue;
			s = b/c;
		}
		int f;
		if(i%4==0) f= a+s;
		if(i%4==1) f=a-s;
		if(i%4==2) f=a*s;
		if(i%4==3){
			if(a%s!=0) continue;
			f = a/s;
		}
		if(f==d) return 1;
	}
	return 0;
}

bool check(int a,int b,int c,int d){
	int num[3] = {a,b,c};
	for(int i=0;i<6;i++){
	if(double_check(num[0],num[1],num[2],d)) return 1;
	next_permutation(num,num+3);
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int d=1;d<=100;d++){
		bool works=0;
		for(int a=1;a<=100;a++)	{
			if(works) break;
			for(int b=a+1;b<=100;b++){
				if(works) break;
				for(int c=b+1;c<=100;c++){
					if(works) break;
					if(a==d || b==d || c==d) continue;
					if(check(a,b,c,d)==0){
						works=1;
						cout<<d<<":"<<a<<","<<b<<","<<c<<"\n";
					}
				}
			}
		}
	}

	return 0;
}
