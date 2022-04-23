#include <bits/stdc++.h>
using namespace std;
int n,m,rate;

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

void modify(int ind,int k,vector<pair<int,int> > &segtree){
    if(ind<0) return;
    int realind = ind + nextPowerOf2(n);
    segtree[realind] = make_pair(k,ind);
    while(realind!=1){
        realind>>=1;
        segtree[realind]  = max(segtree[2*realind],segtree[2*realind+1]);
    }
}
pair<int,int> query(int l,int r, vector<pair<int,int> > &segtree){
    pair<int,int> res = make_pair(0,-1);
    l+=nextPowerOf2(n);
    r+=nextPowerOf2(n);
    while( l<r) {
    if (l%2){
        res = max(res,segtree[l]);
        l++;   
    }
    if ((r%2)){
        res = max(res,segtree[r-1]);
        r--;   
    } 
    l = l>>1;
    r = r>>1;
  }
  return res;    

}

int main(){
    cin>>n>>m>>rate;
    vector<pair<int,int> > spells(n);
    for(int i=0;i<n;i++){
        int p,c;cin>>p>>c;
        spells[i]=make_pair(p,c);
    }
    sort(spells.begin(),spells.end());
    vector<pair<int,int> > segtree(2*nextPowerOf2(n),make_pair(0,-1));
    for(int i=0;i<n;i++){
        modify(i,spells[i].second,segtree);
    }
    long long time=0;
    long long DamPerSec = 0;
    long long health = m;
    pair<int,int> maxinrange = make_pair(0,-1);
    while(!(time>n && DamPerSec<=(long long) rate && maxinrange.first<=0 )){
        health-=DamPerSec;
        health+=rate;
        health = min(health,(long long)m);
        if(health<=0) break;
        //Binary search for r
        int r=n;int l=-1;
        while(r-l>1){
            int mid = l+((r-l)>>1);
            if((long long)spells[mid].first*m >= (long long)health*100){
                r=mid;
            }else{
                l=mid;
            }
        }
        // in range [r,n-1] find the spells with the largest damage that hasn't been chosen yet
        maxinrange = query(r,n,segtree);
        DamPerSec += maxinrange.first;
        modify(maxinrange.second,0,segtree);
        //advance time
        ++time;
    }
    if((time>n && DamPerSec<=(long long) rate && maxinrange.first<=0 )){
        cout<<-1<<endl;
    } else{
        cout<<time<<endl;
    }
}