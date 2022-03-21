;
    short t;
};
bitset<3> target;
int count_target = 0;
bitset<3> colortobit(char& c) {
    switch (c) {
        case 'R':
            return bitset<3>("100");
        case 'B':
            return bitset<3>("010");
        case 'Y':
            return bitset<3>("001");
        case 'P':
            return bitset<3>("110");
        case 'G':
            return bitset<3>("011");
        case 'O':
            return bitset<3>("101");
        case 'D':
            return bitset<3>("111");
        default:
            return bitset<3>("000");
    }
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
        for (int i = 0; i < 3; i++) {
            cin >> colortemp;
            short xtemp, ytemp;
            cin >> xtemp >> ytemp;
            master.push(color(xtemp, ytemp, colortobit(colortemp), 0));
        }
        cin >> colortemp;
        target = colortobit(colortemp);
        vector<vector<bitset<3>>> colormap(n, vector<bitset<3>>(n));
        int maxcount = 0;
        short timenow = 0;
        while (!master.empty()) {
            while((short) master.front().t == timenow){
                if ((colormap[master.front().x][master.front().y] == target)) --count_target;
             colormap[master.front().x][master.front().y] |= master.front().c;
            if (colormap[master.front().x][master.front().y]==target) ++count_target;
            for(int i=0;i<=7;i++){
             if(inbound((short) master.front().x+dx[i],(short)master.front().y+dy[i],n)){
            if((colormap[(short) master.front().x+dx[i]][master.front().y+dy[i]] | master.front().c) !=colormap[(short) master.front().x+dx[i]][(short) master.front().y+dy[i]]){
                 master.push(color((short) (master.front().x)+(dx[i]),(short) (master.front().y)+(dy[i]),master.front().c,master.front().t));
                         }
            
            }
     master.pop();
            
            }       
                
           
            }
            maxcount=max(maxcount,count_target);
            ++timenow;
            // cout<<"\n";
        }
        cout << maxcount << endl;
    }
}
