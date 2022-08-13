#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    long double s[n+1];
    s[0]=0.0;
    int pn[n+1]={0};
    int zero[n+1]={0};
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a);
        zero[i]=zero[i-1]+(int)(a==0);
        pn[i]=pn[i-1]+(int)(a<0);
        a = abs(a);
        s[i] = s[i-1]+log10(a);
    }

    while(q--){
        int l,r;cin>>l>>r;
        long double expo = s[r]-s[l];
        int pns = pn[r]-pn[l];
        if(zero[r]!=zero[l]) puts("0");
        else{
            if(pns%2) putchar('-');
            printf("%.10LfE+%1.Lf\n",
				powl(10,expo-floorl(expo)),
				floorl(expo)
			);     
        }
    }







    return 0;
}