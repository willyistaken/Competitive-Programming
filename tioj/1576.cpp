#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::



int main(){
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	int ans=0;
	int ck,mk,wk=0;
	for(int i=0;i<=min(b,d);i++){
		int milk = b-i;
		int ta = a;
		int mki = min(ta,milk);
		milk-=mki;ta-=mki;
		int cki = min(ta,c);
		int total = (mki*100)+(cki*80)+(60*i);
		if(ans<total){
			ans=total;
			ck = cki;
			mk = mki;
			wk = i;
		}
	}
	printf("%d %d %d\n",ck,mk,wk);
	printf("%d\n",ans);
	return 0;
}
