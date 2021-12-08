#include <bits/stdc++.h>
using namespace std;

int main(){
    string as,bs;cin>>as>>bs;
    //as="12:32:23";bs="14:23:48";
    int a[3],b[3];
    int j=0;
    for(int i=0;i<8;i++){
        

        if((i+1)%3==1){
            a[j]=(as[i]-'0')*10+(as[i+1]-'0');
            b[j]=(bs[i]-'0')*10+(bs[i+1]-'0');
            j+=1;
        }
    }
    if((a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2])){
        b[0]+=24;
    }
    for(int i=2;i>=0;i--){
        b[i]-=a[i];
        if(b[i]<0){
        if(i!=0){
            b[i-1]-=1;
            b[i]+=60;
        }
        if(b[0]<0){
            b[0]+=24;
        }
        }
    }
    for(int i=0;i<3;i++){
        if(i!=0){
            cout<<':';
        }
        if(b[i]<10){
            cout<<'0';
        }
        cout<<b[i];
}

}