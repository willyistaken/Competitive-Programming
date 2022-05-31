#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct road{
    int from;
    int to;
    int w;
};
int query(int a,vector<int> &father){
    if(father[a]==a) return a;
    father[a]= query(father[a],father);
    return father[a];
}
void join(int a,int b,vector<int> &father){
    father[query(a,father)] = query(b,father);
    return ;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    road arr[m];
    vector<int> father(n+1);
    for(int i=0;i<m;i++) {
        road temp;
        cin>>temp.from>>temp.to>>temp.w;
        arr[i]=temp;
    }  
    sort(arr,arr+m,[](const road &a,const road &b){return a.w<b.w;});
    for(int i=0;i<=n;i++) father[i]=i;
    int ans=0;
    for(int i=0;i<m;){
        int howmanyworks=0;
        int lastwork=-1;
        int wnow=arr[i].w;
        while(arr[i].w==wnow){
            if(query(arr[i].from,father)!=query(arr[i].to,father)){
                howmanyworks+=1;
                lastwork=i;
            }
            i+=1;
        }
        ans+=howmanyworks-1;
        if(lastwork>0) join(arr[lastwork].from,arr[lastwork].to,father);
    }
    cout<<min(m-n+1,ans)<<endl;




    return 0;
}

/*
6 10
1 2 3
1 3 3
2 3 2
2 4 5
2 5 2
3 4 4
3 5 1
3 6 1
4 5 4
5 6 1
*/

/*
3 3
1 2 1
2 3 1
3 1 1
*/