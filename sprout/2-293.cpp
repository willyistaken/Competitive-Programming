#include <bits/stdc++.h>
using namespace std;
int dfs(int n,
        int from,
        const vector<vector<int>>& side,
        vector<int>& maxsub,
        vector<bool>& traveled) {
    // cout<<"dfs!\n";
    int all = 0;
    int max = 0;
    int fromind;
    traveled[from] = 1;
    for (int i = 0; i < side[from].size(); i++) {
        if (!traveled[side[from][i]]) {
            int an = dfs(n, side[from][i], side, maxsub, traveled);
            all += an;
            // subtreesize[from][i]=an;
            if (an >= max) {
                max = an;
            }
        } else {
            fromind = i;
        }
    }
    if (n - all - 1 > max) {
        max = n - all - 1;
    }
    maxsub[from] = max;
    delete(&all);
    delete(&max);
    delete(&fromind);
    // subtreesize[from][fromind]=n-all-1;
    return all + 1;
}

/* int horrible(int n,int q,const vector<vector<int> > &side, vector<vector<int>
> &maxsubtreesize()){ int max=0;

} */
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> side(n);
        // vector<vector<int>>subtreesize(n);
        vector<int> maxsub(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            side[a].push_back(b);
            // subtreesize[a].push_back(0);
            side[b].push_back(a);
            // subtreesize[b].push_back(0);
        }
        vector<bool> traveled(n, 0);
        dfs(n, n - 1, side, maxsub, traveled);
        int min = 1e9;
        int minn = -1;
        for (int i = n - 1; i >= 0; i--) {
            int j = maxsub[i];
            if (j <= min) {
                min = j;
                minn = i;
            }
        }
        /* for(auto i:subtreesize){
            for(auto asd:i){
                cout<<asd<<",";
            }
            cout<<endl;
        } */
        cout << minn << endl;
    }
}