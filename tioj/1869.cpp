//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1050;
struct bit{
    int arr[N+1]={0};
    void change(int ind,int v){
        while(ind<=N){
            arr[ind]+=v;
            ind+=(ind & - ind);
        }
    }
    int query(int ind){
        int sum=0;
        while(ind>0){
            sum+=arr[ind];
            ind-=(ind & -ind);
        }
        return sum;
    }
    void print(){
        for(int i=1;i<=N;i++){
            cout<<arr[i]<<" ";
        }
    }
};
struct BIT{
    bit arr[N+1];
    void change(int x,int y,int v){
        while(y<=N){    
            arr[y].change(x,v);
            y+=(y & -y);
        }
    }
    int query(int x,int y){
        int sum=0;
        while(y>0){
            sum+=arr[y].query(x);
            y-=(y & -y);
        }
        return sum;
    }
    void print(){
        for(int i=1;i<=N;i++){
        arr[i].print();
        cout<<endl;
        }
    }
};
int main(){
   // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int t;
    BIT b;
    while(cin>>t){
        if(t==1){
            int x,y,z;cin>>x>>y>>z;
            b.change(x+1,y+1,z);
        
        }else{
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            x1+=1;y1+=1;x2+=1;y2+=1;
            cout<<b.query(x2,y2)-b.query(x1-1,y2)-b.query(x2,y1-1)+b.query(x1-1,y1-1)<<endl;
            //cout<<b.query(x2,y1)<<" "<<b.query(x1,y2)<<" "<<b.query(x2,y1)<<" "<<b.query(x1,y1)<<endl;
        }
    } 
/*     for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            cout<<(b.arr[i]).arr[j]<<" ";
        }
        cout<<endl;
    } */





    return 0;
}