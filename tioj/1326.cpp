#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cor{
    int x;
    int y;
};
struct side{
    int from;
    int to;
    int w;
};
int query(int ind,vector<int> &father){
    if(father[ind]==ind) return ind;
    father[ind]=query(father[ind],father);
    return father[ind];
}
void join(int a,int b,vector<int> &father){
    father[query(a,father)] = query(b,father);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    cor arr[n];
    for(int i=0;i<n;i++){
        cor temp;cin>>temp.x>>temp.y;
        arr[i]=temp;
    }
    sort(arr,arr+n,[](const cor &a,const cor &b){return (a.x<b.x || (a.x==b.x && a.y<b.y));});
    int lastofy[1050];
    fill(lastofy,lastofy+1050,-1);
    vector<side> sides;
    lastofy[arr[0].y]=0;
    vector<int> father(n);
    for(int i=0;i<n;i++) father[i]=i;
    for(int i=1;i<n;i++){
        if(arr[i].x==arr[i-1].x){
            sides.push_back({i,i-1,arr[i].y-arr[i-1].y});
        }
        if(lastofy[arr[i].y]>=0){
            sides.push_back({i,lastofy[arr[i].y],arr[i].x-arr[lastofy[arr[i].y]].x});
        }
        lastofy[arr[i].y]=i;
    } 
    sort(sides.begin(),sides.end(),[](const side &a,const side &b){return a.w<b.w;});
    int ans=0;
    for(int i=0;i<sides.size();i++){
        if(query(sides[i].to,father)!=query(sides[i].from,father)){
            ans+=sides[i].w;
            join(sides[i].to,sides[i].from,father);
        }
    }
    cout<<ans<<endl;
    }


    return 0;
}