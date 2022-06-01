#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;getline(cin,s);
    int n=0;
    for(auto i : s){
        if(!('0'<=i && i<='9')){
            n=max(n-1,0);
            for(int j=0;j<n+1;j++) putchar(i);
            n=0;
        }else{
            n*=10;
            n+=i-'0';
        }
    }
    printf("\n");







    return 0;
}