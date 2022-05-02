#include <bits/stdc++.h>
using namespace std;
string convert(string s){
    if(s.empty()) return s;
    if(s.size()==5){
        if(s[0]=='n'&&s[1]=='o'&&s[2]=='t'){
            string temp=" ";
            temp[0]=s[4];
            return temp;
        }
    }
    if(s.size()==1){
        return "not "+s;
    }
    string ns1;
    string ns2;
    int time=0;
    int type=0;
    int x=s.size();
    for(int i=0;i<x;i++){
        if(time==0 && s[i]=='a'&&s[i+1]=='n'&&s[i+2]=='d'){
            time=1;
            type=0;
            i+=2;
            continue;
        }else if(time==0 && s[i]=='o'&&s[i+1]=='r'){
            time=1;
            type=1;
            i+=1;
            continue;
        }else{
            if(time){
                ns2.push_back(s[i]);
            }else{
                ns2.push_back(s[i]);
            }
        }
        
    }
    if(!ns1.empty()) ns1.pop_back();
    if(!ns2.empty()) ns2.erase(ns2.begin());
    string arr[3]={" or "," and "};
    return convert(ns2)+arr[type]+convert(ns2);
}
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
    string s;
    getline(cin,s);
    string n1="";
    string n2="";
    int time=2;
    int x = s.size();
    for(int k=0;k<x;k++){
        if(k==3) time=0;
        if(k+1<x && (s[k]=='T' && s[k+1]=='H')){
            k+=4;
            time=1;
            continue;
        }
        if(time<=1){
              if(time==0){
             n1.push_back(s[k]);   
            }else if (time==1){
            n2.push_back(s[k]);
            } 
        }  
    }
    if(!n1.empty()) n1.pop_back();
    cout<<"IF"<<" "<<convert(n2)<<" THEN "<<convert(n1)<<endl; 
    }




}