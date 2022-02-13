#include <bits/stdc++.h>
using namespace std;
bool noway=0;
long long mod = 1000000007;
// specialization of nnnnnnnnn...... or uuuuuuuuu.......
int fib[100005]={0};
int fib_n(int n){
    if(n<=1){
        return 1;
    }
    else{
        if(fib[n]){
            return fib[n];
        }
        fib[n]=(fib_n(n-1)+fib_n(n-2))%mod;
        return fib[n];
    }
}
long long ans(string s){
    if(noway){
        return 0;
    }
    int i = s.size();
    if(i<=1){
        if(i==1){
            if(s[0]=='m' || s[0]=='w'){
                noway=true;
                return 0;
            }
        }
        return 1;
    }
    //specialization of nnnnnnnnn..... or uuuuuuu....... (from 3*log(n) → memorization nlog(n) #faster)
    if(s.find_first_not_of(s[0]) == string::npos&&(s[0]=='n'||s[0]=='u')){
        return fib_n(i);
    }
    string a = s.substr(0,i/2);
    string b = s.substr(i/2,i-(i/2));
    if(a[(i/2)-1]==b[0] &&(a[(i/2)-1]=='u'||a[(i/2)-1]=='n')){
        return (((ans(a.substr(0,a.size()-1))*ans(b.substr(1,b.size()-1)))%mod)+((ans(a)*ans(b))%mod))%mod;
    }else{
        return (ans(a)*ans(b))%mod;
    }

}
int main(){
    string s;cin>>s;
    if(noway){
        cout<<0<<'\n';
    }else{
      cout<<ans(s)<<'\n';  
    }
    
}

//o(log(n)) log(n) of recurtion algorithm