#include <bits/stdc++.h>
using namespace std;
vector<int> len;
int br[1005][100];
void reset(){
    for(int i=0;i<1005;i++){
        for(int j=0;j<100;j++){
            br[i][j]=0;
        }
    }
}
bool b(int s,int m){
    if(s==0){
        return 1;
    }
    if(m==0){
        return 0;
    }
    if(s<0 || m<0){
        return 0;
    }
    if(br[s][m]){
        return (br[s][m]-1);
    }
    br[s][m]= (b(s-len[m],m-1)||b(s,m-1))+1;
    return (b(s-len[m],m-1)||b(s,m-1));
}
int main(){
    string ma[2]={"NO","YES"};
    int t;cin>>t;
    while(t--){
        reset();
        len.clear();
        int l;cin>>l;
        int n;cin>>n;
        len.push_back(0);
        for(int i=0;i<n;i++){
            int m;cin>>m;
            len.push_back(m);
        }
        cout<<ma[(int) b(l,n)]<<endl;
    }
}