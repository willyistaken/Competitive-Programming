#include <bits/stdc++.h>
using namespace std;
int n;
int ceilpowerof2(int n) 
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
void modify(int ind,int k,vector<pair<int,int> > &segtree){
    int realind = ind+ceilpowerof2(n);
    segtree[realind]=make_pair(k,ind);
    while(realind!=1){
        realind/=2;
        segtree[realind]=min(segtree[realind*2],segtree[realind*2+1]);
    }
}
pair<int,int> query(int cur,int l,int r,int ql,int qr,vector<pair<int,int> > &segtree){
    if(l>r || ql>qr) return make_pair(INT_MAX,-1);
    if(l>qr || r<ql) return make_pair(INT_MAX,-1);
    if(l==r) return segtree[l+ceilpowerof2(n)];
    if(l>=ql && r<=qr ) return segtree[cur];
    int mid=(l+r)/2;
    return min(query(2*cur,l,mid,ql,qr,segtree),query(2*cur+1,mid+1,r,ql,qr,segtree));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int arr[n];
    long long prefixsum[n+1]={0}; 
    vector<pair<int,int>> segtree(2*ceilpowerof2(n),make_pair(INT_MAX,0)) ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        modify(i,arr[i],segtree);
        prefixsum[i+1]=prefixsum[i]+arr[i];
    }
   int l=0;
   int r=n-1;
   while(r-l>0){
       pair<int,int> temp = query(1,0,ceilpowerof2(n)-1,l,r,segtree);
       if(temp.second==r){
           r=temp.second-1;
           continue;
       } 
       if(temp.second==l){
           l=temp.second+1;
           continue;
       }
       if(prefixsum[temp.second]-prefixsum[l]>prefixsum[r+1]-prefixsum[temp.second+1]){
           r=temp.second-1;
       }else{
           l=temp.second+1;
       }
   }
   cout<<arr[l]<<endl;
}