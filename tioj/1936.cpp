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
	void print(){
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cerr<<arr[i][j]<<" ";
			}
			cerr<<"\n";
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
    random_device rd;
    mt19937 gen(rd()); 
    uniform_int_distribution<> distr((int)-1e2 , (int)1e2);
	int t;cin>>t;
	while(t--){
    matrix A;
    matrix B; 
    matrix C; 
    matrix R;
	int N;
    cin>>N;
	
    A.h = N; A.w=N; B.h=N; B.w=N; C.h=N;C.w=N; R.w=1;R.h=N;
    A.init();B.init();C.init();R.init();
	matrix R2;
	R2.w=1;
	R2.h=N;
	R2.init();
    for(int i=0;i<N;i++){
        R.arr[i][0]=distr(gen);
    }
	for(int i=0;i<N;i++){
		R2.arr[i][0]=distr(gen);
	}
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A.arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>B.arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>C.arr[i][j];
        }
    }
    matrix one = C*R;
    matrix two = B*R;
    two = A*two;
	matrix one2 = C*R2;
	matrix two2 = B*R2;
	two2 = A*two2;
	//one.print();
	//two.print();
    if(one==two && one2==two2 ){
		cout<<"Loli is god.\n";
    }else{
		cout<<"QAQ!\n";
    }
	}

	// randomize algorithm, do two times to avoid overflow and randomness
    return 0;
}

