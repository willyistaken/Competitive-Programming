#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string day[7]={"Sunday\n","Monday\n","Tuesday\n","Wednesday\n","Thursday\n","Friday\n","Saturday\n"};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(cin>>n){
        cout<<day[(5+n)%7];
    }







    return 0;
}