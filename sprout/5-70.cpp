#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
       priority_queue<long long,vector<long long>,greater<long long> > q;
    long long n;cin>>n;
    long long sum=0;
    while(n--){
        long long temp;cin>>temp;
        q.push(temp);
    }
    while(!q.empty()){
        long long a = q.top();
        q.pop();
        long long b =q.top();
        q.pop();
        sum+= a+ b;
        if(!q.empty()){
          q.push(a+b);  
        }
        
    }
    cout<<sum<<endl; 
    }
    
}