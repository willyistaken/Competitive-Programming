#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::
int n,k;
int m,num;
const int MOD = 1e9+7;

int pow(int a,int p) {
    ll r=1;
    while(p) {
        if(p&1) r = (r*a)%MOD;
        a = (1LL*a*a)%MOD;
        p>>=1;
    }
    return r;
}

void getChoose(int* arr) {
    arr[0]=1;
    for(int i=1; i<=k; i++) {
        if(num<i) {
            arr[i]=0;
            continue;
        }
        arr[i] = (1LL*arr[i-1]*(num-i+1))%MOD;
        arr[i] = (1LL*arr[i]*pow(i,MOD-2))%MOD;
    }
}

int madd(int a,int b) {
    a = (a+b)%m;
    if(a<0) a+=m;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        m = __gcd(n,k);
        num = n/m;
        int dp[m][k+1];;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int C[k+1] = {0};
        getChoose(C);
        for(int r=0; r<m; r++) {

            for(int h = k; h>=1; h--) {

                for(int j=0; j<m; j++) {

                    int cur = 0;

                    for(int i=0; i<=h; i++) {

                        cur = (cur+ ((1LL*C[i]*dp[madd(j,-i*r)][h-i])%MOD) )%MOD;

                    }

                    dp[j][h] = cur;

                }


            }

        }

        int ans = (1LL*dp[0][k]*pow(num,MOD-2))%MOD;
        cout<<ans<<"\n";

    }

    return 0;
}

