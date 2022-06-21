#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
     srand( time(NULL) );
    int n = rand();
    n%=10;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        int a=rand();
        int b = rand();
        int c = rand();
        int d = rand();
        a%=20; b%=20; c%=20; d%=20;
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        printf("%d %d %d %d\n",a,b,c,d);
    }







    return 0;
}