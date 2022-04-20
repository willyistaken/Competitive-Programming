#include <bits/stdc++.h>
using namespace std;
int n,m,r;

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

void modify(int ind,int k,pair<int,int>* segtree){
    int realloc = ind+nextPowerOf2(n);
    segtree[realloc] = make_pair(k,ind);
    while(realloc!=1){
        realloc/=2;
        segtree[realloc]=max(segtree[realloc*2],segtree[(realloc*2)+1]);
    }

}
pair<int,int> query(int ind,int l,int r,int ql,int qr, pair<int,int>* segtree){
    
    if(qr<ql || r<l) return make_pair(INT_MIN,-1);
    if(r<ql||l>qr) return make_pair(INT_MIN,-1);
    if(l>=ql && r<=qr) return segtree[ind];
    if(qr==ql) return segtree[r+nextPowerOf2(n)];
    int mid = (l+r)/2;
    return max(query(ind*2,l,mid,ql,qr,segtree),query(ind*2+1,mid+1,r,ql,qr,segtree));
}

int main(){
    cin>>n>>m>>r;
    vector<pair<int,int> > spells(n);
    for(int i=0;i<n;i++){
        int p,c;cin>>p>>c;
        spells[i]=make_pair(p,c);
    }
    sort(spells.begin(),spells.end());
    pair<int,int> segtree[2*nextPowerOf2(n)]={make_pair(0,-1)};
    for(int i=0;i<n;i++){
        modify(i,spells[i].second, segtree );
    }
    long long i=0;
    long long health=m;
    long long cdamage=0;
    while(!(i>n && cdamage<=r)){
        health-=cdamage;
        health+=r;
        health=min(health,(long long) m);
        //binary search for h
        int l=-1;int r=n;
        while(r-l>1){
            int mid=(r+l)/2;
            if((double)spells[mid].first>=(double)(health*100.0)/(double)m){
                r=mid;
            }else{
                l=mid;
            }
        }
        // binary search for h ----code-is-trash---code-is-trash---- 
        if(health<=0) break;
        i++;
        if(r>=n) continue;
        pair<int,int> temp=query(1,0,n-1,r,n-1,segtree);
        
        if((temp.first!=-1)){
            cdamage+=temp.first;
            modify(temp.second,-1,segtree);
        }       
       
    }
    if((i>n && cdamage<=r)){
        cout<<-1<<endl;
    }else{
        cout<<i<<endl;
    }



}