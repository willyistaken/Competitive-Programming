#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    srand( time(NULL) );
    int n = rand()%20;int q=rand()%20;
    cout<<n<<" "<<q<<endl;
    for(int i=0;i<n;i++){
        cout<<2*rand()<<" ";
    }
    cout<<endl;
    for(int i=0;i<q;i++){
        int type=rand()%2;
        if(type){
            cout<<2<<" ";
            int l=rand()%n +1;
            int r=rand()%n +1;
            if(l>r) swap(l,r);
            cout<<l<<" "<<r<<endl;
        }else{
            cout<<1<<" ";
            int l=rand()%n +1;
            int r=rand()%n +1;
            if(l>r) swap(l,r);
            int v = rand();
            cout<<l<<" "<<r<<" "<<v<<endl;
        }
    }





    return 0;
}