#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string t,s;
void init(int f[]){
    f[0]=-1;
    for(int i=1;i<s.size();i++){
        if(s[i]=='*'){
            f[i] = f[i-1]+1;
            continue;
        }
        int now = i-1;
        while(now>=0){
            if(s[f[now]+1]==s[i]) break;
            now = f[now];
        } 
        if(now>=0) f[i] = f[now]+1;
        else f[i]=-1;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin,t);
    getline(cin,s);
    int faliure[s.size()];
    init(faliure);
    int head=0;
    for(int i=0;i<t.size();i++){
        if(s[head]==t[i] || s[head]=='*'){
            if(head==s.size()-1){
                cout<<"Asssssss!!!!!\n";
                return 0;
            }else {
                head++;
            }
        }else{
            head = faliure[head]+1;
        }
    }
    cout<<"zzz...\n";
    return 0;
}