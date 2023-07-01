#pragma GCC optimize("Ofast")
#include <cstdio>
using namespace std;
typedef long long ll;

bool arr[2187][2187];
int pow3[8] = {1,3,9,27,81,243,729,2187};
void carpet(int k,int cx,int cy){
    if(k==1){
        arr[cx+1][cy+1]=1;
        return ;
    }
    int side = pow3[k-1];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            carpet(k-1,cx+i*side,cy+j*side);
        }
    }
    for(int i=cx+side;i<cx+2*side;i++){
        for(int j=cy+side;j<cy+2*side;j++){
            arr[i][j]=1;
        }
    }
}


int main(){
    int n;scanf("%d",&n);
    int side = pow3[n];
    carpet(n,0,0);
    for(int i=0;i<side;i++){
        for(int j=0;j<side;j++){
            printf("%c",".#"[arr[i][j]]);
        }
        printf("\n");
    }






    return 0;
}
