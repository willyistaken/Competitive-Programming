#include<bits/stdc++.h>
using namespace std;
const int maxn=30000+10 ;
struct P
{
    int from,to,dis;
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};
struct Q{int to,dis;};
 
int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}
 
vector<Q> v[maxn] ;
int n,dep[maxn] ;
int anc[17][maxn],ancdis[17][maxn] ;
 
void dfs(int x,int f,int d)
{
    dep[x]=d ;
    for(auto i : v[x]) if(i.to!=f)
    {
        anc[0][i.to]=x ;
        ancdis[0][i.to]=i.dis ;
        dfs(i.to,x,d+1) ;
    }
}
 
void build_LCA()
{
    memset(anc[0],-1,sizeof(anc[0])) ;
    for(int i=1;i<=n;i++) if(anc[0][i]==-1)
    {
        anc[0][i]=i ;
        ancdis[0][i]=0 ;
        dfs(i,i,0) ;
    }
    for(int i=1;(1<<i)<=n;i++) for(int j=1;j<=n;j++)
        anc[i][j]=anc[i-1][anc[i-1][j]] ,
        ancdis[i][j]=max(ancdis[i-1][j],ancdis[i-1][anc[i-1][j]]) ;
}
 
void query_fa(int x,int num,int &ans,int &dis)
{
    if(!num) { ans=x ; dis=0 ; return ; }
    dis=0 ;
    for(int i=16;i>=0 && num;i--) if(num&(1<<i))
        dis=max(dis,ancdis[i][x]) , x=anc[i][x] ,
        num^=(1<<i) ;
    ans=x ;
}
 
int LCA(int x,int y)
{
    if(x==y) return 0 ;
    if(dep[x]>dep[y])
    {
        int f,d ;
        query_fa(x,dep[x]-dep[y],f,d) ;
        return max(d,LCA(f,y)) ;
    }
    if(dep[x]<dep[y])
    {
        int f,d ;
        query_fa(y,dep[y]-dep[x],f,d) ;
        return max(d,LCA(x,f)) ;
    }
    int ret=0 ;
    for(int i=15;i>=0;i--) if(anc[i][x]!=anc[i][y])
        ret=max(ret,max(ancdis[i][x],ancdis[i][y])) ,
        x=anc[i][x] , y=anc[i][y] ;
    return max(ret,max(ancdis[0][x],ancdis[0][y])) ;
}
 
vector<P> edge ;
int main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        edge.push_back((P){x,y,dis}) ;
    }
    sort(edge.begin(),edge.end()) ;
    for(int i=1;i<=n;i++) fa[i]=i ;
    for(auto i : edge)
    {
        int x=getfa(i.from) , y=getfa(i.to) ;
        if(x==y) continue ;
        fa[x]=y ;
        v[i.from].push_back((Q){i.to,i.dis}) ;
        v[i.to].push_back((Q){i.from,i.dis}) ;
    }
 
    build_LCA() ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(getfa(x)!=getfa(y)) printf("-1\n") ;
        else printf("%d\n",LCA(x,y)) ;
    }
}
