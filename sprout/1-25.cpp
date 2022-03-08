#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    bitset<105> donthave;
    list<int> whole[n+1];
    for(int i=0;i<m;i++){
        string c;cin>>c;
        if(c[0]=='A'){
            int store,people;cin>>store>>people;
            whole[store].push_back(people);
        }
        if(c[0]=='L'){
            int store;cin>>store;
            if(whole[store].empty()){
                cout<<"queue "<<store<<" is empty!\n";
            }else{
                whole[store].pop_front();
            }
        }
        if(c[0]=='J'){
           
            int from,to;cin>>from>>to; 
            whole[to].insert(whole[to].end(),whole[from].begin(),whole[from].end());
            whole[from].erase(whole[from].begin(),whole[from].end());
        }
    }

    for(int i=1;i<=n;i++){
        cout<<"queue "<<i<<":";
        if(whole[i].empty() ){
            cout<<" empty\n";
        }else{
            while(!whole[i].empty()){
            cout<<" "<<whole[i].front();
            whole[i].pop_front();
        }
        cout<<endl;
        }
        
    }
}