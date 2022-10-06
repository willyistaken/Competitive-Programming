#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds::




int main() {

    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    bool appear[10]= {0};
    for(int i=0; i<k; i++) {
        int a;
        cin>>a;
        appear[a]=1;
    }
    string l,r;
    cin>>l>>r;
    int digitis[10]= {0};
    fill(digitis,digitis+10,-1);
    int j=0;
    for(int i=0; i<10; i++) {
        if(!appear[i]) digitis[i]=j++;
    }
    int totalin = 1;
    int lt = 0;
    for(int i=l.size()-1; i>=0; i--) {
        lt+=totalin*digitis[(l[i]-'0')];
        totalin*=n-k;
    }
    int rt=0;
    totalin=1;
    for(int i=r.size()-1; i>=0; i--) {
        rt+=totalin*digitis[(r[i]-'0')];
        totalin*=n-k;
    }
	cout<<lt<<" "<<rt<<"\n";
    ll ans=0;
    ll div = 1;
    while(div<=rt) {
        ans+=(rt/div)-(lt/div);
        div = 1LL*(n-k)*div;
    }
    cout<<ans<<"\n";
    return 0;

}
