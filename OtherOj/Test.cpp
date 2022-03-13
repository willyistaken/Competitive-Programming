#include <bits/stdc++.h>
using namespace std;


void foreach(int vaule,void(*func)(int)){
    for(int i=0;i<vaule;i++){
        func(i);
    }
}



int main(){
    auto begin = chrono::high_resolution_clock::now();
    /* auto lambda = [](int vaule){ using namespace std; cout<<vaule+1<<endl;} ;
    foreach(10,lambda); */
    for(int i=0;i<10;i++){
        cout<<i+1<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> time=end-begin;
    cout<<time.count()<<"s"<<endl;
    
}