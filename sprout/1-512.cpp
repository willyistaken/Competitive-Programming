#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    bool pass=1;
    stack<int> tube;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x<0){
            if(tube.empty()){
                pass=0;
                break;
            }else{
                if(tube.top()==-x){
                    tube.pop();
                }else{
                    pass=0;
                    break;
                }
            }
        }else{
            tube.push(x);
        }
    }
    if(pass && tube.empty()){
        cout<<"weed"<<endl;
    }else{
        cout<<"lose light light"<<endl;
    }
}