#include <bits/stdc++.h>
using namespace std;
/*
三振的 K (Strikeout)，代表保送的 W (Walk)，以及一壘安打 S (Single)，二壘安打 D
(Double)，三壘安打 T (Three bases?)，全壘打 H (Home Run)以及其他的出局狀況 O
*/
int main() {
    string k;
    while (cin >> k) {
        int score[2] = {0};
        bool f, s, t;
        f = s = t = 0;
        bool rob = 0;
        int out = 0;
        for (auto c : k) {
            switch (c) {
                case ('K'):
                    ++out;
                    if (out >= 3) {
                        f = s = t = 0;
                        rob = !rob;
                        out = 0;
                    }
                    break;
                case ('O'):
                    ++out;
                    if (out >= 3) {
                        f = s = t = 0;
                        rob = !rob;
                        out = 0;
                    }
                    break;
                case ('W'):
                    if (f) {
                        if (s) {
                            if (t) {
                                score[rob] += 1;
                            } else {
                                t = 1;
                            }
                        } else {
                            s = 1;
                        }
                    } else {
                        f = 1;
                    }
                    break;
                case ('S'):
                    score[rob] += t;
                    t = s;
                    s = f;
                    f = 1;
                    break;
                case ('D'):
                    score[rob] += t;
                    score[rob] += s;
                    t = f;
                    s = 1;
                    f = 0;
                    break;
                case ('T'):
                    score[rob] += t;
                    score[rob] += s;
                    score[rob] += f;
                    t = 1;
                    s = 0;
                    f = 0;
                    break;
                case ('H'):
                    score[rob] += t;
                    score[rob] += s;
                    score[rob] += f;
                    score[rob] += 1;
                    t = s = f = 0;
                    break;
            }
        }
        cout << score[0] << " " << score[1] << endl;
    }
}