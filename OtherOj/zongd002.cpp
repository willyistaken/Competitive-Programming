#include <bits/stdc++.h>
using namespace std;
int eval(){
    string s;cin>>s;
    if(s=="h"){
        int x=eval();
        int y=eval();
        int z=eval();
        return 3*x-2*y+z;
    }
    if(s=="f"){
        int x=eval();
        return 2*x-3;
    }
    if(s=="g"){
        int x=eval();
        int y=eval();
        return 2*x+y-7;
    }
    return stoi(s);

}
int main(){
    cout<<eval()<<endl;
}