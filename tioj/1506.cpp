#include <bits/stdc++.h>
using namespace std;

int main(){
    double a1,a2,b1,b2;cin>>a1>>a2>>b1>>b2;
    if(a1==0 || a2==0){
        if(a1){

     cout<<setprecision(2)<<fixed<<(b2-b1)/(a1)<<endl<<b2<<endl;   
        }else{

     cout<<setprecision(2)<<fixed<<(b1-b2)/(a2)<<endl<<b1<<endl;   
        }
    }else{
     cout<<setprecision(2)<<fixed<<(b2-b1)/(a1-a2)<<endl<<((a2*b1/a1)-b2)/((a2/a1)-1)<<endl;   
    }
    






    
}