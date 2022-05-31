#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sides{
    int from;
    int to;
    int w;
};
int query(int a,vector<int> &father){
    if(father[a]==a) return father[a];
    father[a]= query(father[a],father);
    return father[a];
}
void join(int a,int b,vector<int> &father){
    father[query(a,father)] = query(b,father);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector<int> father(n+1);
    for(int i=0;i<=n;i++) father[i]=i;
    vector<sides> arr;
    for(int i=1;i<=n;i++){
        int c;cin>>c; 
        sides temp;
        temp.from=0;
        temp.to=i;
        temp.w=c; 
        arr.push_back(temp);
    }
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        sides temp;
        temp.from=a;
        temp.to=b; 
        temp.w=w;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),[](const sides &a,const sides &b){return a.w<b.w;});
    ll ans=0;
    for(auto i : arr){
        if(query(i.from,father)!=query(i.to,father)){
            ans+=i.w;
            join(i.from,i.to,father);
        }
    }
    cout<<ans<<endl;



    return 0;
}


/*
9 10
3 1 4 1 5 9 2 6 5
3 1 4
1 5 9
2 6 5
3 5 8
9 7 9
3 2 3
8 4 6
2 6 4
3 3 8
3 2 7
*/