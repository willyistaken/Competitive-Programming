#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct fdc{
    char v[5];
    int t;
};
inline int hsh(fdc a){
    int ans=a.v[0];
    for(int i=1;i<5;i++){
        ans=ans*51 + a.v[i];
    }
    return ans;
}
int maxv[5];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    cin>>maxv[0];
    int maxn= maxv[0];
    int h = maxv[0];
    for(int i=1;i<n;i++){
       cin>>maxv[i];
       h = __gcd(h,maxv[i]);
       maxn = max(maxn,maxv[i]);
    }
    int target;cin>>target;
    if(target>maxn || target%h!=0){
        cout<<-1<<endl;
        return 0;
    }
    unordered_set<int> done;
    queue<fdc> bfs;
    bfs.push({0,0,0,0,0,0}) ;
    done.insert(hsh({0,0,0,0,0,0})) ;  
    while(!bfs.empty()){
        fdc temp = bfs.front();
        bfs.pop();
        for(int i=0;i<5;i++){
            if(temp.v[i]==target){
                cout<<temp.t<<endl;
                return 0;
            }
        }
        //empty element
        for(int i=0;i<5;i++){
            fdc modi = temp;
            modi.v[i]=0;
            if(!done.count(hsh(modi))){
                done.insert(hsh(modi));
                modi.t +=1;
                bfs.push(modi);
            }
        }
        // fill element
        for(int i=0;i<5;i++){
            fdc modi = temp;
            modi.v[i]=maxv[i];
            if(!done.count(hsh(modi))){
                done.insert(hsh(modi));
                modi.t +=1;
                bfs.push(modi);
            }
        }
        // pour f→o
        for(int f=0;f<5;f++){
            for(int o=0;o<5;o++){
                if(f!=o){
                    fdc modi = temp;
                    if(temp.v[f]+temp.v[o]>maxv[o]){
                        modi.v[o]=maxv[o];
                        modi.v[f]=temp.v[f]-(maxv[o]-temp.v[o]);
                    }else{
                        modi.v[o]+=modi.v[f];
                        modi.v[f]=0;
                    }
                    if(!done.count(hsh(modi))){
                        done.insert(hsh(modi));
                        modi.t+=1;
                        bfs.push(modi);
                    }
                }
            }
        }

    }
    cout<<"what happen?\n";


    return 0;
}