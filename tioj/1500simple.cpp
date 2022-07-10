#pragma GCC optimize("Ofast")
#pragma loop_opt(on)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline char readchar(){
	const int S = 1<<20;
	static char buf[S], *p = buf, *q = buf;
	if(p==q&&(q=(p=buf)+fread(buf,1,S,stdin))==buf) return EOF;
	return *p++;
}
inline int R(){
	int ans = 0, c = readchar(), minus = false;
	while((c<'0'||c>'9')&&c!='-'&&c!=EOF) c=readchar();
	if(c=='-') minus = true, c = readchar();
	while(c>='0'&&c<='9') ans=(ans<<3)+(ans<<1)+(c^'0'), c=readchar();
	return minus ? -ans : ans;
}



struct point{
	double x;
	double y;
};
point arr[50005];
double dis(point a,point b){
	return	hypot(a.x-b.x,a.y-b.y);
}
int n;
double minn;
int main(){
	while(true){
	if((n = R())==0) return 0;	
	for(int i=0;i<n;i++){
		arr[i]={(double)R(),(double)R()};
	}
	sort(arr,arr+n,[](const point &a,const point &b){return ((a.x!=b.x) ? a.x<b.x:a.y<b.y);});
	minn = 1e15;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].x-arr[j].x>minn) break;
			minn = min(dis(arr[i],arr[j]),minn);
		}
	}
	printf("%.6lf\n", minn);	
	}
	return 0;
}
