#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds




int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        bool ans = 0;
        for(int i=0; i<n; i++) {
            int a;
            cin>>a;
            if(a%2) ans=1;
        }
        if(ans) cout<<"first\n";
        else cout<<"second\n";
    }
    return 0;
}
