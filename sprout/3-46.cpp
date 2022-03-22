#include <bits/stdc++.h>
using namespace std;
struct color {
    unsigned short x;
    unsigned short y;
    char c;
    unsigned short t;
};
char target;
int count_target = 0;
char colortobit(char& c) {
    switch (c) {
        case 'R':
            return 4;
        case 'B':
            return 2;
        case 'Y':
            return 1;
        case 'P':
            return 6;
        case 'G':
            return 3;
        case 'O':
            return 5;
        case 'D':
            return 7;
        default:
            return 0;
    }
}
void printmap(vector<vector<char> > &arr){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<(int) arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool inbound(short x,short y,short n){
    if(x<n && 0<=x){
        if(y<n && 0<=y){
            return true;
        }
    }
    return false;
}
vector<short> dx{-1,-1,-1,0,0,1,1,1};
vector<short> dy{1,0,-1,1,-1,1,0,-1};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    short t;
    cin >> t;
    while (t--) {
        count_target = 0;
        short n;
        cin >> n;
        queue<color> master;
        char colortemp; 
        vector<vector<char>> colormap(n, vector<char>(n,0));
        for (int i = 0; i < 3; i++) {
            cin >> colortemp;
            short xtemp, ytemp;
            cin >> xtemp >> ytemp;
            master.push({xtemp, ytemp,colortobit(colortemp), 0});
            colormap[xtemp][ytemp] = colortobit(colortemp);
        }
        cin >> colortemp;
        target = colortobit(colortemp);
       
        int maxcount =0;
        count_target=(target==1 || target==2 || target==4);
        short timenow = 0;
        while (!master.empty()) {
            while(!master.empty() && (short) master.front().t == timenow){
              
            for(int i=0;i<=7;i++){
             if(inbound((short) master.front().x+dx[i],(short)master.front().y+dy[i],n)){
            if((colormap[ master.front().x+dx[i]][master.front().y+dy[i]] | master.front().c ) !=colormap[(short) master.front().x+dx[i]][(short) master.front().y+dy[i]]){
                if ((colormap[master.front().x+dx[i]][master.front().y+dy[i]] == target)) --count_target;
                     colormap[master.front().x+dx[i]][master.front().y+dy[i]] |= master.front().c;
                if (colormap[master.front().x+dx[i]][master.front().y+dy[i]]==target) ++count_target;
                 master.push({(short) (master.front().x)+(dx[i]),(master.front().y)+(dy[i]),colormap[master.front().x+dx[i]][master.front().y+dy[i]],(unsigned short) master.front().t+1});
                         }
            
            }
            }
           // cout<<master.front().x<<" "<<master.front().y<<" "<<master.front().t<<endl;
            master.pop();    
            }
           // printmap(colormap);
            maxcount=max(maxcount,count_target);
            ++timenow;
            // cout<<"\n";
        }
        cout << maxcount << endl;
    }
}
