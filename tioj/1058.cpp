#pragma GCC optimize("Ofast")
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
inline void print(string t){
    for(int i=0;i<t.size();i++){
        putchar(t[i]);
    }
    putchar('\n');
}
int main(){
    string a;
    string b; 
    cin>>a>>b;
    int tempa,tempb;
    tempa = stoi(a);
    tempb = stoi(b);
    if(tempa>tempb){
        print(a);
        return 0;
    }
    if(tempb>tempa){
        print(b);
        return 0;
    } 

    for(int i=0;i<min(a.size(),b.size());i++){
        if(b[i]-'0'>a[i]-'0'){
                    print(b);
                    return 0;
            }
            if(a[i]-'0'>b[i]-'0'){
                    print(a);
                    return 0;
                }
        }
        if(a.size()>b.size()){
            print(a);
        }else{
            print(b);
        }

        








    return 0;
}