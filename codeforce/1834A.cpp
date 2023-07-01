#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

void solve() {
    int n;
    cin>>n;
    int a=0;
    int b=0;
    for(int i=0; i<n; i++) {
        int ai;
        cin>>ai;
        if(ai>0) a++;
        else b++;
    }
    if(a>=b) {
        if(b&1) cout<<1<<"\n";
        else cout<<0<<"\n";
        return ;
    }
    int time = (b-a)/2;
    time+=(b-a)%2;
    if((b+time)%2) time++;
    cout<<time<<"\n";
}


int main() {
	int a;cin>>a;				
	for(int i=0;i<a;i++){
		cout<<i<<"\n";
	}
    return 0;
}


