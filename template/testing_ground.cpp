#include<bits/stdc++.h>
using namespace std;
char G[4][4] ;
int l[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},
                {1,4,7},{2,5,8},{0,4,8},{2,4,6}} ;
bool line(char c)
{
    char s[9] ;
    for(int i=0;i<9;i++) s[i]=G[i/3][i%3] ;
    for(int i=0;i<8;i++)
    {
        bool all=1 ;
        for(int j=0;j<3;j++) if(s[l[i][j]]!=c) all=0 ;
        if(all) return 1 ;
    }
    return 0 ;
}
 
bool solve()
{
    int a=0 , b=0 ;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++)
    {
        if(G[i][j]=='O') a++ ;
        else if(G[i][j]=='X') b++ ;
        else if(G[i][j]!='.') return 0 ;
    }
	cout<<a<<b<<line('X')<<line('O')<<endl;
    return (a==b && !line('X')) || (a==b+1 && !line('O')) ;
}
 
main()
{
    for(int i=0;i<3;i++) scanf("%s",G[i]) ;
    if(solve()) printf("POSSIBLE\n") ;
    else printf("IMPOSSIBLE\n") ;
}