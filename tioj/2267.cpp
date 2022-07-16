#pragma GCC optimize("Ofast")
#include<cstdio>
using namespace std;
typedef long long ll;
int n;

int main(){
    scanf("%d",&n);
	char s[n+5];
	scanf("%s",s);
    if(n==1){
        puts("Yes");
        return 0;
    }
    if(n==2 ){
        if(s[0]!=s[1]){
        	puts("No");
        }else{
        	puts("Yes");
        }
        return 0;
    }
    if(n%3==2){
        bool xo = (s[0]=='1');
        for(int i=1;i<n;i++){
            if(i%3!=2){
                xo^=(s[i]=='1');
            }
        }
        if(xo){
        	puts("No");
        }else{
        	puts("Yes");
        }
    }else{
        puts("Yes");
    }

//the solution by npsc is wrong?(it should be xor == 1 → no)
    return 0;
}
