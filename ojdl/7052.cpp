#include <bits/stdc++.h>
using namespace std;
const int mod = 20191126;
struct matrix {
    vector<vector<int> > val{{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,1}};
    matrix operator*(matrix b) {
        matrix ans ;
        ans.val = vector<vector<int> >(6,vector<int>(6,0));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                for (int k = 0; k < 6; k++) {
                    ans.val[i][j] += (1LL * val[i][k] * b.val[k][j]) % mod;
                    ans.val[i][j] %= mod;
                }
            }
        }
        return ans;
    }
    void printout(){
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                cout<<val[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
};


matrix one;

map<long long,matrix> ac;

matrix fast_n(matrix a, long long n) {
    if(ac.count(n)) return ac[n];
    matrix element;
    if(n==0){
        ac.insert(make_pair(n,element));
      return element;  
    } 
    if (n == 1) return a;
    if(n%2){
        element = fast_n(a,n/2)*fast_n(a,(n/2)+1);
        ac.insert(make_pair(n,element));
        return element;  
    }
    element = fast_n(a,n/2)*fast_n(a,n/2);
      ac.insert(make_pair(n,element));
    return element;  
}
long long eval(int k,long long n) {
    matrix original;
    original.val = vector<vector<int> >{{0,1,0,0,0,0},{1,1,0,0,0,0},{1,1,1,0,0,0},{1,1,1,1,0,0},{1,1,1,1,1,0},{1,1,1,1,1,1}};
    matrix storeans = fast_n(original,n-1);
    //storeans.printout();
    long long realans=0;
    for(int i=1;i<6;i++){
        realans+=storeans.val[k+1][i]%mod;
        realans%=mod;
    }
    return realans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k, n;
        cin >> k >> n;
        cout<<eval((int) k,n)<<endl;
        
    }
}
