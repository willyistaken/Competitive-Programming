#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
typedef long long ll;
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
inline void W(int a){ if(OP>65520) { write(1,OB,OP); OP=0; } if(a<=0){ if(a==0){ OB[OP++]='0'; OB[OP++]='\n'; return ; } OB[OP++]='-'; OB[OP++]='1'; OB[OP++]='\n'; return ; } char TB[10];int g=0; while(a){ TB[g++] = (char)('0'+a%10); a/=10; } while(g--){ OB[OP++]=TB[g]; } OB[OP++]='\n'; } 
typedef long long ll; 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    while(n=R(),n!=0){ 
        int arr[n][n]; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) arr[i][j] = R();

        }
        int q = R();
        while(q--){
            int x0,x1,y0,y1;
            x0 = R();
            x1 = R();
            y0 = R();
            y1 = R();
            int m=0;int number=0;
            for(int i=x0;i<=x1;i++){
                for(int j=y0;j<=y1;j++){
                    if(number==0) {
                        m = arr[i][j];
                    }else if(m!=arr[i][j]){
                        number-=2; 
                    }
                    number++;
                }
            }
            int cnt=0;
            int size=0;
            for(int i=x0;i<=x1;i++){
                for(int j=y0;j<=y1;j++){
                    if(arr[i][j]==m) cnt++;
                    size++;
                }
            }
            printf("%d\n",(cnt>size/2)?m:-1);
        } 
    }
    //write(1,OB,OP);

    return 0;
}
