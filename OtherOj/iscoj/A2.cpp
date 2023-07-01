#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    ll num = 0;
    ll flo = 0;
    bool k = 0;
    ll how = 1;
    for(auto c : s) {
        if(c!='.') {
            if(k) {
				flo*=10;
				flo+=c-'0';
				how*=10;
            } else {
                num*=10;
                num+=c-'0';
            }
        } else {
            k = 1;
        }
    }
	ll top = flo;
	ll bot = how-1;
	ll d = __gcd(top,bot);
	top/=d;
	bot/=d;
	top+=num*bot;
	cout<<top<<"/"<<bot<<"\n";
    return 0;
}
