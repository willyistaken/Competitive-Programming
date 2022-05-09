#include <bits/stdc++.h>
using namespace std;

//input: n(the size of the array) follow by n interger (stuff in the array)
vector<int> arr;
int n;

int nextPowerOf2(int n) 
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
void modify(int ind,int k,vector<int> &segtree){
    int realind = ind+nextPowerOf2(n);
    segtree[realind]=k;
    while(realind!=1){
        realind/=2;
        segtree[realind] = max(segtree[realind*2],segtree[realind*2+1]);
    }
}
int query(int cur,int l,int r,int ql,int qr,vector<int> &segtree){
    if(ql>qr || l>r) return INT_MIN;
    if(r<ql || l>qr) return INT_MIN;
    if(l>=ql && r<=qr) return segtree[cur];
    if(r==l) return segtree[l+nextPowerOf2(n)];
    int mid = (l+r)>>1;
    return max(query(cur*2,l,mid,ql,qr,segtree),query(cur*2+1,mid+1,r,ql,qr,segtree));
}
void travel(int i,vector<int> &segtree){
    if(i>=2*nextPowerOf2(n)) return;
    cout<<segtree[i]<<endl;
    travel(2*i,segtree);
    travel(2*i+1,segtree);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        arr.push_back(temp);
    }
    vector<int> segtree(2*nextPowerOf2(n),-1);
    
    for(int i=0;i<n;i++){
        modify(i,arr[i],segtree);
    }
    for(int i=0;i<5;i++){
        cout<<query(1,0,nextPowerOf2(n)-1,0,i,segtree)<<endl;
    }


}
//無遞迴版
