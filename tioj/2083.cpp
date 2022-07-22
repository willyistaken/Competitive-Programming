// =＾● ⋏ ●＾=
#include<bits/stdc++.h>
using namespace std;
#define small int

small a[10][10],b[10][10];

int main(){
    int n; cin>>n;
    for(small i=0;i<n;++i)for(small j=0;j<n;++j)cin>>a[i][j];
    for(small i=0;i<n;++i)for(small j=0;j<n;++j)cin>>b[j][i];
    int cnt=0;
    for(small i=0;i<n;++i)for(small j=0;j<n;++j)for(small k=0;k<n;++k)cnt+=a[i][k]*b[j][k];
    cout<<cnt%5<<endl;
}
