#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
int n,m;
inline bool inbound(int x,int y){
    return (0<=x && x<n && 0<=y && y<m);
}
void dfs(char type,int x,int y,vector<vector<char> > &arr){
    arr[x][y]='0';
    for(int i=0;i<8;i++){
        if(inbound(x+dx[i],y+dy[i])){
            if(arr[x+dx[i]][y+dy[i]]==type){
                dfs(type,x+dx[i],y+dy[i],arr);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m){
    vector<vector<char> > arr1(n,vector<char>(m,'0'));
	vector<vector<char> > arr2(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
			if(s[j]-'0') arr1[i][j]='1';
			if(s[j]-'0'==2) arr2[i][j]='2';
        }
    }
    int dice=0;
    int point=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i][j]=='1'){
                dice+=1;
                dfs('1',i,j,arr1);
            }
            if(arr2[i][j]=='2'){
                point+=1;
                dfs('2',i,j,arr2);
            }
        }
    }


    cout<<dice<<" "<<point<<"\n";
   }



    return 0;
}


//f*ck this , this is one of the most stupid problem on tioj
//2 also means dice(it also connect 1);
