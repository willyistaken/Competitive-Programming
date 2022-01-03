#include <bits/stdc++.h>
using namespace std;

string result[51][51];
string lcs(string a,string b){
    int al=a.size();
    int bl = b.size();
    if(a.empty() || b.empty()){
        return "";
    }
    if(!result[al][bl].empty()){
        return result[al][bl];
    }
    int am=lcs(a.substr(0,al-1),b).size();
    int bm=lcs(a,b.substr(0,bl-1)).size();
    
    if(a[al-1]==b[bl-1]){
        result[al][bl]=lcs(a.substr(0,al-1),b.substr(0,bl-1))+a[al-1];
        return result[al][bl];
    }else{
        if(am>bm){
            result[al][bl]=lcs(a.substr(0,al-1),b);
        }else{
            result[al][bl]= lcs(a,b.substr(0,bl-1));
        }
        return result[al][bl];
    }
    
}
int main(){
string x,y;cin>>x>>y;
cout<<(lcs(x,y).empty() ? "E":lcs(x,y) );
}

/*提示 LCS 不用連續
關係 lcs(a,b) = case 1: lcs ∋ a[-1]&&b[-1]→a[-1]==b[-1] → lcs(a,b)=lcs(a[0:-1],b[0,-1])+a[-1]
case 2: lcs ∌ a[-1] || b[-1] → max(lcs(a[-1],b),lcs(a,b[-1]))*/