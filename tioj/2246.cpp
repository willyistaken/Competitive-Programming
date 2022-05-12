#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,r;cin>>n>>r;
    map<pair<int,int>,bool> count;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        for(int i=-r;i<=r;i++){
            for(int j=-r;j<=r;j++){
                if(((i*i)+(j*j))<=r*r){
                    if(count.count({x+i,y+j})) {
                        count.erase({x+i,y+j});
                    }else{
                     count.insert({{x+i,y+j},1});
                    }    
                }
            }
        }

    }

    cout<<count.size()<<endl;





    return 0;
}