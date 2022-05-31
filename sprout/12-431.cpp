#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    ll dis1[n+1];fill(dis1,dis1+n+1,1e15);
    dis1[1]=0;
    ll disn[n+1];fill(disn,disn+n+1,1e15);
    disn[n]=0;
    bitset<200010> done;
    done.reset();
    vector<vector<pair<int,int > > > sides(n+1);
    vector<vector<pair<int,int> > > rsides(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        sides[a].push_back({b,w});
        rsides[b].push_back({a,w});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int> > ,greater<pair<ll,int> > > pq;
    pq.push({0,1});
    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();
        if(done[cur.second]) continue;
        for(auto i : sides[cur.second]){
            if(dis1[i.first]>dis1[cur.second]+i.second){
                dis1[i.first]=dis1[cur.second]+i.second;
                pq.push({dis1[i.first],i.first});
            }
        }
        done[cur.second]=1;
    }

    done.reset();

    pq.push({0,n});
    while(!pq.empty()){
        pair<ll,int> cur = pq.top();
        pq.pop();
        if(done[cur.second]) continue;
        for(auto i : rsides[cur.second]){
            if(disn[i.first]>disn[cur.second]+i.second){
                disn[i.first]=disn[cur.second]+i.second;
                pq.push({disn[i.first],i.first});
            }
        }
        done[cur.second]=1;
    }

    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b; 
        cout<<min(dis1[a]+1+disn[b],dis1[n])<<endl;
    }

    return 0;
}

/*
6 5 3
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
2 5
1 6
3 2
*/

/*
8 9 5
1 2 1
1 3 1
2 4 1
2 6 1
3 5 1
4 7 1
5 6 1
6 8 1
7 8 1
6 1
1 6
1 2
5 8
2 8
*/

/*
5 8 4
1 1 1000000000
2 1 3
1 3 5
1 4 9
4 5 8
5 4 2
3 4 3
4 5 1
2 2
1 5
1 4
3 4
*/