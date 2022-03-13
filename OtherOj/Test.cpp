#include <bits/stdc++.h>
using namespace std;




int main(){
    auto begin = chrono::high_resolution_clock::now();
    int n=0;
    for(int i=0;i<1e9;++i){
        ++n;
    }
    cout<<n<<endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> time=end-begin;
    cout<<time.count()<<"s"<<endl;
  

    
}