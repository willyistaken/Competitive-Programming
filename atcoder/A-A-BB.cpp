#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    string news="";
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            news.append("BB");
        }else{
            news.push_back(s[i]);
        }
    }
    s="";
    int head=0;
    while(head<news.size()){
        if(news[head]=='B'&&news[head+1]=='B'){
            s.push_back('A');
            ++head;
        }else{
            s.push_back(news[head]);
        }
        ++head;
    }
    cout<<s<<endl;
}