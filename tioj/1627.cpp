#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,T,Q;
    while(cin>>n>>T>>Q) {
        int dif[T+1]= {0};
        int cnt[T+1]= {0};
        for(int i=0; i<n; i++) {
            int a;
            cin>>a;
            cnt[a]++;
        }
        for(int i=1; i<=T; i++) {
            for(int j=0; j<=T; j+=i) {
                if((j/i)%2) {
                    dif[j]-=cnt[i];
                } else {
                    dif[j]+=cnt[i];
                }
            }
        }
        for(int i=1; i<=T; i++) {
            dif[i]+=dif[i-1];

        }
        while(Q--) {
            int g;
            cin>>g;
            cout<<dif[g]<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
