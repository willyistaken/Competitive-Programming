#include <bits/stdc++.h>
using namespace std;
struct monos{
    int level;
    int power;
};
int main(){
    int n;cin>>n;
    int arr[n];
    int tarr[n];
    int lrange[n];
    int rrange[n];
    stack<monos> mono;

    for(int i=0;i<n;i++){
       int tt;cin>>tt;
       arr[i]=tt;
    }
    
    for(int i=n-1;i>=0;i--){
        tarr[n-(i+1)]=arr[i];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            lrange[0]=0;
            monos temps;
            temps.level=0;
            temps.power=arr[0];
            mono.push(temps);
        }else{
            
            while(!mono.empty()&&mono.top().power <  arr[i] ){
                mono.pop();
            }
            if(mono.empty()){
                lrange[i]=0;
            }else{
                lrange[i]=mono.top().level+1;
            }
            monos tempss;
            tempss.level=i;
            tempss.power=arr[i];
            mono.push(tempss);
        }
    


    }
    while(!mono.empty()){
        mono.pop();
    }
    for(int i=0;i<n;i++){
        if(i==0){
            rrange[0]=0;
            monos temps;
            temps.level=0;
            temps.power=arr[0];
            mono.push(temps);
        }else{
            
            while(!mono.empty() && mono.top().power < arr[i]){
                mono.pop();
            }
            if(mono.empty()){
                rrange[n-i-1]=n-1;
            }else{
                rrange[n-i-1]=mono.top().level+1;
            }
            monos tempss;
            tempss.level=i;
            tempss.power=arr[i];
            mono.push(tempss);
        }
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=rrange[i]-lrange[i];
            if(rrange[i]==i){
                sum+=1;
            }
            if(lrange[i]==i){
                sum+=1;
            }
        }
        sum/=2;
        cout<<sum;



}