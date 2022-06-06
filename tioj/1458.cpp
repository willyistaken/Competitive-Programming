#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dir_x[4] = {0,1,0,-1};
int dir_y[4] = {1,0,-1,0};
inline string tobi(char a){
    if(a==' ') return "00000";
    int g= a-'A';
    g+=1;
    string temp = "00000";
    for(int i=0;i<5;i++){
        if(g&1) temp[4-i]='1';
        else temp[4-i] ='0';
        g>>=1;
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int gh=1;gh<=t;gh++){
    cout<<gh<<" ";
    int r,c;cin>>r>>c; 
    vector<vector<int> > arr(r,vector<int>(c,-1));
    string s;getline(cin,s);
    string binary="";
    for(int j=1;j<s.size();j++){
        binary+=tobi(s[j]);
    }
    int x=0;
    int y=-1;
    int id=0;
    for(int i=0;i<r*c;i++){
        int temp_x = x+dir_x[id];
        int temp_y = y+dir_y[id];
        if(temp_x>=r || temp_x<0 || temp_y>=c || temp_y<0){
            id = (id+1>=4) ? id-3:id+1;
        }else if(arr[temp_x][temp_y]>=0) {
            id = (id+1>=4) ? id-3:id+1;
        }
        x+=dir_x[id];
        y+=dir_y[id];
        arr[x][y] = (i>=binary.size()) ? 0:(binary[i]=='1');
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j];
        }
    }
    cout<<"\n";
    }




    return 0;
}