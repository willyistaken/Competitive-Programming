#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ans{
    bool f1;
    bool f2;
    bool f3;
};

ans eval(bool* A){
    ans result;
    result.f1 =  (A[0] & A[1]) || (A[1] & A[2]);
    result.f2 =  (A[1] & A[2]) || (A[2] & A[3]);
    result.f3 =  (A[2] & A[3]) || (A[3] & A[4]);
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    bool A[5];
    bool B[3];
    string t;
    while(cin>>t){
        if(t.size()==5){
         for(int i=0;i<5;i++) A[i] = (t[i]=='1');
         ans r = eval(A);
        cout<<r.f1<<r.f2<<r.f3<<endl;   
        }else{
            for(int i=0;i<3;i++) B[i] = (t[i]=='1');        
            int ways=0;
            for(int i=0;i<32;i++){
                for(int j=0;j<5;j++){
                    A[j] = (i>>j)&1;
                }
                ans r = eval(A);
                if( (r.f1 == B[0]) && (r.f2 == B[1]) && (r.f3 == B[2])){
                            ways++;
                }
            }
            cout<<ways<<endl;
        }
        
    }







    return 0;
}