#include <bits/stdc++.h>
using namespace std;
 
int n, r, used[10];
vector <long long> v;
 
void f(int pos, long long now){
    if (pos == r){
        v.push_back(now);
        return;
    }
    for (int i = 0; i < n; i++){
        if (used[i]) continue;
        used[i] = 1;
        now *= 10;
        now += i;
        f(pos+1, now);
        now /= 10;
        used[i] = 0;
    }
}
 
int main(){
    cin >> n >> r;
    f(0, 0);
    if (v.size() < (n+r)) cout << v[0] << "\n";
    else cout << v[v.size()-(n+r)] << "\n";
}
