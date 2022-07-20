#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;
 
int f[maxn],d[maxn],t[maxn] ;
priority_queue< int,vector<int>,greater<int> > pq ;
 
main()
{
    int T,n ;
    while(scanf("%d%d",&T,&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&f[i]) ;
        for(int i=1;i<=n;i++) scanf("%d",&d[i]) ;
        for(int i=1;i<=n;i++) scanf("%d",&t[i]) ;
        LL ans=0LL , sum=0LL ;
        while(!pq.empty()) pq.pop() ;
        for(int i=1;i<=n;i++)
        {
            T-=t[i] ;
            while(T<0 && !pq.empty())
                sum-=pq.top() , pq.pop() , T++ ;
            if(T<0 || (T==0 && pq.empty())) break ;
            for(int j=0;;j++)
            {
                int val=f[i]-j*d[i] ;
                if(val<=0) break ;
                if(T>0) pq.push(val) , sum+=val , T-- ;
                else if(pq.top()<val)
                    sum+=val-pq.top() , pq.pop() , pq.push(val) ;
                else break ;
            }
            ans=max(ans,sum) ;
        }
        printf("%lld\n",ans) ;
    }
}
 
