#include <bits/stdc++.h>
using namespace std;
char flip(char k){
    if(k=='R'){
        return 'B';
    }
    if(k=='B'){
        return 'R';
    }

    return '?';
}
string alts(int n){
    string s="R";
    for(int i=1;i<n;i++){
        if(i%2==1){
            s+="B";
        }else{
            s+="R";
        }
    }
    return s;
}
int main(){
    int t;cin>>t;
    while(t--){
            int n;cin>>n;
    string s;cin>>s;
    bitset<105> in;
     for(int i=0;i<n;i++){
            if(s[i]!='?'){
                in.set(i);
            }
     }
     if(!in.any()){
         s=alts(n);
     }
    while(s.find('?')!=string::npos){
        for(int i=0;i<n;i++){
            if(s[i]!='?'){
                if(i-1>=0 && !in[i-1]){
                    s[i-1]=flip(s[i]);
                }
                if(i+1<n && !in[i+1]){
                    s[i+1]=flip(s[i]);
                }
            }
        }
    }
    cout<<s<<endl;
    }

}