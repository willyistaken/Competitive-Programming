#include <iostream>
using namespace std;

int main(){
int ans=0;
int a,b;cin>>a>>b;
if(b==2 | b==5| b==8){
    cout<<200;
    return 0;
}
if(a%2==1){
    cout<<100;
    return 0;
}
if(a==b){
    cout<<50;
    return 0;
}
cout<<0;
}