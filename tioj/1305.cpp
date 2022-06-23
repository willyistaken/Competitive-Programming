#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

void add(int i,vector<int> &segtree,int v){
    i+=n;
    if(v>0) segtree[i]=1;
    else segtree[i]=0;
    i>>=1;
    while(i){
        segtree[i] = segtree[2*i]+segtree[2*i+1]; 
        i>>=1;
    }
    return ;
}

int query(int r,int k,vector<int> &segtree){
    if(segtree[r]<k) return -1;
    if(r>=n) return r-n;
    if(segtree[2*r]<k) return query(2*r+1,k-segtree[2*r],segtree);
    else return query(2*r,k,segtree);
}

inline int np2(int _n){
    _n--;
    _n |= _n>>1;
    _n |= _n>>2;
    _n |= _n>>4;
    _n |= _n>>8;
    _n |= _n>>16;
    return _n+1;
}

int main(){
    string s;
    set<int> dis;
    queue<pair<char,int> > command;
    while(cin>>s){
        int k;
        if(s[0]!='e') cin>>k;
       command.push({s[0],k});
       if(s[0]=='i'){
           dis.insert(k);
       }
       if(s[0]=='r'){
           dis.insert(k);
       }     
       if(s[0]=='e'){
           break;
       }
    }
    map<int,int> mp;
    vector<int> amp;
    for(auto i:dis){
        mp.insert({i,mp.size()});
        amp.push_back(i);
    }
    n = dis.size();
    n = np2(n);
    vector<int> segtree(2*n,0);    
    while(!command.empty()){
        pair<int,int> temp = command.front();
        command.pop();
        if(temp.first=='i'){
            add(mp[temp.second],segtree,1);
        }
        if(temp.first=='r'){
           if(segtree[mp[temp.second]+n]>0){
                add(mp[temp.second],segtree,-1);
            }
        }
        if(temp.first=='a'){
            if(temp.second<1){
                cout<<"error\n";
                continue;
            }
            if(query(1,temp.second,segtree)<0){
                cout<<"error\n";
            }else{
                cout<<amp[query(1,temp.second,segtree)]<<endl;
            }
        }
    }

  




    return 0;
}

//k 有可能是<1