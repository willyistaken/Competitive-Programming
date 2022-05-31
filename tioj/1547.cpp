#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fib[31]={0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987, 1597,2584,4181,6765,10946,17711,28657,46368,75025, 121393,196418,317811,514229,832040,1346269};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    int now=1;
    for(int i=0;i<t;i++){
        for(int j=0;j<fib[i+1];j++){
            now = (now>2) ? now-3:now;
            cout<<now;
            ++now;
        }
        cout<<endl;
    }







    return 0;
}