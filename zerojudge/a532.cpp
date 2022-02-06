#include <bits/stdc++.h>
using namespace std;
char flip[10] = {'0','1','n','n','n','n','9','n','8','6'};
string ta(string a){
   
    a=reverse(a.begin(),a.end());
    string new="";
    for(int i=0;i<a.size();i++){
        if(flip[a[i]-'0']=='n'){
            return "no";
        }else{
            new+=flip[a[i]-'0'];
        }
    }
    return new;
}
int main(){
    long long n[1000001];
    int now=1;
    int  i=0;
    while(now<=1000000){
stringstream ss;
ss << i;
string str = ss.str();
    if(str==ta(str)){
        n[now]=i;
        now++;
    }
    i++;
    }
}