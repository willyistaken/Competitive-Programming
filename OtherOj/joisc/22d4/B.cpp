#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include<bits/extc++.h>
//__gnu_pbds

vector<ll> A;
struct SegTree {
    vector<pair<int,int> > arr;
    vector<int> tag;
    int n;
    void built(int ind,int L,int R) {
        arr[ind].second = (R-L+1);
        if(L==R) return;
        int M = (L+R)/2;
        built(2*ind,L,M);
        built(2*ind+1,M+1,R);
    }
    void init(int _n) {
        n =_n;
        arr.resize(4*n);
        tag.resize(4*n);
        built(1,1,n);
    }
    void push(int ind) {
        if(2*ind+1>4*n) return;
        if(tag[ind]) {
            arr[2*ind].first+=tag[ind];
            arr[2*ind+1].first+=tag[ind];
            tag[2*ind]+=tag[ind];
            tag[2*ind+1]+=tag[ind];
            tag[ind]=0;
        }
    }
    inline pair<int,int> merge(const pair<int,int> a,const pair<int,int> b) {
        if(a.first!=b.first) return min(a,b);
        return {a.first,a.second+b.second};
    }
    pair<int,int> query(int ind,int l,int r,int L,int R) {
        if(r<l) return {0,0};
        if(l==L && r==R) {
            return arr[ind];
        }
        push(ind);
        int M = (L+R)/2;
        if(r<=M) return query(2*ind,l,r,L,M);
        if(l>M) return query(2*ind+1,l,r,M+1,R);
        return merge(query(2*ind,l,M,L,M),query(2*ind+1,M+1,r,M+1,R));
    }
    void modify(int ind,int l,int r,int L,int R,int v) {
        //cout<<l<<" "<<r<<"~"<<L<<" "<<R<<"safd"<<endl;
        if(l==L && r==R) {
            arr[ind].first+=v;
            tag[ind]+=v;
            return ;
        }
        push(ind);
        int M = (L+R)/2;
        if(r<=M) modify(2*ind,l,r,L,M,v);
        else if(l>M) modify(2*ind+1,l,r,M+1,R,v);
        else {
            modify(2*ind,l,M,L,M,v);
            modify(2*ind+1,M+1,r,M+1,R,v);
        }
        arr[ind] = merge(arr[2*ind],arr[2*ind+1]);
    }

} segtree;

struct range {
    int l,r;
    range(int _l,int _r) {
        l = _l;
        r = _r;
    }
    bool operator<(const range &rhs) const {
        return (r-l)<(rhs.r-rhs.l);
    }
};
struct IntTree {
    vector<priority_queue<range> > arr;
    int n;
    void init(int _n) {
        n = _n;
        arr.resize(4*n);
    }
    void insert(range a,int ind,int L,int R) {
        int M = (L+R)/2;
        if(a.l<=M && a.r>=M) {
            //cout<<"insert "<<a.l<<" "<<a.r<<"->"<<ind<<"\n";
            arr[ind].push(a);
            segtree.modify(1,a.l,a.r,1,n,1);
            return;
        }
        if(a.r<=M) insert(a,2*ind,L,M);
        else insert(a,2*ind+1,M+1,R);
    }
    void remove(int x,int ind,int L,int R) {
        while(arr[ind].size()) {
            range cur = arr[ind].top();
            if(cur.l<=x && cur.r>=x) {
                segtree.modify(1,cur.l,cur.r,1,n,-1);
                arr[ind].pop();
            } else {
                break;
            }
        }
        int M = (L+R)/2;
        if(x==M) return;
        if(x<M) remove(x,2*ind,L,M);
        if(x>M) remove(x,2*ind+1,M+1,R);
    }
    void out(int ind,int L,int R) {
        auto pq = arr[ind];
        while(pq.size()) {
//			cout<<pq.top().l<<" "<<pq.top().r<<"->"<<ind<<"k\n";
            pq.pop();
        }
        if(L==R) return;
        int M = (L+R)/2;
        out(2*ind,L,M);
        out(2*ind+1,M+1,R);
    }
} inttree;

struct SegTree2 {
    vector< pair<ll,ll> > arr;
    // a[i]+A[i]>A[x]
    // 2*a[i]-A[i]>-A[x-1]
    vector<ll> tag;
    int n;
    void init(int _n) {
        n = _n;
        arr.resize(4*n);
        tag.resize(4*n);
    }
    void apply(int ind,ll v) {
        arr[ind].first+=v;
        arr[ind].second-=v;
        tag[ind]+=v;
    }
    void push(int ind) {
        if(2*ind+1>=4*n) return;
        if(tag[ind]) {
            apply(2*ind,tag[ind]);
            apply(2*ind+1,tag[ind]);
            tag[ind]=0;
        }
    }
    ll sum(int ind,int x,int L,int R) {
        if(L==R && L==x) {
            return arr[ind].first-A[x];
        }
        push(ind);
        int M = (L+R)/2;
        if(x<=M) return sum(2*ind,x,L,M);
        if(x>M) return sum(2*ind+1,x,M+1,R);
        assert(1==0);
        return 0;
    }
    void smodify(int ind,int x,int L,int R,ll v) {
        if(L==x && R==x) {
            arr[ind].first+=v;
            arr[ind].second+=2*v;
            return;
        }
        push(ind);
        int M = (L+R)/2;
        if(x<=M) smodify(2*ind,x,L,M,v);
        if(x>M) smodify(2*ind+1,x,M+1,R,v);
        arr[ind] = {max(arr[2*ind].first,arr[2*ind+1].first),max(arr[2*ind].second,arr[2*ind+1].second)};
    }
    void rmodify(int ind,int l,int r,int L,int R,ll v) {
        if(l==L && r==R) {
            apply(ind,v);
            return;
        }
        push(ind);
        int M = (L+R)/2;
        if(r<=M) rmodify(2*ind,l,r,L,M,v);
        else if(l>M)  rmodify(2*ind+1,l,r,M+1,R,v);
        else {
            rmodify(2*ind,l,M,L,M,v);
            rmodify(2*ind+1,M+1,r,M+1,R,v);
        }
        arr[ind] = {max(arr[2*ind].first,arr[2*ind+1].first),max(arr[2*ind].second,arr[2*ind+1].second)};
    }

    void update(int ind,ll v) {
        ll k = v-A[ind];
        smodify(1,ind,1,n,k);
        rmodify(1,ind,n,1,n,k);
        A[ind]=v;
    }
    void getr(int ind,ll v,int x,int L,int R,vector<pair<int,ll> > &ret) {
        if(R<x) return;
        if(arr[ind].second<=v) return;
        if(L==R) {
            ret.push_back({L,arr[ind].second});
            return;
        }
        push(ind);
        int M =(L+R)/2;
        getr(2*ind,v,x,L,M,ret);
        getr(2*ind+1,v,x,M+1,R,ret);
    }
    void getl(int ind,ll v,int x,int L,int R,vector<pair<int,ll> > &ret) {
        if(L>x)	 return;
        if(arr[ind].first<=v) return;
        if(L==R) {
            ret.push_back({L,arr[ind].first});
            return;
        }
        push(ind);
        int M = (L+R)/2;
        getl(2*ind,v,x,L,M,ret);
        getl(2*ind+1,v,x,M+1,R,ret);
    }
} segtree2;

int n;
void MainUpdate(int ind,ll v) {
    inttree.remove(ind,1,1,n);
    inttree.remove(ind-1,1,1,n);
    inttree.remove(ind+1,1,1,n);
    segtree2.update(ind,v);
    vector<pair<int,ll> > rcan;
    vector<pair<int,ll> > lcan;
    ll Ax = segtree2.sum(1,ind,1,n);
    segtree2.getr(1,-(Ax),ind,1,n,rcan);
    segtree2.getl(1,Ax-A[ind],ind,1,n,lcan);
    // a[i]+A[i]>A[x-1]
    // 2*a[i]-A[i]>-A[x]
    for(auto pr : rcan) {
        for(auto pl : lcan) {
            if(pr.first-1<pl.first+1) continue;
            ll sumbet = (A[pr.first]-pr.second)-(pl.second-A[pl.first]);
            if(A[pr.first]>sumbet && A[pl.first]>sumbet) {
                //if(ind==4) cout<<pl.first<<" "<<pr.first<<"gg\n";
                inttree.insert(range(pl.first+1,pr.first-1),1,1,n);
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    n+=2;
    segtree.init(n);
    inttree.init(n);
    segtree2.init(n);
    A.resize(n+1);
    inttree.insert(range(2,n-1),1,1,n);
    segtree2.update(1,1e16);
    segtree2.update(n,1e16);
    for(int i=2; i<n; i++) {
        ll v;
        cin>>v;
        MainUpdate(i,v);
    }
    int q;
    cin>>q;
    while(q--) {
        int t;
        cin>>t;
        if(t==1) {
            int x,y;
            cin>>x>>y;
            x++;
//			cout<<"t\n";
            MainUpdate(x,y);
        } else {
            int l,r;
            cin>>l>>r;
            l++;
            r++;
            int rl = l;
            int rr = r;

            vector<pair<int,ll> > rcan;
            ll Ax = segtree2.sum(1,l,1,n);
            segtree2.getr(1,-(Ax-A[l]),l,1,n,rcan);
            for(auto i : rcan) if(i.first<=r) rl = max(rl,i.first);

            vector<pair<int,ll> > lcan;
            Ax = segtree2.sum(1,r,1,n);
            segtree2.getl(1,Ax,r,1,n,lcan);
            for(auto i : lcan) if(i.first>=l) rr = min(rr,i.first);
            pair<int,int> ans = segtree.query(1,rl,rr,1,n);
            cout<<ans.second<<"\n";
        }
    }
    return 0;
}
/*
8
8 6 1 4 1 1 4 4
3
1 3 6
2 3 8
2 1 5
*/
