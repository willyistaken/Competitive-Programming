#include <bits/stdc++.h>
using namespace std;
struct color {
    color(uint16_t x1, uint16_t y1, bitset<3> c1, uint16_t t1)
        : x(x1), y(y1), c(c1), t(t1) {}
    uint16_t x;
    uint16_t y;
    bitset<3> c;
    uint16_t t;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    uint16_t t;
    cin >> t;
    while (t--) {
        count_target = 0;
        uint16_t n;
        cin >> n;
        queue<color> master;
        char colortemp;
        for (int i = 0; i < 3; i++) {
            cin >> colortemp;
            uint16_t xtemp, ytemp;
            cin >> xtemp >> ytemp;
            master.push(color(xtemp, ytemp, colortobit(colortemp), 0));
        }
        cin >> colortemp;
        target = colortobit(colortemp);
        vector<vector<bitset<3>>> colormap(n, vector<bitset<3>>(n));
        int maxcount = 0;
        uint16_t timenow = 0;
        while (maxcount <= count_target) {
            while (master.front().t == timenow) {
                if ((colormap[master.front().x][master.front().y] == target)) --count_target;
                colormap[master.front().x][master.front().y] |= master.front().c;
                if (colormap[master.front().x][master.front().y]==target) ++count_target;
                
                master.pop();
            }
            maxcount=max(maxcount,count_target);
            ++timenow;
            // cout<<"\n";
        }
        cout << maxcount << endl;
    }
}