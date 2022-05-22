#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const MOD = (int)(1007729);
int const prime = 31;
int hsh(string a){
    ll sum=a[0]-'a';
    for(int i=0;i<a.size();i++){
      sum=(1LL*sum*prime)%MOD;
      sum+=a[i]-'a';  
      sum = (sum>MOD) ? sum-MOD : sum;
    }
    return sum;
}
int main(){
    string t;
    string b;
    cin>>t>>b;
    int hs = hsh(t);
   int primetop =1;
    for(int i=0;i<t.size();i++){
        primetop=(1LL*primetop*prime)%MOD;
    }
    int bhsh[b.size()+1];
    bhsh[0]=0;
    for(int i=1;i<b.size()+1;i++){
        bhsh[i]=(1LL*bhsh[i-1]*prime)%MOD;
        bhsh[i]+=b[i-1]-'a';
        bhsh[i] = (bhsh[i]>MOD) ? bhsh[i]-MOD : bhsh[i]; 
    }  
    queue<int> ans;
    cout<<hs<<"this"<<endl;
    for(int i=0;i<=b.size()-t.size();i++){
        int check = bhsh[i+t.size()];
        check -= (1LL*bhsh[i]*primetop)%MOD;
        check = check%MOD;
        if(check<0) check+=MOD;
        if(check==hs){     
            ans.push(i);
        }
        cout<<check<<" at "<<i<<endl;
    }
    while(!ans.empty()){
        cout<<ans.front();
        if(ans.size()!=1) cout<<" ";
        ans.pop();
    }
    cout<<endl;
 


    return 0;
}