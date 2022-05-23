#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const mod = 1e9+7;
struct matrix{
    int w;
    int h;
    vector<vector<int>> arr;
    void init(){
        for(int i=0;i<this->h;i++){
            arr.push_back(vector<int>(this->w,0)); 
        }
    }
};

matrix operator*(const matrix &a,const matrix &b){
    assert(a.w==b.h);
    matrix re;
    re.h = a.h;
    re.w=b.w;
    re.init();
    for(int i=0;i<re.h;i++){
        for(int j=0;j<re.w;j++){
            for(int k=0;k<b.h;k++){
                re.arr[i][j]+=(1LL*a.arr[i][k]*b.arr[k][j])%mod;
                re.arr[i][j]%=mod;
            }
        }
    }
    return re;
}

bool operator==(const matrix &a,const matrix &b){
    if(a.h!=b.h || a.w!=b.w) return false;
    for(int i=0;i<a.h;i++){
        for(int j=0;j<a.w;j++){
            if(a.arr[i][j]!=b.arr[i][j]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    matrix A;
    matrix B; 
    matrix C; 
    matrix R;
    int N,M,K;
    cin>>N>>M>>K;
    A.h = N; A.w=M; B.h=M; B.w=K; C.h=N;C.w=K; R.w=1;R.h=K;
    A.init();B.init();C.init();R.init();
    random_device rd;
    mt19937 gen(rd()); 
    //uniform_int_distribution<> distr(1 , 10); 賭徒版 10%機率WA 
    uniform_int_distribution<> distr(1 , (int)1e7);
    for(int i=0;i<K;i++){
        R.arr[i][0]=distr(gen);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A.arr[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++){
            cin>>B.arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cin>>C.arr[i][j];
        }
    }
    matrix one = C*R;
    matrix two = B*R;
    two = A*two;
    if(one==two){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}